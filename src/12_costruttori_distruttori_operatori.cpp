// 12_costruttori_distruttori_operatori.cpp
// COSTRUTTORI, DISTRUTTORI E OPERATORI

#include <iostream>
using namespace std;

class Punto {
    int x, y;
public:
    // Costruttore
    Punto(int x_, int y_) : x(x_), y(y_) {
        cout << "Costruttore chiamato!" << endl;
    }
    // Distruttore
    ~Punto() {
        cout << "Distruttore chiamato!" << endl;
    }
    // Operatore di assegnazione
    Punto& operator=(const Punto& other) {
        cout << "operator= chiamato!" << endl;
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    // Operatore di output
    friend ostream& operator<<(ostream& os, const Punto& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Punto a(1,2);
    Punto b(3,4);
    b = a; // operator=
    cout << "a: " << a << endl; // operator<<
    cout << "b: " << b << endl;
    return 0;
}
