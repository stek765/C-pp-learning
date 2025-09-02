// 01.5_const.cpp
// In Cpp ci sono 2 strade per la immutability:
// - const       (viene valutato a tempo di esecuzione)
// - constexpr   (viene valutato a tempo di compilazione)

#include <iostream>
using namespace std;

// Funzione constexpr per calcolare il quadrato
constexpr double square(double x) {
    return x * x;
}

int main(int argc, char const *argv[])
{
    const int x = 10;          // valore costante
    constexpr double dmv = 3.0;           // esempio di valore
    constexpr double max1 = 1.3 * square(dmv);  // OK se square(dmv) è una constant expression, altrimenti error

    // x = 15;                 // errore: non si può modificare una costante
    // y = 25;                 // errore: non si può modificare una costante


    return 0;
}

// Quando usare uno o l'altro:
// - const: quando il valore è noto solo a tempo di esecuzione
// - constexpr: quando il valore è noto a tempo di compilazione