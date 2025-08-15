// 21_lambda.cpp
// LAMBDA - Funzioni anonime e moderne

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Le lambda sono funzioni anonime, cioè senza nome, che puoi scrivere direttamente dove ti servono.
Sono utili per:
- passare funzioni come parametri (es. agli algoritmi STL)
- scrivere codice compatto e leggibile
- manipolare collezioni (vector, map, ecc)

Sintassi base:
[] (parametri) { corpo }
Le parentesi quadre [] servono per la "cattura" delle variabili locali.
Puoi catturare per valore [x], per riferimento [&x], o tutto [=] / [&].
*/

int main() {
    vector<int> v = {1, 2, 3, 4};

    // Lambda: funzione anonima che stampa ogni elemento
    auto stampa = [](int x) { cout << x << " "; };
    for_each(v.begin(), v.end(), stampa); // Passa la lambda come funzione
    cout << endl;

    // Lambda inline: somma tutti gli elementi del vettore
    int somma = 0;
    for_each(v.begin(), v.end(), [&](int x) { somma += x; }); // Cattura somma per riferimento
    cout << "Somma: " << somma << endl;

    // Esempio di lambda con cattura per valore
    int moltiplicatore = 2;
    for_each(v.begin(), v.end(), [moltiplicatore](int x) { cout << x * moltiplicatore << " "; });
    cout << " <-- elementi moltiplicati per 2" << endl;

    // Lambda come predicato: conta i pari
    int pari = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    cout << "Numeri pari: " << pari << endl;

    // Puoi anche usare lambda per ordinare, filtrare, ecc.

    return 0;
}
