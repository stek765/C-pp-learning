// 13_ereditarieta.cpp
// EREDITARIETÀ E POLIMORFISMO - Spiegazione semplice

#include <iostream>
using namespace std;

// Una classe base è un "modello generico"
class Animale {
public:
    // Il metodo parla è virtuale: permette il vero polimorfismo cioè
    // la possibilità di chiamare metodi derivati attraverso puntatori/base
    virtual void parla() {
        cout << "Suono generico" << endl;
    }
};

// Una classe derivata eredita tutto dalla base
class Cane : public Animale {
public:
    // Override: ridefinisco il metodo parla
    void parla() override {
        cout << "Bau!" << endl;
    }
};

class Gatto : public Animale {
public:
    void parla() override {
        cout << "Miao!" << endl;
    }
};

int main() {
    Animale a;   // Oggetto base
    Cane c;      // Oggetto derivato
    Gatto g;     // Altro derivato

    a.parla();   // Suono generico
    c.parla();   // Bau!
    g.parla();   // Miao!

    // Polimorfismo: uso puntatore base per oggetti diversi
    Animale* ptr;
    ptr = &c;
    ptr->parla(); // Bau! (grazie a virtual)
    ptr = &g;
    ptr->parla(); // Miao!

    // se non ci fosse virtual, verrebbe chiamato il metodo della classe base

    // Array di puntatori base
    Animale* zoo[3] = {&a, &c, &g};
    cout << "\nTutti gli animali parlano:" << endl;
    for (int i = 0; i < 3; i++) {
        zoo[i]->parla(); // Ogni animale fa il suo verso
    }
    return 0;
}

/*
Ereditarietà: permette di creare classi "specializzate" partendo da una base.
Polimorfismo: permette di trattare oggetti diversi in modo uniforme, ma con comportamenti specifici.
virtual/override: servono per far sì che il metodo giusto venga chiamato anche usando puntatori/base.
*/
