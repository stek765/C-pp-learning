// 13,1_virtual_polimorfismo.cpp
// VIRTUAL E POLIMORFISMO: COME IL C++ SCEGLIE QUALE FUNZIONE CHIAMARE

#include <iostream>
#include <vector>
#include <memory>

// Regola Naming: Classi con Maiuscola
class Guerriero
{
public:
    // SENZA virtual: il compilatore decide a TEMPO DI COMPILAZIONE (Early Binding).
    // Guarda solo il TIPO della variabile (Guerriero*), non cosa c'è dentro davvero.
    void attacca_statico()
    {
        std::cout << "Guerriero: Attacco generico (frecce o spada? boh)" << std::endl;
    }

    // CON virtual: il compilatore decide a TEMPO DI ESECUZIONE (Late Binding).
    // Guarda l'oggetto reale in memoria (V-Table lookup).
    virtual void attacca_dinamico()
    {
        std::cout << "Guerriero: Attacco base" << std::endl;
    }
};

class Arciere : public Guerriero
{
public:
    void attacca_statico()
    {
        std::cout << "Arciere: Scocco una freccia!" << std::endl;
    }

    // 'override' è opzionale ma FORTEMENTE raccomandato in C++11+.
    // Se sbagli a scrivere il nome della funzione base, il compilatore ti dà errore.
    void attacca_dinamico() override
    {
        std::cout << "Arciere: Tiro mirato!" << std::endl;
    }
};

class Mago : public Guerriero
{
public:
    // 'final': impedisce a chi eredita da Mago di fare override di questa funzione.
    void attacca_dinamico() override final
    {
        std::cout << "Mago: Palla di fuoco!" << std::endl;
    }
};

/*
class Negromante : public Mago {
    // Errore: non puoi fare override di una funzione 'final'
    // void attacca_dinamico() override { ... }
};
*/

int main()
{
    std::cout << "--- STATIC BINDING (SENZA VIRTUAL) ---" << std::endl;
    Arciere legolas;
    Guerriero *ptr_g = &legolas;

    // Chiama Guerriero::attacca_statico() perché ptr_g è di tipo Guerriero*
    // Il compilatore ignora che in realtà punta a un Arciere.
    ptr_g->attacca_statico();

    std::cout << "\n--- DYNAMIC BINDING (CON VIRTUAL) ---" << std::endl;
    // Chiama Arciere::attacca_dinamico() perché la funzione è virtuale.
    // A runtime verifica il tipo reale dell'oggetto.
    ptr_g->attacca_dinamico();

    std::cout << "\n--- ESEMPIO REALE: VETTORE POLIMORFICO ---" << std::endl;
    // Posso trattare tutti come "Guerrieri", ma ognuno si comporta come deve.
    std::vector<std::unique_ptr<Guerriero>> party;

    party.push_back(std::make_unique<Arciere>());
    party.push_back(std::make_unique<Mago>());
    party.push_back(std::make_unique<Guerriero>());

    for (const auto &membro : party)
    {
        membro->attacca_dinamico(); // Magia del polimorfismo
    }

    return 0;
}
