// 23_thread.cpp
// THREAD - Multithreading base in C++

#include <iostream>
#include <thread> // Libreria per gestire i thread
using namespace std;

/*
Un thread è un "flusso di esecuzione" separato: permette di eseguire più cose in parallelo.
In C++ moderno si usa la classe std::thread per creare e gestire thread.

Sintassi base:
thread nome(funzione); // Avvia un nuovo thread che esegue la funzione
nome.join();           // Aspetta che il thread finisca

Attenzione: se non chiami join(), il programma può terminare prima che il thread abbia finito!
*/

// Funzione che verrà eseguita dal thread
void stampa() {
    cout << "Ciao dal thread!" << endl;
}

int main() {
    // Avvia un thread che esegue la funzione stampa
    thread t(stampa); // Il thread parte subito

    // join() blocca il main finché il thread non ha finito
    t.join();         // Aspetta che il thread finisca

    cout << "Main finito" << endl;
    return 0;
}
