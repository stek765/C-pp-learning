# C++ Professionale BEST-PRACTICE

> Ispirato da "Clean Code", "Effective C++", "The Pragmatic Programmer" e adattato al C++ Low-Level/Embedded.

Il problema nel mondo reale non è far funzionare un ciclo, ma garantire manutenibilità. 
**Domanda chiave:** *"Tra 6 mesi, quando dovremo aggiungere una feature, vorremo spararci o saremo in grado di farlo in un'ora?"*

---

## 1. La Regola d'Oro: "Il Codice è per gli Umani, non per le Macchine"
*(Ispirazione: Clean Code)*

Un compilatore ignora i nomi delle variabili, il tuo collega no.

### Nomi Parlanti (Naming Convention)
| Bad ⛔ | Good ✅ | Perché? |
| :--- | :--- | :--- |
| `int t;` | `uint32_t motor_timeout_ms;` | So il tipo, lo scopo e l'unità di misura. |
| `void check();` | `bool is_sensor_calibrated();` | È una domanda, mi aspetto true/false come ritorno. |

### Il Commento è un Fallimento (quasi sempre)
Se devi scrivere un commento per spiegare *cosa* fa il codice, il codice è scritto male. Refactorizza il codice per essere auto-esplicativo.

**Bad:**
```cpp
// Controlla se la temperatura è sopra 100
if (t > 100) { ... }
```

**Good:**
```cpp
if (is_overheating()) { ... }
```

**Eccezione Low-Level:**
Nell'embedded i commenti servono per spiegare il **PERCHÉ** di hack strani.
*Es: "Aspetto 5ms perché il datasheet del sensore dice che serve tempo per il reset".*

---

## 2. Organizzazione Fisica: La Legge di Lakos
*(Ispirazione: Large-Scale C++ Software Design)*

In C++, sbagliare le dipendenze significa tempi di compilazione esplosivi e incubi di linking.

### Un Classe = Due File
1.  **`Circuit.h`** (L'interfaccia: *cosa* fa).
2.  **`Circuit.cpp`** (L'implementazione: *come* lo fa).
*Non mettere mai codice di implementazione nel .h (a meno che non sia un template).*

### Struttura delle Cartelle (Project Layout)
Non buttare tutto nella root. Un progetto serio si presenta così:

```text
/project_root
├── /src           // I file .cpp (Implementazione)
├── /include       // I file .h (Interfaccia pubblica)
├── /tests         // Unit test (googletest / catch2)
├── /docs          // Documentazione
├── /libs          // Librerie esterne
└── CMakeLists.txt // Il file che dice come costruire il progetto
```

### Include Guards & Forward Declaration
Questa è una di quelle cose che separa chi "scrive codice che compila" da chi "gestisce progetti grandi".

#### 1. Include Guards (`#pragma once`)

**Il Problema: L'Inclusione Multipla**
Senza protezioni, se includi lo stesso file header più volte (anche indirettamente, es. `Gararage.h` che include `Motore.h` e `Auto.h` che include `Motore.h`), il compilatore vedrà definizioni duplicate e darà errore ("Redefinition of class...").

**La Soluzione: Include Guard**
È un trucco per dire al compilatore: *"Se hai già letto questo file, ignoralo"*.

**Modo Moderno (Consigliato):**
```cpp
// Motore.h
#pragma once

class Motore { ... };
```

#### 2. Forward Declaration (Il segreto dei tempi di compilazione)

**Il Problema: L'effetto valanga**
Se in `Auto.h` fai `#include "Guidatore.h"`, ogni volta che modifichi `Guidatore.h`, devi ricompilare anche tutti i file che usano `Auto.h`. In progetti grandi, questo trasforma i tempi di build da minuti a ore.

**La Soluzione: Forward Declaration**
Se usi solo un puntatore o un riferimento a una classe nel file `.h`, al compilatore non serve sapere la dimensione esatta o i metodi della classe. Gli basta sapere che *esiste*.

**Esempio Pratico:**

```cpp
// Auto.h
#pragma once

class Guidatore; // <--- FORWARD DECLARATION (Promessa: "Esiste, fidati")

class Auto {
public:
    void assegnaAutista(Guidatore* g); // Uso solo il puntatore, il compilatore è felice.
private:
    Guidatore* m_autista;
};
```
*L'include vero (`#include "Guidatore.h"`) lo metti solo nel file `.cpp`.*

**Tabella decisionale rapida:**

| Situazione | Azione | Sintassi |
| :--- | :--- | :--- |
| Membro puntatore (`T*`) | **Forward Decl.** | `class A; A* ptr;` |
| Membro riferimento (`T&`) | **Forward Decl.** | `class A; A& ref;` |
| Parametro funzione | **Forward Decl.** | `void func(A a);` |
| Membro per valore | **#include** | `#include "A.h" ... A obj;` |
| Ereditarietà | **#include** | `#include "A.h" ... class B : public A` |

---

## 3. La Filosofia RAII e la Sicurezza
*(Ispirazione: Effective Modern C++)*

Cosa distingue un programmatore C++ Senior da uno C.

### Mai `new` e `delete` nudi
Usa `std::unique_ptr` o `std::shared_ptr` o `auto var = std::make_unique`. Il codice deve pulirsi da solo. Se vedi una `delete` nel codice moderno, è una "code smell".

### Const Correctness (La regola del "Non Toccare")
Se una funzione non deve modificare i dati, **DEVI** marcarla `const`.

```cpp
void print_info() const { ... } 
// Se provo a cambiare una variabile qui, il compilatore mi blocca.
```
Questo comunica al team: *"Fidati di questa funzione, è sicura, legge solo".*

---

## 4. Architettura Low-Level: SOLID & HAL
*(Ispirazione: Design Patterns per Embedded)*

Come scrivere codice che gira su un STM32 oggi e su un ESP32 domani?

### HAL (Hardware Abstraction Layer)
Non scrivere mai registri hardware (es. `GPIOA->ODR = 0x1`) dentro la logica di business.

Crea un'interfaccia astratta:
```cpp
class IDigitalOutput {
public:
    virtual void turn_on() = 0;
    virtual void turn_off() = 0;
    virtual ~IDigitalOutput() = default; // Distruttore virtuale sempre!
};
```
Poi crea `STM32Led` che eredita da quella. Il tuo codice userà `IDigitalOutput`, indipendentemente dall'hardware sottostante.

### Single Responsibility Principle (SRP)
Una classe non deve fare tutto.
*   `Circuito`: Gestisce la logica dei fili.
*   `CircuitoPrinter`: Sa come stampare un circuito a video.
*   `CircuitoStorage`: Sa come salvare un circuito su file.

Se cambi il formato di stampa, non rischi di rompere la logica del circuito.

---

## 5. Il Workflow nel Team
*(Ispirazione: The Pragmatic Programmer)*

### Style Guide Automatica
Non litigare su "dove va la parentesi graffa". Usa **Clang-Format**. È un file (`.clang-format`) nel progetto che formatta automaticamente il codice al salvataggio.

### Code Review
Nessun codice entra nel "main" senza che qualcun altro lo abbia letto (4 occhi vedono meglio di 2).
Cosa cercare:
*   Nomi poco chiari.
*   Funzioni troppo lunghe (se > 20-30 righe, spezzala!).
*   Mancanza di gestione errori.

---
