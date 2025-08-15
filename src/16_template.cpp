// 16_template.cpp
// TEMPLATE - Funzioni e classi generiche

#include <iostream>
using namespace std;

// Un template permette di scrivere funzioni e classi che funzionano con qualsiasi tipo
// Sintassi: template<typename T> ...
// T è un "segnaposto" per il tipo che userai (int, double, ecc.)
template<typename T>
T somma(T a, T b) {
    return a + b; // Funziona con qualsiasi tipo che supporta +
}

int main() {
    // Chiamata con int
    cout << "Somma int: " << somma(3, 5) << endl;      // 8
    // Chiamata con double
    cout << "Somma double: " << somma(2.5, 4.1) << endl;  // 6.6
    // Chiamata con string
    cout << "Somma string: " << somma(string("Ciao "), string("mondo")) << endl; // Ciao mondo
    // Puoi usare somma con qualsiasi tipo che abbia l'operatore +
    return 0;
}

/*
Perché usare i template?
- Scrivi una sola funzione/classe che funziona con tanti tipi diversi
- Eviti duplicazione di codice
- Tipico per funzioni matematiche, container, algoritmi

Esempio di template di classe:
template<typename T>
class Box {
public:
    T valore;
    Box(T v) : valore(v) {}
};
Box<int> b1(10);
Box<string> b2("ciao");
*/
