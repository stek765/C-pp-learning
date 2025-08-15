// 00_hello_world.cpp

#include <iostream>  // Libreria per input/output (cin, cout)
#include <iomanip>   // Per setw, setprecision, fixed, etc.
#include <string>    // Per std::string
#include <cstdio>    // Per printf

int main() {
    // cout = "console out" - stampa sulla console
    // << = operatore di inserimento
    // endl = end line (va a capo)
    std::cout << "Ciao Mondo!" << std::endl;
    
    // Alternativa senza std::
    using namespace std;
    cout << "Secondo messaggio senza std::" << endl;
    


    // BEST PRACTICES:

    cout << "\n=== MODI PIÙ COMUNI DI PRINTARE ===" << endl;
    
    // 1. COUT CON << (più comune in C++)
    cout << "Metodo 1: " << "cout con <<" << endl;
    
    // 2. PRINTF (stile C, ma funziona in C++)
    printf("Metodo 2: printf come in C\n");
    
    // 3. COUT CONCATENATO (più leggibile)
    string nome = "Marco";
    int eta = 25;
    cout << "Ciao " << nome << ", hai " << eta << " anni!" << endl;
    
    // 4. PRINTF FORMATTATO (come Python f-string)
    printf("Ciao %s, hai %d anni!\n", nome.c_str(), eta);
    
    cout << "\n=== ESEMPI CON TIPI DIVERSI ===" << endl;
    
    // TIPI NUMERICI
    int intero = 42;
    float decimale = 3.14f;
    double doppio = 2.71828;
    bool booleano = true;
    char carattere = 'A';
    
    cout << "Int: " << intero << " | Float: " << decimale << " | Double: " << doppio << endl;
    cout << "Bool: " << booleano << " | Char: " << carattere << endl;
    
    // CON PRINTF (specifica il tipo)
    printf("Int: %d | Float: %.2f | Double: %.5f\n", intero, decimale, doppio);
    printf("Bool: %d | Char: %c | ASCII: %d\n", booleano, carattere, carattere);
    
    /*
    CARATTERI SPECIALI:
    \n  = newline (a capo)
    \t  = tab (tabulazione)
    \"  = virgolette doppie
    \'  = virgolette singole  
    \\  = backslash
    \r  = carriage return
    \a  = bell (suono)
    \b  = backspace
    \0  = null terminator
    */
    
    cout << "\n=== FORMATTAZIONE AVANZATA ===" << endl;
    
    // PRECISIONE DECIMALI
    double pi = 3.14159265359;
    cout << "Pi normale: " << pi << endl;
    cout << fixed << setprecision(2);                   // 2 decimali fissi
    cout << "Pi 2 decimali: " << pi << endl;
    cout << setprecision(4);                            // 4 decimali fissi  
    cout << "Pi 4 decimali: " << pi << endl;
    
    // LARGHEZZA CAMPO
    cout << "\n--- Tabella con setw ---" << endl;
    cout << setw(10) << "Nome" << setw(5) << "Età" << setw(8) << "Voto" << endl;
    cout << setw(10) << "Mario" << setw(5) << 25 << setw(8) << 28.5 << endl;
    cout << setw(10) << "Anna" << setw(5) << 22 << setw(8) << 30.0 << endl;
    
    cout << "\n=== STAMPA CON COLORI (se supportato) ===" << endl;
    
    // CODICI ANSI PER COLORI (funziona su molti terminali)
    cout << "\033[31m" << "Testo rosso" << "\033[0m" << endl;      // Rosso
    cout << "\033[32m" << "Testo verde" << "\033[0m" << endl;      // Verde
    cout << "\033[33m" << "Testo giallo" << "\033[0m" << endl;     // Giallo
    cout << "\033[34m" << "Testo blu" << "\033[0m" << endl;        // Blu
    cout << "\033[35m" << "Testo magenta" << "\033[0m" << endl;    // Magenta
    cout << "\033[36m" << "Testo ciano" << "\033[0m" << endl;      // Ciano
    
    cout << "\n=== STAMPA ASCII ART ===" << endl;
    
    cout << "   _____ _    _" << endl;
    cout << "  / ____| |  | |" << endl;
    cout << " | |    | |__| |" << endl;
    cout << " | |    |  __  |" << endl;  
    cout << " | |____| |  | |" << endl;
    cout << "  \\_____|_|  |_|" << endl;
    cout << "     C++!" << endl;
    
    cout << "\n=== STAMPA FORME ===" << endl;
    
    
    cout << "\n Piramide:" << endl;
    int metà = 2;
    for (int i = 0; i < 3; i++){
        int j = 0; 
        while (j < 5){
            if (j < metà - i || j > metà + i) {
                cout << "  ";  // Spazio per allineamento
            } else {
                cout << "* ";  // Stampa asterisco
            }
            j++;
        }
        cout << endl;  // A capo dopo ogni riga
    
    }
    
    cout << "\n=== STAMPA MENU ===" << endl;
    
    cout << "╔══════════════════════════╗" << endl;
    cout << "║         MENU             ║" << endl;
    cout << "╠══════════════════════════╣" << endl;
    cout << "║ 1. Opzione uno           ║" << endl;
    cout << "║ 2. Opzione due           ║" << endl;
    cout << "║ 3. Opzione tre           ║" << endl;
    cout << "║ 4. Esci                  ║" << endl;
    cout << "╚══════════════════════════╝" << endl;
    cout << "Scelta: ";
    
    cout << "\n\n=== FINE ESEMPI ===" << endl;
    
    return 0;  // Ritorna 0 = programma terminato con successo
}

/*
COMPILAZIONE:
g++ 00_hello_world.cpp -o hello
./hello

*/