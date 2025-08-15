// 26_pattern.cpp
// DESIGN PATTERN - Esempio Singleton

#include <iostream>
using namespace std;

/*
Il pattern Singleton serve per avere UNA SOLA istanza di una classe in tutto il programma.
Utile quando vuoi che una risorsa sia condivisa e unica (es: configurazione, logger, connessione DB).

Come funziona:
- Il costruttore è privato, quindi non puoi creare oggetti con "new" o direttamente.
- L'unico modo per ottenere l'oggetto è chiamare getInstance(), che restituisce sempre la stessa istanza.
- static Singleton instance; garantisce che l'oggetto venga creato solo la prima volta.
*/

class Singleton {
private:
    Singleton() {
        // inserisco per esempio un logger
        cout << "Logger inizializzato" << endl;
    }
public:
    // Restituisce sempre la stessa istanza
    static Singleton &getInstance() {
        static Singleton instance; // Oggetto statico, creato solo la prima volta
        return instance;
    }
    void saluta() { cout << "Sono il Singleton!" << endl; }
};

int main() {
    // Ottieni l'unica istanza del Singleton
    Singleton &s = Singleton::getInstance();
    s.saluta(); // Chiamata al metodo

    // Se provi a creare un altro oggetto, il compilatore dà errore:
    // Singleton x; // ERRORE: costruttore privato

    return 0;
}
