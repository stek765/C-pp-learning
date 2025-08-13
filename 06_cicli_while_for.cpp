// 06_cicli_while_for.cpp
// CICLI - Ripetere operazioni

#include <iostream>
using namespace std;

int main() {
    cout << "=== CICLO WHILE ===" << endl;
    
    // WHILE: ripete FINCHÉ la condizione è vera
    int contatore = 1;
    
    while (contatore <= 5) {
        cout << "Iterazione " << contatore << endl;
        contatore++;  // IMPORTANTE: aggiorna la variabile!
    }
    
    cout << "\n=== CICLO DO-WHILE ===" << endl;
    
    // DO-WHILE: esegue ALMENO UNA VOLTA, poi controlla
    int numero;
    
    do {
        cout << "Inserisci un numero positivo: ";
        numero = 8;  // Simuliamo l'input
        cout << numero << endl;
        
        if (numero <= 0) {
            cout << "Errore! Il numero deve essere positivo." << endl;
        }
    } while (numero <= 0);
    
    cout << "Numero valido inserito: " << numero << endl;
    
    cout << "\n=== CICLO FOR ===" << endl;
    
    // FOR: più compatto per contatori
    // for (inizializzazione; condizione; aggiornamento)
    for (int i = 1; i <= 5; i++) {
        cout << "FOR - Iterazione " << i << endl;
    }
    
    cout << "\n=== FOR CON DIVERSI INCREMENTI ===" << endl;
    
    // Incremento di 2
    for (int i = 0; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    
    // Decremento
    for (int i = 10; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "\n=== CICLI ANNIDATI ===" << endl;
    
    // Tabellina delle moltiplicazioni
    cout << "Tabellina 3x3:" << endl;
    for (int riga = 1; riga <= 3; riga++) {
        for (int colonna = 1; colonna <= 3; colonna++) {
            cout << (riga * colonna) << "\t";  // \t = tab
        }
        cout << endl;  // A capo dopo ogni riga
    }
    
    cout << "\n=== BREAK E CONTINUE ===" << endl;
    
    // BREAK: esce dal ciclo
    cout << "Numeri da 1 a 10, ma fermiamoci a 6:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 7) {
            break;  // Esce dal ciclo quando i vale 7
        }
        cout << i << " ";
    }
    cout << endl;
    
    // CONTINUE: salta all'iterazione successiva
    cout << "Numeri pari da 1 a 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {  // Se è dispari
            continue;  // Salta questa iterazione
        }
        cout << i << " ";
    }
    cout << endl;
    
    cout << "\n=== ESEMPI PRATICI ===" << endl;
    
    // Esempio 1: Somma numeri
    cout << "Somma dei numeri da 1 a 100:" << endl;
    int somma = 0;
    for (int i = 1; i <= 100; i++) {
        somma += i;
    }
    cout << "Risultato: " << somma << endl;
    
    // Esempio 2: Fattoriale
    cout << "Fattoriale di 5:" << endl;
    int n = 5;
    int fattoriale = 1;
    for (int i = 1; i <= n; i++) {
        fattoriale *= i;
        cout << i << "! = " << fattoriale << endl;
    }
    
    // Esempio 3: Contare cifre
    cout << "Conteggio cifre del numero 12345:" << endl;
    int num = 12345;
    int cifre = 0;
    while (num > 0) {
        cifre++;
        num /= 10;  // Rimuove l'ultima cifra
        cout << "Rimangono " << num << ", cifre contate: " << cifre << endl;
    }
    cout << "Totale cifre: " << cifre << endl;
    
    // Esempio 4: Ricerca di un numero
    cout << "Ricerca del numero 7 nell'array [2,5,7,9,1]:" << endl;
    int array[] = {2, 5, 7, 9, 1};
    int dimensione = 5;
    int cercato = 7;
    bool trovato = false;
    
    for (int i = 0; i < dimensione; i++) {
        cout << "Controllo posizione " << i << ": " << array[i] << endl;
        if (array[i] == cercato) {
            cout << "Trovato " << cercato << " alla posizione " << i << endl;
            trovato = true;
            break;
        }
    }
    
    if (!trovato) {
        cout << "Numero non trovato" << endl;
    }
    
    // Esempio 5: Menu con ciclo
    cout << "\nSimulazione menu (interrompe a scelta 4):" << endl;
    int scelta = 0;
    int iterazione = 0;
    int scelte_simulate[] = {1, 2, 3, 4};  // Simuliamo le scelte
    
    while (true) {  // Ciclo infinito
        cout << "\nMENU:" << endl;
        cout << "1. Opzione A" << endl;
        cout << "2. Opzione B" << endl;
        cout << "3. Opzione C" << endl;
        cout << "4. Esci" << endl;
        cout << "Scelta: ";
        
        // Simuliamo input utente
        scelta = scelte_simulate[iterazione];
        cout << scelta << endl;
        
        switch (scelta) {
            case 1:
                cout << "Hai scelto Opzione A" << endl;
                break;
            case 2:
                cout << "Hai scelto Opzione B" << endl;
                break;
            case 3:
                cout << "Hai scelto Opzione C" << endl;
                break;
            case 4:
                cout << "Uscita dal programma..." << endl;
                return 0;  // Esce da tutto il programma
            default:
                cout << "Scelta non valida!" << endl;
        }
        
        iterazione++;
    }
    
    return 0;
}

/*
TIPI DI CICLO:

WHILE:
- Controlla prima, poi esegue
- Può non eseguirsi mai
- Perfetto quando non sai quante iterazioni servono

DO-WHILE:
- Esegue prima, poi controlla
- Si esegue ALMENO una volta
- Perfetto per menu e validazione input

FOR:
- Più compatto per contatori
- Inizializzazione, condizione, aggiornamento in una riga
- Perfetto per iterazioni con numero noto

CONTROLLI DI FLUSSO:
- break: esce dal ciclo corrente
- continue: salta alla prossima iterazione
- return: esce dalla funzione (e dal programma se in main)

ERRORI COMUNI:
- Ciclo infinito: dimenticare di aggiornare la variabile di controllo
- Off-by-one: sbagliare di 1 nelle condizioni (< vs <=)
- Variabile non inizializzata prima del while
*/
