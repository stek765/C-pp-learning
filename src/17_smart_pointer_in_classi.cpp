// 17_smart_pointer_in_classi.cpp
// SMART POINTER IN CLASSI

#include <iostream>
#include <memory>
using namespace std;

class Persona {
    string nome;
    unique_ptr<int> eta; // Gestione automatica della memoria
public:
    Persona(string n, int e) : nome(n), eta(make_unique<int>(e)) {}
    void info() {
        cout << "Nome: " << nome << ", Età: " << *eta << endl;
    }
};

int main() {
    Persona p("Mario", 30);
    p.info();
    // La memoria di eta viene gestita automaticamente!
    return 0;
}
