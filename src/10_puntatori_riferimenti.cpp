// 10_puntatori_riferimenti.cpp
// PUNTATORI E RIFERIMENTI - Gestione avanzata della memoria

#include <iostream>
using namespace std;

/*
==================== RIFERIMENTI IN C++ =====================

Cos'è un riferimento?
Un riferimento è come un puntatore ad una variabile con:
- il vantaggio di non avere la sintassi complessa dei puntatori
- il limite di non poter essere null (quindi non rischi di accedere a memoria non inizializzata)
- Ma che non possono essere riassegnati, un riferimento è legato a una sola variabile.

Sintassi: int& ref = variabile;

Esempio pratico:
void incrementa(int& x) {
    x++; // Modifica la variabile originale!
}

int a = 5;
incrementa(a); // Ora a vale 6

La vera differenza è nella sicurezza e nella sintassi, non nell’efficienza. 
Puoi usarli tranquillamente senza preoccuparti di rallentamenti o overhead!
• il limite di non poter essere null (quindi non rischi di accedere a memoria non inizializzata)
• Non possono essere “dangling”
============================================================*/

// ALLOCAZIONE E DEALLICAZIONE DINAMICA:
// in c++ si usa new e delete per allocare e deallocare memoria dinamica
// es: int* p = new int(42);  // allocazione di un intero, 42 è il valore assegnato 
//     delete p;              // deallocazione

// Se vuoi allocare uno spazio per 10 interi (tutti inizializzati a zero):
// int* array = new int[10](); // crea un array di 10 interi, tutti a 0
// delete[] array;             // libera la memoria

// PROTOTIPI FUNZIONI USATE NEL MAIN
void passaggioPerValore(int valore);
void passaggioPerPuntatore(int* ptr);
void passaggioPerRiferimento(int& ref);
void scambia(int* a, int* b);
int* trovaMassimo(int array[], int dimensione);


#include <iostream>
using namespace std;

