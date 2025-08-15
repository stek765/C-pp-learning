// 22_move_semantics.cpp
// MOVE SEMANTICS - Ottimizzazione prestazioni

#include <iostream>
#include <vector>
using namespace std;

/*
Le move semantics permettono di "spostare" risorse invece di copiarle.
Sono fondamentali per ottimizzare le prestazioni quando lavori con oggetti pesanti (es. vector, string).

std::move non copia i dati, ma trasferisce la proprietà delle risorse:
- L'oggetto sorgente (es. a) viene svuotato
- L'oggetto destinazione (es. b) riceve i dati

Utile per evitare copie inutili e rendere il codice più veloce!
*/

int main() {
    vector<int> a = {1,2,3}; // a contiene 1,2,3
    // Sposta i dati da a a b: dopo questa riga, a è vuoto e b contiene i dati
    vector<int> b = std::move(a); // move = trasferimento risorse, non copia

    cout << "b: ";
    for (int x : b) cout << x << " "; // b ha i dati
    cout << "\na: ";
    for (int x : a) cout << x << " "; // a ora è vuoto (size=0)
    cout << endl;

    // Nota: dopo la move, non usare più l'oggetto sorgente se ti serve ancora!

    return 0;
}
