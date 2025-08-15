// 24_file_stream.cpp
// FILE E STREAM - Lettura e scrittura file in C++

#include <iostream>
#include <fstream> // Libreria per gestire file
using namespace std;

/*
In C++ si usano gli stream per leggere e scrivere file:
- ofstream: scrittura su file (output file stream)
- ifstream: lettura da file (input file stream)

Buone pratiche:
- Chiudi sempre il file con .close() quando hai finito
- Controlla che il file sia stato aperto correttamente
*/

int main() {
    // Scrittura su file
    ofstream out("test.txt"); // Crea/apre il file in scrittura
    out << "Ciao file!" << endl; // Scrive una riga nel file
    out.close(); // Chiude il file

    // Lettura da file
    ifstream in("test.txt"); // Apre il file in lettura
    string riga;
    getline(in, riga); // Legge una riga dal file
    cout << "Letto: " << riga << endl; // Stampa la riga letta
    in.close(); // Chiude il file

    // Nota: puoi controllare se il file è stato aperto con in.is_open() o out.is_open()

    return 0;
}
