// 05_switch_case.cpp
// SWITCH-CASE - Alternative a catene di if-else

#include <iostream>
using namespace std;

int main() {
    cout << "=== SWITCH BASE ===" << endl;
    
    int giorno = 3;
    
    switch (giorno) {
        case 1:
            cout << "Lunedì" << endl;
            break;  // IMPORTANTE: senza break continua al prossimo case!
        case 2:
            cout << "Martedì" << endl;
            break;
        case 3:
            cout << "Mercoledì" << endl;
            break;
        case 4:
            cout << "Giovedì" << endl;
            break;
        case 5:
            cout << "Venerdì" << endl;
            break;
        case 6:
            cout << "Sabato" << endl;
            break;
        case 7:
            cout << "Domenica" << endl;
            break;
        default:  // Opzionale: caso di default
            cout << "Giorno non valido!" << endl;
    }
    
    cout << "\n=== SWITCH CON CHAR ===" << endl;
    
    char voto = 'B';
    
    switch (voto) {
        case 'A':
            cout << "Eccellente!" << endl;
            break;
        case 'B':
            cout << "Molto buono!" << endl;
            break;
        case 'C':
            cout << "Buono" << endl;
            break;
        case 'D':
            cout << "Sufficiente" << endl;
            break;
        case 'F':
            cout << "Insufficiente" << endl;
            break;
        default:
            cout << "Voto non riconosciuto" << endl;
    }
    
    cout << "\n=== SWITCH SENZA BREAK (fall-through) ===" << endl;
    
    int mese = 2;
    
    switch (mese) {
        case 12:
        case 1:
        case 2:
            cout << "Inverno" << endl;
            break;
        case 3:
        case 4:
        case 5:
            cout << "Primavera" << endl;
            break;
        case 6:
        case 7:
        case 8:
            cout << "Estate" << endl;
            break;
        case 9:
        case 10:
        case 11:
            cout << "Autunno" << endl;
            break;
        default:
            cout << "Mese non valido" << endl;
    }
    
    cout << "\n=== SWITCH CON AZIONI MULTIPLE ===" << endl;
    
    char operatore = '*';
    int x = 6, y = 4;
    
    switch (operatore) {
        case '+':
            cout << x << " + " << y << " = " << (x + y) << endl;
            break;
        case '-':
            cout << x << " - " << y << " = " << (x - y) << endl;
            break;
        case '*':
            cout << x << " * " << y << " = " << (x * y) << endl;
            break;
        case '/':
            if (y != 0) {
                cout << x << " / " << y << " = " << (x / y) << endl;
            } else {
                cout << "Errore: divisione per zero!" << endl;
            }
            break;
        default:
            cout << "Operatore non supportato: " << operatore << endl;
    }
    
    cout << "\n=== ESEMPIO: MENU INTERATTIVO ===" << endl;
    
    cout << "MENU:" << endl;
    cout << "1. Visualizza saldo" << endl;
    cout << "2. Deposita denaro" << endl;
    cout << "3. Preleva denaro" << endl;
    cout << "4. Esci" << endl;
    cout << "Scelta: ";
    
    int scelta = 2;  // Simuliamo la scelta dell'utente
    cout << scelta << endl;  // Mostriamo la scelta simulata
    
    float saldo = 1000.50;
    
    switch (scelta) {
        case 1:
            cout << "Il tuo saldo è: " << saldo << " euro" << endl;
            break;
        case 2: {
            // Blocco {} per dichiarare variabili locali
            float deposito = 250.0;
            saldo += deposito;
            cout << "Depositati " << deposito << " euro." << endl;
            cout << "Nuovo saldo: " << saldo << " euro" << endl;
            break;
        }
        case 3: {
            float prelievo = 100.0;
            if (prelievo <= saldo) {
                saldo -= prelievo;
                cout << "Prelevati " << prelievo << " euro." << endl;
                cout << "Saldo rimanente: " << saldo << " euro" << endl;
            } else {
                cout << "Saldo insufficiente!" << endl;
            }
            break;
        }
        case 4:
            cout << "Arrivederci!" << endl;
            break;
        default:
            cout << "Scelta non valida!" << endl;
    }
    
/*
FALL-THROUGH:
- Senza break, continua al case successivo
- Utile per raggruppare casi simili
- Può essere fonte di bug se dimenticato!
*/
