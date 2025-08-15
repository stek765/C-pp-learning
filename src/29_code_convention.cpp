// 29_code_convention.cpp
// CODE CONVENTION - Stile, naming e best practice

#include <iostream>
using namespace std;

/*
Best practice per scrivere codice C++ chiaro e mantenibile:
- Usa nomi di variabili e funzioni descrittivi (es: sommaTotale, calcolaMedia)
- Segui uno stile coerente (indentazione, spazi, parentesi)
- Costanti in MAIUSCOLO: const int MAX_SIZE = 100;
- Funzioni e variabili in camelCase o snake_case
- Commenta il codice dove serve, ma non esagerare
- Raggruppa il codice in moduli e file separati
- Evita variabili globali
- Preferisci const e reference dove possibile
- Usa RAII e smart pointer per la gestione della memoria
- Scrivi funzioni brevi e con uno scopo chiaro
*/

// Esempio di stile e naming
class Rettangolo {
    int larghezza;
    int altezza;
public:
    Rettangolo(int l, int a) : larghezza(l), altezza(a) {}
    int calcolaArea() const { return larghezza * altezza; }
};

int main() {
    Rettangolo r(10, 5);
    cout << "Area: " << r.calcolaArea() << endl;
    return 0;
}