int main() {
    cout << "=== INDIRIZZI DI MEMORIA ===" << endl;
    
    int numero = 42;
    cout << "Valore di numero: " << numero << endl;
    cout << "Indirizzo di numero: " << &numero << endl;  // & = operatore "indirizzo di"
    
    float decimale = 3.14;
    char carattere = 'A';
    cout << "Indirizzo di decimale: " << &decimale << endl;
    cout << "Indirizzo di carattere: " << (void*)&carattere << endl;  // Cast per char
    
    cout << "\n=== PUNTATORI BASE ===" << endl;
    
    // DICHIARAZIONE PUNTATORE
    int* puntatore;  // Puntatore a intero (non inizializzato!)
    
    // INIZIALIZZAZIONE PUNTATORE
    puntatore = &numero;  // per prendere l'indirizzo di un valore
    
    cout << "Valore della variabile: " << numero << endl;        // 42
    cout << "Indirizzo nella variabile puntatore: " << puntatore << endl;  // indirizzo
    cout << "Valore puntato (dereferenziazione): " << *puntatore << endl;  // 42
    
    // MODIFICA TRAMITE PUNTATORE
    *puntatore = 100;  // * = operatore di dereferenziazione
    cout << "Dopo modifica tramite puntatore:" << endl;
    cout << "numero: " << numero << endl;        // 100 (cambiato!)
    cout << "*puntatore: " << *puntatore << endl; // 100
    
    cout << "\n=== PUNTATORI E ARRAY ===" << endl;
    
    int numeri[] = {10, 20, 30, 40, 50};
    int* ptr_array = numeri;  // Il nome dell'array è già un puntatore!
    
    cout << "Array con indici normali: ";
    for (int i = 0; i < 5; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;
    
    cout << "Array con puntatore: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr_array + i) << " ";  // ptr_array[i] equivale a *(ptr_array + i)
    }
    cout << endl;
    
    // ARITMETICA DEI PUNTATORI
    cout << "Primo elemento: " << *ptr_array << endl;           // 10
    cout << "Secondo elemento: " << *(ptr_array + 1) << endl;   // 20
    cout << "Terzo elemento: " << *(ptr_array + 2) << endl;     // 30
    
    ptr_array++;  // Avanza al prossimo elemento
    cout << "Dopo ptr_array++: " << *ptr_array << endl;        // 20
    
    cout << "\n=== PUNTATORE NULL ===" << endl;
    
    int* ptr_null = nullptr;  // C++11: usa nullptr invece di NULL
    
    cout << "ptr_null: " << ptr_null << endl;
    
    // CONTROLLO PRIMA DI USARE IL PUNTATORE
    if (ptr_null != nullptr) {
        cout << "Valore: " << *ptr_null << endl;
    } else {
        cout << "Puntatore null - non posso dereferenziare!" << endl;
    }
    
    cout << "\n=== RIFERIMENTI ===" << endl;
    
    int originale = 25;
    int& riferimento = originale;  // riferimento è un "alias" di originale
    // RIFERIMENTI (C++)
    // Un riferimento è un "alias" di una variabile già esistente.
    // Sintassi: tipo& nome = variabile;
    // - Non può essere null
    // - Non può cambiare a cosa si riferisce dopo l'inizializzazione
    // - Si comporta come la variabile originale: ogni modifica al riferimento modifica l'originale
    // - Più sicuro e semplice dei puntatori per il passaggio di parametri
    
    cout << "originale: " << originale << endl;           // 25
    cout << "riferimento: " << riferimento << endl;       // 25
    cout << "Hanno lo stesso indirizzo? " << (&originale == &riferimento) << endl; // 1
    
    // MODIFICA TRAMITE RIFERIMENTO
    riferimento = 99;
    cout << "Dopo riferimento = 99:" << endl;
    cout << "originale: " << originale << endl;           // 99 (cambiato!)
    cout << "riferimento: " << riferimento << endl;       // 99
    
    cout << "\n=== DIFFERENZE PUNTATORI vs RIFERIMENTI ===" << endl;
    
    int a = 10, b = 20;
    
    // PUNTATORI: possono cambiare a cosa puntano
    int* ptr = &a;
    cout << "ptr punta ad a: " << *ptr << endl;  // 10
    ptr = &b;  // Ora punta a b
    cout << "ptr ora punta a b: " << *ptr << endl;  // 20
    
    // RIFERIMENTI: sempre lo stesso oggetto
    int& ref = a;  // Si inizializza UNA SOLA VOLTA
    cout << "ref si riferisce ad a: " << ref << endl;  // 10
    // ref = b;  // Questo NON cambia il riferimento, ma assegna b ad a!
    
    cout << "\n=== PASSAGGIO PARAMETRI ALLE FUNZIONI ===" << endl;
    
    // Funzioni definite sotto
    int valore = 5;
    
    cout << "Valore iniziale: " << valore << endl;
    
    passaggioPerValore(valore);
    cout << "Dopo passaggio per valore: " << valore << endl;  // 5 (non cambia)
    
    passaggioPerPuntatore(&valore);
    cout << "Dopo passaggio per puntatore: " << valore << endl;  // 15 (cambiato)
    
    passaggioPerRiferimento(valore);
    cout << "Dopo passaggio per riferimento: " << valore << endl;  // 25 (cambiato)
    
    cout << "\n=== ALLOCAZIONE DINAMICA ===" << endl;
    
    // NEW: alloca memoria nell'heap
    int* ptr_dinamico = new int(77);  // Alloca un int con valore 77
    cout << "Valore allocato dinamicamente: " << *ptr_dinamico << endl;
    
    // Array dinamico
    int dimensione = 5;
    int* array_dinamico = new int[dimensione];
    
    // Inizializza l'array
    for (int i = 0; i < dimensione; i++) {
        array_dinamico[i] = i * 10;
    }
    
    cout << "Array dinamico: ";
    for (int i = 0; i < dimensione; i++) {
        cout << array_dinamico[i] << " ";
    }
    cout << endl;
    
    // DELETE: libera la memoria (IMPORTANTE!)
    delete ptr_dinamico;        // Libera singola variabile
    delete[] array_dinamico;    // Libera array
    
    // Dopo delete, i puntatori sono "dangling" - non usare più!
    // ptr_dinamico = nullptr;  // Buona pratica
    
    cout << "\n=== ESEMPI PRATICI ===" << endl;
    
    // Esempio 1: Scambio di valori
    int x = 100, y = 200;
    cout << "Prima dello scambio: x=" << x << ", y=" << y << endl;
    scambia(&x, &y);
    cout << "Dopo lo scambio: x=" << x << ", y=" << y << endl;
    
    // Esempio 2: Trova il massimo e la sua posizione
    int dati[] = {3, 7, 1, 9, 4};
    int* ptr_max = trovaMassimo(dati, 5);
    cout << "Massimo nell'array: " << *ptr_max << endl;
    cout << "Posizione: " << (ptr_max - dati) << endl;
    
    return 0;
}

// FUNZIONI DI ESEMPIO PER PASSAGGIO PARAMETRI

void passaggioPerValore(int valore) {
    valore += 10;  // Modifica la COPIA, non l'originale
    cout << "Dentro la funzione (per valore): " << valore << endl;
}

void passaggioPerPuntatore(int* ptr) {
    *ptr += 10;  // Modifica l'ORIGINALE attraverso il puntatore
    cout << "Dentro la funzione (per puntatore): " << *ptr << endl;
}

void passaggioPerRiferimento(int& ref) {
    ref += 10;  // Modifica l'ORIGINALE attraverso il riferimento
    cout << "Dentro la funzione (per riferimento): " << ref << endl;
}

void scambia(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* trovaMassimo(int array[], int dimensione) {
    int* ptr_max = &array[0];  // Punta al primo elemento
    
    for (int i = 1; i < dimensione; i++) {
        if (array[i] > *ptr_max) {
            ptr_max = &array[i];  // Aggiorna il puntatore
        }
    }
    
    return ptr_max;  // Ritorna il puntatore al massimo
}
