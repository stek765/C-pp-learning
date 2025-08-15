// 25_moduli.cpp
// MODULI E NAMESPACE - Organizzazione codice in C++

#include <iostream>
using namespace std;

/*
Un namespace è solo un "contenitore" per funzioni, variabili o classi.
Serve per organizzare il codice e evitare conflitti di nomi.
Non crea oggetti, non ha dati propri.

Esempio di namespace:
namespace util {
    void saluta() { cout << "Ciao da util!" << endl; }
}
// Per usare la funzione: util::saluta();

Una classe invece è un modello per creare oggetti, con dati e metodi.
Esempio di classe:
class Persona {
public:
    void saluta() { cout << "Ciao da Persona!" << endl; }
};
// Per usare la funzione: Persona p; p.saluta();

Quindi:
- Namespace = organizzazione, nessun oggetto
- Classe = oggetto con dati e metodi
*/


// Esempio pratico: più namespace con funzioni saluta
namespace persona {
    void saluta() { cout << "Ciao, sono una persona!" << endl; }
}

namespace animale {
    void saluta() { cout << "Bau! Sono un cane!" << endl; }
}

namespace robot {
    void saluta() { cout << "010101! Sono un robot!" << endl; }
}

int main() {
    // Chiamata di funzione tramite namespace
    persona::saluta(); // Stampa: Ciao, sono una persona!
    animale::saluta(); // Stampa: Bau! Sono un cane!
    robot::saluta();   // Stampa: 010101! Sono un robot!

    // Se avessi scritto solo saluta(), il compilatore non saprebbe quale usare!

    return 0;
}
