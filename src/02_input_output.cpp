// 02_input_output.cpp
// INPUT E OUTPUT - Comunicare con l'utente

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    // VARIABILI PER INPUT
    string nome;
    string nomecompleto;
    int eta;
    float altezza;
    char iniziale;
    
    // OUTPUT - Chiedere informazioni
    cout << "=== RACCOLTA DATI UTENTE ===" << endl;
    cout << "Come ti chiami? ";
    
    // INPUT - Ricevere dati
    cin >> nome;  // cin = "console in" - legge dalla tastiera
    
    cout << "Quanti anni hai? ";
    cin >> eta;
    
    cout << "Quanto sei alto (in metri)? ";
    cin >> altezza;
    
    cout << "Qual è l'iniziale del tuo cognome? ";
    cin >> iniziale;
    
    // OUTPUT FORMATTATO
    cout << "\n=== I TUOI DATI ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Età: " << eta << " anni" << endl;
    cout << "Altezza: " << altezza << " metri" << endl;
    cout << "Iniziale: " << iniziale << endl;

    // PROBLEMA SPAZI: cin >> lascia '\n' nel buffer, se uso getline lo legge subito!
    cout << "\n--- PROBLEMA SPAZI ---" << endl;
    cout << "Inserisci il tuo nome completo: ";

    cin.ignore();           // Rimuove il '\n' rimasto da cin >> iniziale

    getline(cin, nomecompleto);     // Legge tutta la riga, spazi inclusi
    cout << "Nome completo: " << nomecompleto << endl;
    
    // CONCATENAZIONE STRINGHE
    string saluto = "Ciao " + nome + "!";
    cout << saluto << endl;
    
    return 0;
}

/*
DIFFERENZE INPUT:
- cin >> variabile: legge fino al primo spazio o newline
- getline(cin, variabile): legge tutta la riga inclusi gli spazi
- cin.ignore(): pulisce il buffer di input

OPERATORI DI STREAM:
- << : inserimento (output)
- >> : estrazione (input)

ESCAPE SEQUENCES:
- \n : newline (a capo)
- \t : tab
- \" : virgolette
- \\ : backslash

DETTAGLIO BUFFER DI INPUT:

Il buffer è una "coda" di caratteri in attesa di essere letti:

Scenario SENZA cin.ignore():
1. cin >> eta;           → Buffer dopo: "\n"
2. getline(cin, nome);   → Legge subito "\n" → nome = ""

Scenario CON cin.ignore():
1. cin >> eta;           → Buffer dopo: "\n"
2. cin.ignore();         → Buffer dopo: "" (vuoto)
3. getline(cin, nome);   → Aspetta nuovo input → nome = "Mario Rossi"


REGOLA D'ORO:
Usa sempre cin.ignore() prima di getline() se hai usato cin >> prima!
*/
