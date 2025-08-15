
// 19_eccezioni.cpp
// ECCEZIONI - Gestione degli errori in C++

#include <iostream>
using namespace std;

/*
Le eccezioni permettono di gestire gli errori in modo elegante e sicuro.
Invece di far "crashare" il programma, puoi intercettare e gestire l'errore.

try { ... }  // Prova a eseguire il codice
throw ...;   // Lancia un'eccezione (errore)
catch (...)  // Gestisce l'eccezione
*/

int main() {
    try {
        cout << "Provo a dividere per zero..." << endl;
        int a = 10, b = 0;
        // Se b è zero, lancio un'eccezione (errore) che verrà gestita nel catch
        if (b == 0) throw runtime_error("Divisione per zero!");
        // Se non c'è errore, eseguo la divisione
        cout << a / b << endl;
    } catch (const exception& e) { // il & indica che e è un riferimento costante di tipo exception
        // Questo blocco gestisce l'errore
        cout << "Errore: " << e.what() << endl;
    }

    // Puoi creare eccezioni personalizzate:
    // class MioErrore : public exception { ... };

    // Puoi anche gestire più tipi di errori dopo il try:
    // catch (const runtime_error& e) { ... }
    // catch (const out_of_range& e) { ... }

    // Le eccezioni rendono il codice più robusto e leggibile!
    return 0;
}
