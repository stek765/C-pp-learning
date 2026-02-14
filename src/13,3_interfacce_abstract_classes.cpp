// 13,3_interfacce_abstract_classes.cpp
// INTERFACCE E CLASSI ASTRATTE
// Come creare contratti software solidi

#include <iostream>
#include <vector>
#include <string>

/*
    CLASSE ASTRATTA (Abstract Class):
    Una classe che ha almeno una "funzione virtuale pura" (= 0).
    Non puoi istanziarla direttamente (es. 'Forma f;' è errore).
    Serve come modello per altre classi.

    INTERFACCIA (Interface):
    In C++ non esiste la keyword 'interface' (come in Java/C#).
    Un'interfaccia è una classe astratta che ha SOLO metodi virtuali puri
    e nessun dato membro (variabili).
*/

// DEFINIZIONE DI INTERFACCIA
// Chiunque erediti da IDrawable DEVE saper disegnare se stesso.
class IDrawable
{
public:
    // virtual puro (= 0). Obbliga i figli a implementarlo.
    virtual void draw() const = 0;

    // Distruttore virtuale obbligatorio per le interfacce!
    virtual ~IDrawable() = default;
};

// Altra interfaccia per chi può essere salvato su file
class ISerializable
{
public:
    virtual std::string serialize() const = 0;
    virtual ~ISerializable() = default;
};

// --- IMPLEMENTAZIONI CONCRETE ---

// Cerchio deve rispettare il contratto IDrawable
class Cerchio : public IDrawable
{
public:
    void draw() const override
    {
        std::cout << "O" << std::endl;
    }
};

// Quadrato implementa DUE interfacce (Ereditarietà Multipla di Interfacce)
// In C++ l'ereditarietà multipla è pericolosa, ma con le interfacce pure è sicura e comune.
class Quadrato : public IDrawable, public ISerializable
{
public:
    void draw() const override
    {
        std::cout << "[]" << std::endl;
    }

    std::string serialize() const override
    {
        return "Shape:Square;Color:Red";
    }
};

// Funzione che accetta QUALSIASI cosa sia disegnabile.
// Non gli importa se è un Cerchio o un Quadrato, basta che sia un IDrawable.
// Questo è il principio di Dependency Inversion (SOLID).
void render_screen(const std::vector<IDrawable *> &objects)
{
    std::cout << "Rendering screen..." << std::endl;
    for (const auto &obj : objects)
    {
        obj->draw();
    }
}

int main()
{
    // IDrawable x; // ERRORE: Non puoi istanziare una classe astratta

    Cerchio c;
    Quadrato q;

    // Polimorfismo tramite interfaccia
    std::vector<IDrawable *> oggetti;
    oggetti.push_back(&c);
    oggetti.push_back(&q);

    render_screen(oggetti);

    // Esempio con l'altra interfaccia
    std::cout << "\nSalvataggio dati:" << std::endl;
    // std::cout << c.serialize(); // ERRORE: Cerchio non è ISerializable
    std::cout << q.serialize() << std::endl; // OK

    return 0;
}
