// 01_variabili_tipi.cpp
// VARIABILI E TIPI DI DATO

#include <iostream>
using namespace std;

int main() {
    // TIPI NUMERICI INTERI
    int numero = 42;                    // Intero (4 byte, da -2mld a +2mld)
    short piccolo = 100;                // Intero piccolo (2 byte)
    long grande = 1000000;              // Intero grande (8 byte)
    unsigned int positivo = 300;        // Solo numeri positivi (0 a 4mld)
    
    // TIPI NUMERICI DECIMALI
    float decimale = 3.14f;             // Virgola mobile (4 byte, 7 cifre precisione)
    double precisione = 3.14159265359;  // Doppia precisione (8 byte, 15 cifre)
    
    // CARATTERI E STRINGHE
    char lettera = 'A';                 // Un singolo carattere (1 byte)
    string testo = "Ciao mondo";        // Stringa di caratteri
    
    // BOOLEANI
    bool vero = true;                   // true o false
    bool falso = false;
    
    // STAMPIAMO TUTTO
    cout << "Intero: " << numero << endl;
    cout << "Float: " << decimale << endl;
    cout << "Double: " << precisione << endl;
    cout << "Char: " << lettera << endl;
    cout << "String: " << testo << endl;
    cout << "Bool vero: " << vero << endl;        // stampa 1
    cout << "Bool falso: " << falso << endl;      // stampa 0
    
    // DIMENSIONI IN MEMORIA
    cout << "\n--- DIMENSIONI ---" << endl;
    cout << "int: " << sizeof(int) << " byte" << endl;
    cout << "float: " << sizeof(float) << " byte" << endl;
    cout << "double: " << sizeof(double) << " byte" << endl;
    cout << "char: " << sizeof(char) << " byte" << endl;
    
    return 0;
}

/*
REGOLE VARIABILI:
- Iniziano con lettera o underscore
- Possono contenere lettere, numeri, underscore
- Case sensitive (età != Età)
- Non possono essere parole riservate (int, if, while...)

CONVENZIONI NOMI:
- camelCase: nomeVariabile
- snake_case: nome_variabile
- PascalCase: NomeVariabile (per classi)
*/
