// 07_array_vettori.cpp
// ARRAY - Collezioni di elementi dello stesso tipo

#include <iostream>
using namespace std;

int main() {
    cout << "=== DICHIARAZIONE ARRAY ===" << endl;
    
    // DICHIARAZIONE E INIZIALIZZAZIONE
    int numeri[5] = {10, 20, 30, 40, 50};  // Array di 5 interi
    char lettere[3] = {'A', 'B', 'C'};     // Array di 3 caratteri
    float prezzi[] = {12.5, 8.0, 15.2};   // Dimensione automatica (3)
    
    // Array non inizializzato (valori casuali!)
    int vuoto[4];  // ATTENZIONE: contiene valori random!
    
    // Array inizializzato a zero
    int zeri[5] = {0};  // Primo elemento 0, gli altri automaticamente 0
    int tutti_zeri[5] = {};  // Tutti gli elementi a 0
    
    cout << "\n=== ACCESSO AGLI ELEMENTI ===" << endl;
    
    // ACCESSO TRAMITE INDICE (inizia da 0!)
    cout << "Primo numero: " << numeri[0] << endl;      // 10
    cout << "Secondo numero: " << numeri[1] << endl;    // 20
    cout << "Ultimo numero: " << numeri[4] << endl;     // 50
    
    // MODIFICA ELEMENTI
    numeri[2] = 99;  // Cambia il terzo elemento
    cout << "Numero modificato: " << numeri[2] << endl; // 99
    
    cout << "\n=== CICLI E ARRAY ===" << endl;
    
    // STAMPA TUTTO L'ARRAY
    cout << "Tutti i numeri: ";
    for (int i = 0; i < 5; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;
    
    // CALCOLO DELLA DIMENSIONE
    int dimensione = sizeof(numeri) / sizeof(numeri[0]);
    cout << "Dimensione array: " << dimensione << endl;
    
    // SOMMA TUTTI GLI ELEMENTI
    int somma = 0;
    for (int i = 0; i < dimensione; i++) {
        somma += numeri[i];
    }
    cout << "Somma elementi: " << somma << endl;
    
    cout << "\n=== RICERCA IN ARRAY ===" << endl;
    
    // RICERCA LINEARE
    int cercato = 99;
    bool trovato = false;
    int posizione = -1;
    
    for (int i = 0; i < dimensione; i++) {
        if (numeri[i] == cercato) {
            trovato = true;
            posizione = i;
            break;
        }
    }
    
    if (trovato) {
        cout << "Numero " << cercato << " trovato alla posizione " << posizione << endl;
    } else {
        cout << "Numero " << cercato << " non trovato" << endl;
    }
    
    cout << "\n=== TROVARE MIN E MAX ===" << endl;
    
    int voti[] = {18, 27, 24, 30, 22, 28};
    int dim_voti = sizeof(voti) / sizeof(voti[0]);
    
    int minimo = voti[0];  // Assume il primo come minimo
    int massimo = voti[0]; // Assume il primo come massimo
    
    for (int i = 1; i < dim_voti; i++) {  // Inizia da 1!
        if (voti[i] < minimo) {
            minimo = voti[i];
        }
        if (voti[i] > massimo) {
            massimo = voti[i];
        }
    }
    
    cout << "Voti: ";
    for (int i = 0; i < dim_voti; i++) {
        cout << voti[i] << " ";
    }
    cout << endl;
    cout << "Voto minimo: " << minimo << endl;
    cout << "Voto massimo: " << massimo << endl;
    
    cout << "\n=== ARRAY DI STRINGHE (CHAR) ===" << endl;
    
    // STRINGA COME ARRAY DI CHAR
    char nome[] = "Mario";  // Automaticamente aggiunge '\0' alla fine
    char cognome[10] = "Rossi";  // 10 caratteri massimo
    
    cout << "Nome: " << nome << endl;
    cout << "Cognome: " << cognome << endl;
    
    // ACCESSO AI SINGOLI CARATTERI
    cout << "Prima lettera nome: " << nome[0] << endl;
    cout << "Lettere del nome: ";
    for (int i = 0; nome[i] != '\0'; i++) {  // Finché non trova il terminatore
        cout << nome[i] << " ";
    }
    cout << endl;
    
    cout << "\n=== COPIA DI ARRAY ===" << endl;
    
    int originale[] = {1, 2, 3, 4, 5};
    int copia[5];
    
    // COPIA MANUALE (array NON si possono assegnare direttamente!)
    for (int i = 0; i < 5; i++) {
        copia[i] = originale[i];
    }
    
    cout << "Array originale: ";
    for (int i = 0; i < 5; i++) {
        cout << originale[i] << " ";
    }
    cout << endl;
    
    cout << "Array copia: ";
    for (int i = 0; i < 5; i++) {
        cout << copia[i] << " ";
    }
    cout << endl;
    
    cout << "\n=== ARRAY MULTIDIMENSIONALI (MATRICI) ===" << endl;
    
    // MATRICE 3x3
    int matrice[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Matrice 3x3:" << endl;
    for (int riga = 0; riga < 3; riga++) {
        for (int colonna = 0; colonna < 3; colonna++) {
            cout << matrice[riga][colonna] << "\t";
        }
        cout << endl;
    }
    
    // ACCESSO A ELEMENTO SPECIFICO
    cout << "Elemento riga 1, colonna 2: " << matrice[1][2] << endl;  // 6
    
    cout << "\n=== ESEMPI PRATICI ===" << endl;
    
    // Esempio 1: Media voti
    float voti_studente[] = {8.5, 7.0, 9.2, 6.8, 8.8};
    int num_voti = sizeof(voti_studente) / sizeof(voti_studente[0]);
    
    float somma_voti = 0;
    for (int i = 0; i < num_voti; i++) {
        somma_voti += voti_studente[i];
    }
    float media = somma_voti / num_voti;
    
    cout << "Voti studente: ";
    for (int i = 0; i < num_voti; i++) {
        cout << voti_studente[i] << " ";
    }
    cout << endl;
    cout << "Media: " << media << endl;
    
    // Esempio 2: Conta occorrenze
    int dati[] = {1, 3, 7, 3, 2, 3, 8, 3, 5};
    int dimensione_dati = sizeof(dati) / sizeof(dati[0]);
    int numero_da_contare = 3;
    int conteggio = 0;
    
    for (int i = 0; i < dimensione_dati; i++) {
        if (dati[i] == numero_da_contare) {
            conteggio++;
        }
    }
    
    cout << "Il numero " << numero_da_contare << " appare " << conteggio << " volte" << endl;
    
    // Esempio 3: Inversione array
    int da_invertire[] = {1, 2, 3, 4, 5};
    int dim = sizeof(da_invertire) / sizeof(da_invertire[0]);
    
    cout << "Array originale: ";
    for (int i = 0; i < dim; i++) {
        cout << da_invertire[i] << " ";
    }
    cout << endl;
    
    // Inversione: scambio primo con ultimo, secondo con penultimo, etc.
    for (int i = 0; i < dim / 2; i++) {
        int temp = da_invertire[i];
        da_invertire[i] = da_invertire[dim - 1 - i];
        da_invertire[dim - 1 - i] = temp;
    }
    
    cout << "Array invertito: ";
    for (int i = 0; i < dim; i++) {
        cout << da_invertire[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
CONCETTI CHIAVE ARRAY:

DICHIARAZIONE:
- tipo nome[dimensione]
- tipo nome[] = {valori...}  (dimensione automatica)
- tipo nome[dim] = {valori...}

ACCESSO:
- nome[indice] dove indice va da 0 a dimensione-1
- ATTENZIONE: C++ non controlla i limiti! array[100] su array[5] = ERRORE!

DIMENSIONE:
- sizeof(array) / sizeof(array[0])
- Funziona solo nell'ambito dove è dichiarato l'array

LIMITI:
- Dimensione fissa (determinata a compile-time)
- Non si possono assegnare: array1 = array2 ❌
- Non si possono confrontare: array1 == array2 ❌
- Bisogna fare tutto manualmente con i cicli

STRINGHE:
- Array di char terminato con '\0'
- "ciao" = {'c','i','a','o','\0'}

MATRICI:
- tipo nome[righe][colonne]
- Accesso: nome[i][j]

ALTERNATIVE MODERNE:
- std::vector (dimensione dinamica)
- std::array (dimensione fissa ma con funzioni)
- std::string (per stringhe)
*/
