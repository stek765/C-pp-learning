# 📚 C++ Learning Journey

> 🚧 **Work in Progress** - Sto imparando C++ step by step!

Questa repository contiene il mio percorso di apprendimento del C++, dal livello base ai concetti più avanzati.

## 📋 Indice dei File

| File | Argomento | Status |
|------|-----------|--------|
| `00_hello_world.cpp` | Primo programma, print, compilazione | ✅ |
| `01_variabili_tipi.cpp` | Variabili, tipi di dato, sizeof | ✅ |
| `02_input_output.cpp` | cin, cout, getline, buffer | ✅ |
| `03_operatori.cpp` | Operatori aritmetici, logici, confronto | ✅ |
| `04_condizioni_if.cpp` | if, else, else if, operatore ternario | ✅ |
| `05_switch_case.cpp` | switch-case, fall-through | ✅ |
| `06_cicli_while_for.cpp` | while, do-while, for, break, continue | ✅ |
| `07_array_vettori.cpp` | Array, matrici, ricerca | ✅ |
| `08_funzioni.cpp` | Funzioni, parametri, overloading | ✅ |
| `09_stringhe.cpp` | std::string, metodi, conversioni | ✅ |
| `10_puntatori_riferimenti.cpp` | Puntatori, riferimenti, memoria | ✅ |
| `11_classi_oggetti.cpp` | Classi, oggetti, costruttori | 🔄 TODO |
| `12_ereditarieta.cpp` | Ereditarietà, polimorfismo | 📝 TODO |
| `13_template.cpp` | Template, generics | 📝 TODO |
| `14_stl_containers.cpp` | STL, vector, map, set | 📝 TODO |

## 🚀 Come Compilare ed Eseguire

```bash
# Compilazione
g++ nome_file.cpp -o eseguibile

# Esecuzione  
./eseguibile

# Esempio:
g++ 00_hello_world.cpp -o hello
./hello
```

## 🚀 Compilazione automatica con Makefile

Per compilare tutti i file C++ in modo automatico e ordinato:

```bash
make
```

Gli eseguibili verranno creati nella cartella `bin/`.
Per pulire la cartella degli eseguibili:

```bash
make clean
```

## 📦 Struttura della repository

- Tutti i sorgenti C++ sono in `src/`
- Gli eseguibili sono in `bin/`
- Materiale avanzato e PDF in `Corso Avanzato Federico Busato/`

## 🛠️ Dipendenze

- Compilatore C++ (g++ consigliato)
- Make (per la compilazione automatica)

## 📖 Struttura dei File

Ogni file contiene:
- **Commenti dettagliati** per ogni concetto
- **Esempi pratici** funzionanti
- **Sezione teorica** alla fine con riassunto
- **Codice progressivo** dal semplice al complesso

## 🎯 Obiettivi di Apprendimento

## 📚 Riferimenti

- [Corso Avanzato Federico Busato](./Corso%20Avanzato%20Federico%20Busato/)
- [Documentazione C++ ufficiale](https://cppreference.com/)
- [Modern C++ Guidelines](https://isocpp.github.io/CppCoreGuidelines/)

