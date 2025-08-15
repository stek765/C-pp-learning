// 11_classi_oggetti.cpp
// CLASSI E OGGETTI - Fondamenti OOP

#include <iostream>
using namespace std;

// Una classe è un "modello" per creare oggetti
class Persona {
public:
    string nome; // attributo
    int eta;     // attributo

    // Costruttore: crea e inizializza l'oggetto
    // In C++ la lista di inizializzazione (dopo i due punti) è il modo migliore per inizializzare gli attributi.
    // Perché? È più efficiente, obbligatoria per costanti/riferimenti, e inizializza subito i valori.
    // Qui: nome(n) prende il valore n, eta(e) prende il valore e, PRIMA che entri nel corpo del costruttore.
    // Questo evita errori, doppie assegnazioni e rende il codice più sicuro e moderno.
    Persona(string n, int e) : nome(n), eta(e) {} // Usa SEMPRE la lista di inizializzazione!

    // Metodo: funzione che agisce sull'oggetto
    void saluta() {
        cout << "Ciao, sono " << nome << " e ho " << eta << " anni." << endl;
    }
};

int main() {
    // Creo un oggetto Persona
    Persona p("Mario", 30);
    p.saluta(); // Chiamo un metodo
    p.eta++;    // Modifico un attributo
    cout << "Nuova età: " << p.eta << endl;
    return 0;
}

// ===================
// PUBLIC vs PRIVATE
// ===================
// In C++ puoi decidere chi può accedere ai dati e ai metodi della classe:
// - public: accessibile da fuori (tutti possono usarlo)
// - private: accessibile solo dentro la classe (protegge i dati)
//
// Esempio pratico:
//
// class Persona {
// public:
//     string nome; // tutti possono leggerlo/scriverlo
// private:
//     int eta;     // solo la classe può modificarlo
// };
//
// Di solito si mettono i dati "sensibili" come private e si usano metodi public per modificarli.
// Questo rende il codice più sicuro e controllato!
