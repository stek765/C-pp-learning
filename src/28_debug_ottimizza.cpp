// 28_debug_ottimizza.cpp
// DEBUGGING E OTTIMIZZAZIONE in C++

#include <iostream>
using namespace std;

/*
DEBUGGING:
- Serve per trovare e correggere errori nel codice.
- Puoi usare:
    - cout/cerr per stampare variabili e messaggi
    - debugger (gdb, lldb, debugger IDE) per eseguire il codice passo-passo
    - breakpoints per fermare l'esecuzione in punti precisi

Esempio:
int x = 5;
cout << "x vale: " << x << endl; // stampa il valore per controllare

OTTIMIZZAZIONE:
- Serve per rendere il programma più veloce e leggero.
- Consigli:
    - Usa algoritmi efficienti (es: cerca, ordina, filtra)
    - Evita copie inutili di dati (usa riferimenti, move semantics)
    - Misura i tempi di esecuzione se serve (profiling)
*/

int main() {
        // Debug: stampa messaggi per controllare il flusso e i valori
        cout << "Debug: usa cout, debugger, breakpoints" << endl;

        // Ottimizzazione: scegli algoritmi e tecniche efficienti
        cout << "Ottimizza: usa algoritmi efficienti, evita copie inutili" << endl;

        // Esempio pratico di debug
        int x = 42;
        cout << "Valore di x: " << x << endl; // controllo valore

        // Esempio pratico di ottimizzazione
        // Evita copie: usa riferimento
        int a = 10;
        int& ref = a; // nessuna copia, solo alias
        ref += 5;
        cout << "a ottimizzato: " << a << endl;

        return 0;
}
