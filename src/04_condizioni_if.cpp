// 04_condizioni_if.cpp
// STRUTTURE CONDIZIONALI - Prendere decisioni

#include <iostream>
using namespace std;

int main() {
    cout << "=== IF SEMPLICE ===" << endl;
    
    int numero = 10;
    
    // IF SEMPLICE
    if (numero > 5) {
        cout << numero << " è maggiore di 5" << endl;
    }
    
    cout << "\n=== IF-ELSE ===" << endl;
    
    int eta = 17;
    
    if (eta >= 18) {
        cout << "Sei maggiorenne!" << endl;
    } else {
        cout << "Sei minorenne!" << endl;
    }
    
    cout << "\n=== IF-ELSE IF-ELSE (catena) ===" << endl;
    
    int voto = 28;
    
    if (voto >= 30) {
        cout << "Eccellente! Lode!" << endl;
    } else if (voto >= 27) {
        cout << "Ottimo!" << endl;
    } else if (voto >= 24) {
        cout << "Buono!" << endl;
    } else if (voto >= 18) {
        cout << "Sufficiente." << endl;
    } else {
        cout << "Insufficiente." << endl;
    }
    
    cout << "\n=== CONDIZIONI MULTIPLE ===" << endl;
    
    int temperatura = 25;
    bool piove = false;
    
    // AND logico
    if (temperatura > 20 && !piove) {
        cout << "Bella giornata per uscire!" << endl;
    }
    
    // OR logico
    if (temperatura < 0 || temperatura > 35) {
        cout << "Temperatura estrema!" << endl;
    }
    
    cout << "\n=== CONDIZIONI ANNIDATE ===" << endl;
    
    char tipo = 'S';  // S = Studente, L = Lavoratore
    int anni = 22;
    
    if (tipo == 'S') {  // Se è studente
        if (anni < 25) {
            cout << "Studente giovane - Sconto 20%" << endl;
        } else {
            cout << "Studente - Sconto 10%" << endl;
        }
    } else if (tipo == 'L') {  // Se è lavoratore
        if (anni > 65) {
            cout << "Pensionato - Sconto 15%" << endl;
        } else {
            cout << "Lavoratore - Prezzo pieno" << endl;
        }
    }
    
    cout << "\n=== OPERATORE TERNARIO ===" << endl;
    
    int a = 8, b = 12;
    
    // Forma compatta di if-else
    int maggiore = (a > b) ? a : b;  // se a>b allora a, altrimenti b
    cout << "Il maggiore tra " << a << " e " << b << " è " << maggiore << endl;
    
    // Equivale a:
    int maggiore2;
    if (a > b) {
        maggiore2 = a;
    } else {
        maggiore2 = b;
    }
    
    cout << "\n=== ESEMPI PRATICI ===" << endl;
    
    
    // Controllo password
    string password = "ciao123";
    
    if (password.length() < 6) {
        cout << "Password troppo corta!" << endl;
    } else if (password == "password" || password == "123456") {
        cout << "Password troppo comune!" << endl;
    } else {
        cout << "Password accettata." << endl;
    }
    
    return 0;
}
