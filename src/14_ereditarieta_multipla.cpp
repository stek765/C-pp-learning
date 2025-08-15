// 14_ereditarieta_multipla.cpp
// EREDITARIETÀ MULTIPLA

#include <iostream>
using namespace std;

class Base1 {
public:
    void saluta() { cout << "Ciao da Base1!" << endl; }
};

class Base2 {
public:
    void parla() { cout << "Parlo da Base2!" << endl; }
};

class Derivata : public Base1, public Base2 {
public:
    void info() { cout << "Sono la classe derivata!" << endl; }
};

int main() {
    Derivata d;
    d.saluta(); // metodo di Base1
    d.parla();  // metodo di Base2
    d.info();   // metodo proprio
    return 0;
}
