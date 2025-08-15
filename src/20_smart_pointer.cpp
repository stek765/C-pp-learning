
// 20_smart_pointer.cpp
// SMART POINTER - Gestione automatica della memoria in C++ moderno

#include <iostream>
#include <memory> // Libreria per smart pointer
using namespace std;

/*
Gli smart pointer gestiscono la memoria automaticamente:
- Evitano memory leak (dimenticare delete)
- Rendono il codice più sicuro e semplice

Tipi principali:
unique_ptr   // possiede un solo oggetto, non si può copiare, si distrugge automaticamente quando esce dallo scope
shared_ptr   // più puntatori possono condividere lo stesso oggetto
weak_ptr     // puntatore "debole", non possiede l'oggetto, serve per evitare cicli
*/

int main() {
    // unique_ptr: possiede un solo oggetto, si distrugge automaticamente
    unique_ptr<int> p = make_unique<int>(42); // crea e gestisce un int
    cout << "Valore: " << *p << endl;

    // shared_ptr: più puntatori possono condividere lo stesso oggetto (avviene un conteggio degli shared_ptr)
    shared_ptr<int> p2 = make_shared<int>(100); // crea e gestisce un int
    shared_ptr<int> p3 = p2; // p2 e p3 condividono lo stesso int
    cout << "Valore condiviso: " << *p3 << endl;

    // weak_ptr: puntatore "debole", non aumenta il conteggio dei riferimenti
    weak_ptr<int> wp = p2; // serve per controllare se l'oggetto esiste ancora
    cout << "Ancora valido? " << !wp.expired() << endl;

    // Esempio pratico sul conteggio dei riferimenti:
    shared_ptr<int> p1 = make_shared<int>(2); // reference count = 1
    shared_ptr<int> p2 = p1;                  // reference count = 2 (p1 e p2 condividono lo stesso oggetto)
    *p1 = 42; // Cambia il valore puntato, ma il conteggio non cambia
    // Se ora scrivi: p1 = make_shared<int>(99); // p1 ora punta a un nuovo oggetto, il vecchio reference count diminuisce
    // Il vecchio oggetto ora ha reference count = 1 (solo p2 lo punta)
    // Il nuovo oggetto ha reference count = 1 (solo p1 lo punta)
    // Se scrivi: p2 = nullptr; // reference count del vecchio oggetto va a 0, viene eliminato

    // "Sovrascritto" significa che assegni un nuovo valore al puntatore, es:
    // p1 = make_shared<int>(99); // p1 ora punta a un nuovo oggetto, il vecchio oggetto perde un riferimento

    // Quando tutti i shared_ptr sono distrutti (cioè escono dallo scope, vengono assegnati a nullptr, o sovrascritti),
    // il conteggio dei riferimenti arriva a zero e l'oggetto viene eliminato automaticamente.
    // Non serve mai chiamare delete!
    return 0;
}
