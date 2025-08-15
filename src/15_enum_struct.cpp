// 15_enum_struct.cpp
// ENUM E STRUCT

#include <iostream>
using namespace std;

// Enum: insieme di costanti con nome
enum Colore { Rosso, Verde, Blu };

// Struct: raggruppa variabili sotto un unico nome
struct Punto {
    int x;
    int y;
};

int main() {
    Colore c = Verde;
    if (c == Verde) cout << "Il colore è verde!" << endl;

    Punto p;
    p.x = 10;
    p.y = 20;
    cout << "Punto: (" << p.x << ", " << p.y << ")" << endl;
    return 0;
}
