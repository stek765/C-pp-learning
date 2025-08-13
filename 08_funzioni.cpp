// 08_funzioni.cpp
// FUNZIONI - Riutilizzare codice e organizzare il programma

#include <iostream>
using namespace std;

// DICHIARAZIONE DI FUNZIONI (prototipi)
void saluta();                           // Funzione senza parametri e senza return
void salutaPersona(string nome);        // Funzione con parametro, senza return
int somma(int a, int b);                 // Funzione con parametri e return
float calcolaMedia(float v1, float v2, float v3);
int fattoriale(int n);
void stampaArray(int arr[], int dimensione);
bool isPrimo(int numero);

int main() {
    cout << "=== CHIAMATE DI FUNZIONI ===" << endl;
    
    // CHIAMATA FUNZIONE VOID (senza return)
    saluta();
    salutaPersona("Marco");
    
    // CHIAMATA FUNZIONE CON RETURN
    int risultato = somma(5, 3);
    cout << "5 + 3 = " << risultato << endl;
    
    // CHIAMATA DIRETTA SENZA VARIABILE
    cout << "10 + 7 = " << somma(10, 7) << endl;
    
    cout << "\n=== ESEMPI DI FUNZIONI ===" << endl;
    
    // Media di tre voti
    float media = calcolaMedia(8.5, 7.0, 9.2);
    cout << "Media voti: " << media << endl;
    
    // Fattoriale
    int n = 5;
    cout << "Fattoriale di " << n << " = " << fattoriale(n) << endl;
    
    // Test numero primo
    int numero = 17;
    if (isPrimo(numero)) {
        cout << numero << " è primo" << endl;
    } else {
        cout << numero << " non è primo" << endl;
    }
    
    // Stampa array
    int numeri[] = {10, 20, 30, 40, 50};
    cout << "Array: ";
    stampaArray(numeri, 5);
    
    cout << "\n=== FUNZIONI CON VALORI DI DEFAULT ===" << endl;
    
    // Funzione con parametri di default (definita sotto)
    cout << "Potenza di 2^3: " << potenza(2, 3) << endl;
    cout << "Potenza di 5^2 (default): " << potenza(5) << endl;
    
    cout << "\n=== OVERLOADING (STESSO NOME, PARAMETRI DIVERSI) ===" << endl;
    
    cout << "Somma interi: " << somma(3, 7) << endl;           // int + int
    cout << "Somma decimali: " << somma(3.5, 7.2) << endl;    // double + double
    cout << "Somma tre numeri: " << somma(1, 2, 3) << endl;   // tre parametri
    
    return 0;
}

// DEFINIZIONI DELLE FUNZIONI

void saluta() {
    cout << "Ciao! Benvenuto nel programma!" << endl;
}

void salutaPersona(string nome) {
    cout << "Ciao " << nome << "! Come stai?" << endl;
}

int somma(int a, int b) {
    return a + b;  // Ritorna il risultato
}

float calcolaMedia(float v1, float v2, float v3) {
    float somma = v1 + v2 + v3;
    return somma / 3.0;  // Importante: 3.0 per divisione reale
}

int fattoriale(int n) {
    if (n <= 1) {
        return 1;  // Caso base: 0! = 1! = 1
    }
    
    int risultato = 1;
    for (int i = 2; i <= n; i++) {
        risultato *= i;
    }
    return risultato;
}

void stampaArray(int arr[], int dimensione) {
    // NOTA: arr è un puntatore, non un array vero!
    for (int i = 0; i < dimensione; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isPrimo(int numero) {
    if (numero <= 1) {
        return false;  // 0 e 1 non sono primi
    }
    if (numero == 2) {
        return true;   // 2 è primo
    }
    if (numero % 2 == 0) {
        return false;  // Numeri pari > 2 non sono primi
    }
    
    // Controlla divisori dispari da 3 a √numero
    for (int i = 3; i * i <= numero; i += 2) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

// FUNZIONE CON PARAMETRO DI DEFAULT (deve essere nel prototipo!)
int potenza(int base, int esponente = 2) {  // Default: esponente = 2
    int risultato = 1;
    for (int i = 0; i < esponente; i++) {
        risultato *= base;
    }
    return risultato;
}

// OVERLOADING - STESSO NOME, PARAMETRI DIVERSI

// Già definita sopra: int somma(int a, int b)

double somma(double a, double b) {  // Diverso tipo parametri
    return a + b;
}

int somma(int a, int b, int c) {    // Diverso numero parametri
    return a + b + c;
}

// ESEMPI DI FUNZIONI UTILI

// Funzione per trovare il massimo
int massimo(int a, int b) {
    return (a > b) ? a : b;
}

int massimo(int a, int b, int c) {
    return massimo(massimo(a, b), c);  // Riusa la funzione a 2 parametri
}

// Funzione per scambiare due valori (PASSAGGIO PER RIFERIMENTO)
void scambia(int &a, int &b) {  // & = riferimento (modifica originale)
    int temp = a;
    a = b;
    b = temp;
}

// Esempio di utilizzo dello scambio (da chiamare in main se vuoi testare)
void testScambio() {
    int x = 10, y = 20;
    cout << "Prima dello scambio: x=" << x << ", y=" << y << endl;
    scambia(x, y);
    cout << "Dopo lo scambio: x=" << x << ", y=" << y << endl;
}

// Funzione ricorsiva (chiama se stessa)
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // fibonacci(0)=0, fibonacci(1)=1
    }
    return fibonacci(n-1) + fibonacci(n-2);  // Chiamata ricorsiva
}

// Funzione per validare input
int leggiInteroPositivo() {
    int numero;
    do {
        cout << "Inserisci un numero intero positivo: ";
        cin >> numero;
        if (numero <= 0) {
            cout << "Errore! Il numero deve essere positivo." << endl;
        }
    } while (numero <= 0);
    return numero;
}

// Funzione per calcolare MCD (Massimo Comun Divisore)
int mcd(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

/*
ANATOMIA DI UNA FUNZIONE:

tipo_ritorno nome_funzione(tipo param1, tipo param2, ...) {
    // corpo della funzione
    return valore;  // se tipo_ritorno != void
}

COMPONENTI:
- tipo_ritorno: int, float, bool, void (nessun ritorno)
- nome_funzione: segue regole variabili
- parametri: input della funzione
- return: output della funzione (opzionale se void)

PASSAGGIO PARAMETRI:
- Per valore: copia il valore (int a)
- Per riferimento: modifica l'originale (int &a)
- Array: sempre per riferimento (puntatore)

VANTAGGI FUNZIONI:
- Riutilizzo codice
- Modularity (divide et impera)
- Testing più facile
- Manutenzione semplificata
- Leggibilità migliorata

SCOPE (AMBITO):
- Variabili locali: esistono solo dentro la funzione
- Variabili globali: esistono ovunque (EVITARE!)
- Parametri: sono locali alla funzione

OVERLOADING:
- Stesso nome, parametri diversi (numero o tipo)
- Compilatore sceglie automaticamente quale usare
- NON si può fare overload solo sul tipo di ritorno

RICORSIONE:
- Funzione che chiama se stessa
- Serve un caso base per fermarsi
- Utile per problemi che si riducono (fattoriale, fibonacci)
*/
