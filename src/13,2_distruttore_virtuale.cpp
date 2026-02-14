// 13,2_distruttore_virtuale.cpp
// PERCHÉ IL DISTRUTTORE DEVE ESSERE VIRTUAL?

#include <iostream>

/*
    REGOLA D'ORO DEL C++:
    Se una classe ha anche solo UNA funzione virtuale, deve avere un
    distruttore virtuale.

    PERCHÉ?
    Quando elimini un oggetto derivato tramite un puntatore alla classe base,
    se il distruttore base NON è virtuale, il distruttore derivato NON viene chiamato.
    Risultato: MEMORY LEAK.
*/

// --- CASO SBAGLIATO ---
class BaseErrata
{
public:
    BaseErrata() { std::cout << "BaseErrata creata\n"; }
    // Manca 'virtual' qui!
    ~BaseErrata() { std::cout << "BaseErrata distrutta\n"; }
};

class DerivataErrata : public BaseErrata
{
    int *array_gigante;

public:
    DerivataErrata()
    {
        array_gigante = new int[1000]; // Allocazione risorsa
        std::cout << "DerivataErrata creata (risorse allocate)\n";
    }
    ~DerivataErrata()
    {
        delete[] array_gigante; // Pulizia risorsa
        std::cout << "DerivataErrata distrutta (risorse liberate)\n";
    }
};

// --- CASO CORRETTO ---
class BaseCorretta
{
public:
    BaseCorretta() { std::cout << "BaseCorretta creata\n"; }

    // VIRTUAL: assicura che venga chiamato prima il distruttore del figlio
    virtual ~BaseCorretta() { std::cout << "BaseCorretta distrutta\n"; }
};

class DerivataCorretta : public BaseCorretta
{
    int *array_gigante;

public:
    DerivataCorretta()
    {
        array_gigante = new int[1000];
        std::cout << "DerivataCorretta creata\n";
    }
    ~DerivataCorretta() override
    {
        delete[] array_gigante;
        std::cout << "DerivataCorretta distrutta\n";
    }
};

int main()
{
    std::cout << "=== SCENARIO 1: DISASTRO (Senza Virtual Destructor) ===\n";
    BaseErrata *p1 = new DerivataErrata();
    // Qui cancelliamo tramite puntatore Base.
    // Il compilatore vede ~BaseErrata() non virtuale e chiama SOLO quello.
    // ~DerivataErrata() NON viene chiamato -> MEMORY LEAK di array_gigante!
    delete p1;

    std::cout << "\n=== SCENARIO 2: CORRETTO (Con Virtual Destructor) ===\n";
    BaseCorretta *p2 = new DerivataCorretta();
    // Qui delete p2 guarda la vtable, vede che il distruttore è virtuale,
    // chiama ~DerivataCorretta() PRIMA, e poi ~BaseCorretta().
    delete p2;

    return 0;
}
