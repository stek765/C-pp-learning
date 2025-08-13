// 09_stringhe.cpp
// STRINGHE - Lavorare con il testo

#include <iostream>
#include <string>    // Per usare std::string
#include <cctype>    // Per funzioni su caratteri (toupper, tolower, etc.)
#include <algorithm> // Per transform, reverse, etc.
using namespace std;

int main() {
    cout << "=== STRINGHE BASE ===" << endl;
    
    // DICHIARAZIONE E INIZIALIZZAZIONE
    string nome = "Mario";
    string cognome("Rossi");           // Alternativa
    string frase = "Ciao mondo!";
    string vuota = "";                 // Stringa vuota
    string ripetuta(5, 'A');          // "AAAAA"
    
    cout << "Nome: " << nome << endl;
    cout << "Cognome: " << cognome << endl;
    cout << "Frase: " << frase << endl;
    cout << "Ripetuta: " << ripetuta << endl;
    
    // LUNGHEZZA STRINGA
    cout << "Lunghezza nome: " << nome.length() << endl;      // 5
    cout << "Lunghezza nome: " << nome.size() << endl;        // Uguale a length()
    cout << "È vuota? " << vuota.empty() << endl;             // 1 (true)
    
    cout << "\n=== ACCESSO AI CARATTERI ===" << endl;
    
    // ACCESSO TRAMITE INDICE
    cout << "Prima lettera: " << nome[0] << endl;             // M
    cout << "Ultima lettera: " << nome[nome.length()-1] << endl; // o
    cout << "Con at(): " << nome.at(1) << endl;               // a (più sicuro)
    
    // MODIFICA CARATTERI
    nome[0] = 'L';  // Cambia M in L
    cout << "Nome modificato: " << nome << endl;              // Lario
    
    // ITERAZIONE SU OGNI CARATTERE
    cout << "Caratteri di '" << frase << "': ";
    for (int i = 0; i < frase.length(); i++) {
        cout << frase[i] << " ";
    }
    cout << endl;
    
    // RANGE-BASED FOR LOOP (C++11)
    cout << "Con range-based for: ";
    for (char c : frase) {
        cout << c << " ";
    }
    cout << endl;
    
    cout << "\n=== CONCATENAZIONE ===" << endl;
    
    string parte1 = "Hello";
    string parte2 = "World";
    
    // CONCATENAZIONE CON +
    string risultato = parte1 + " " + parte2 + "!";
    cout << "Concatenazione: " << risultato << endl;
    
    // CONCATENAZIONE CON +=
    string messaggio = "Ciao";
    messaggio += " ";
    messaggio += "a";
    messaggio += " tutti!";
    cout << "Con +=: " << messaggio << endl;
    
    // APPEND
    string saluto = "Buongiorno";
    saluto.append(" amici");
    cout << "Con append: " << saluto << endl;
    
    cout << "\n=== CONFRONTO STRINGHE ===" << endl;
    
    string str1 = "apple";
    string str2 = "banana";
    string str3 = "apple";
    
    // CONFRONTO CON OPERATORI
    cout << "str1 == str3: " << (str1 == str3) << endl;       // 1 (true)
    cout << "str1 != str2: " << (str1 != str2) << endl;       // 1 (true)
    cout << "str1 < str2: " << (str1 < str2) << endl;         // 1 (ordine alfabetico)
    
    // COMPARE (ritorna: <0 se prima, 0 se uguale, >0 se dopo)
    int confronto = str1.compare(str2);
    cout << "str1.compare(str2): " << confronto << endl;      // < 0
    
    cout << "\n=== RICERCA NELLE STRINGHE ===" << endl;
    
    string testo = "Il gatto è sul tappeto";
    
    // FIND - trova prima occorrenza
    size_t posizione = testo.find("gatto");
    if (posizione != string::npos) {  // npos = "not found"
        cout << "Trovato 'gatto' alla posizione " << posizione << endl;
    }
    
    // FIND CON CARATTERE
    posizione = testo.find('è');
    cout << "Carattere 'è' alla posizione " << posizione << endl;
    
    // FIND DALLA FINE
    posizione = testo.rfind("t");  // Ultimo 't'
    cout << "Ultimo 't' alla posizione " << posizione << endl;
    
    // CONTROLLA SE CONTIENE
    if (testo.find("cane") == string::npos) {
        cout << "La parola 'cane' non è presente" << endl;
    }
    
    cout << "\n=== SUBSTRING ===" << endl;
    
    string frase_lunga = "Programmazione in C++";
    
    // SUBSTR(inizio, lunghezza)
    string parte = frase_lunga.substr(0, 13);  // "Programmazione"
    cout << "Primi 13 caratteri: " << parte << endl;
    
    string linguaggio = frase_lunga.substr(17);  // Dal carattere 17 in poi
    cout << "Linguaggio: " << linguaggio << endl;
    
    cout << "\n=== MODIFICA STRINGHE ===" << endl;
    
    string esempio = "Ciao Mondo";
    
    // REPLACE(posizione, lunghezza, nuova_stringa)
    esempio.replace(5, 5, "Universo");  // Sostituisce "Mondo" con "Universo"
    cout << "Dopo replace: " << esempio << endl;
    
    // INSERT
    esempio.insert(5, "Vasto ");
    cout << "Dopo insert: " << esempio << endl;
    
    // ERASE
    esempio.erase(5, 6);  // Rimuove "Vasto "
    cout << "Dopo erase: " << esempio << endl;
    
    cout << "\n=== CONVERSIONI MAIUSCOLE/MINUSCOLE ===" << endl;
    
    string misto = "CiAo MoNdO";
    string maiuscolo = misto;
    string minuscolo = misto;
    
    // TRANSFORM CON TOUPPER/TOLOWER
    transform(maiuscolo.begin(), maiuscolo.end(), maiuscolo.begin(), ::toupper);
    transform(minuscolo.begin(), minuscolo.end(), minuscolo.begin(), ::tolower);
    
    cout << "Originale: " << misto << endl;
    cout << "Maiuscolo: " << maiuscolo << endl;
    cout << "Minuscolo: " << minuscolo << endl;
    
    cout << "\n=== CONTROLLO CARATTERI ===" << endl;
    
    char carattere = 'A';
    
    cout << "Carattere: " << carattere << endl;
    cout << "È alfabetico? " << isalpha(carattere) << endl;
    cout << "È cifra? " << isdigit(carattere) << endl;
    cout << "È maiuscolo? " << isupper(carattere) << endl;
    cout << "È minuscolo? " << islower(carattere) << endl;
    cout << "È spazio? " << isspace(carattere) << endl;
    
    cout << "\n=== CONVERSIONI NUMERICHE ===" << endl;
    
    // DA STRINGA A NUMERO
    string numero_str = "123";
    string decimale_str = "45.67";
    
    int numero = stoi(numero_str);        // string to int
    float decimale = stof(decimale_str);  // string to float
    double preciso = stod(decimale_str);  // string to double
    
    cout << "Stringa '" << numero_str << "' -> numero " << numero << endl;
    cout << "Stringa '" << decimale_str << "' -> decimale " << decimale << endl;
    
    // DA NUMERO A STRINGA
    int valore = 789;
    string valore_str = to_string(valore);
    cout << "Numero " << valore << " -> stringa '" << valore_str << "'" << endl;
    
    cout << "\n=== ESEMPI PRATICI ===" << endl;
    
    // Esempio 1: Conta parole
    string frase_esempio = "Questa è una frase di prova";
    int spazi = 0;
    for (char c : frase_esempio) {
        if (c == ' ') spazi++;
    }
    int parole = spazi + 1;  // Numero spazi + 1
    cout << "Frase: " << frase_esempio << endl;
    cout << "Numero parole: " << parole << endl;
    
    // Esempio 2: Conta vocali
    string testo_vocali = "Programmazione";
    string vocali = "aeiouAEIOU";
    int conta_vocali = 0;
    
    for (char c : testo_vocali) {
        if (vocali.find(c) != string::npos) {
            conta_vocali++;
        }
    }
    cout << "Vocali in '" << testo_vocali << "': " << conta_vocali << endl;
    
    // Esempio 3: Palindromo
    string parola = "anna";
    string inversa = parola;
    reverse(inversa.begin(), inversa.end());
    
    if (parola == inversa) {
        cout << "'" << parola << "' è un palindromo" << endl;
    } else {
        cout << "'" << parola << "' non è un palindromo" << endl;
    }
    
    // Esempio 4: Validazione email semplice
    string email = "utente@esempio.com";
    bool email_valida = false;
    
    if (email.find('@') != string::npos && 
        email.find('.') != string::npos && 
        email.length() > 5) {
        email_valida = true;
    }
    
    cout << "Email '" << email << "' è " << (email_valida ? "valida" : "non valida") << endl;
    
    // Esempio 5: Rimuovi spazi
    string con_spazi = "  Ciao   mondo  ";
    string senza_spazi = "";
    
    for (char c : con_spazi) {
        if (c != ' ') {
            senza_spazi += c;
        }
    }
    
    cout << "Con spazi: '" << con_spazi << "'" << endl;
    cout << "Senza spazi: '" << senza_spazi << "'" << endl;
    
    return 0;
}

/*
STRING vs ARRAY DI CHAR:

C-STYLE (char[]):
- char nome[] = "Mario";
- Terminata da '\0'
- Dimensione fissa
- Operazioni manuali

C++ STYLE (std::string):
- string nome = "Mario";
- Dimensione dinamica
- Molti metodi incorporati
- Più sicura e facile

METODI PRINCIPALI STRING:

INFORMAZIONI:
- length(), size(): lunghezza
- empty(): è vuota?
- capacity(): spazio allocato

ACCESSO:
- [i], at(i): carattere all'indice i
- front(), back(): primo e ultimo carattere

RICERCA:
- find(substr): trova sottostringa
- rfind(substr): trova dall'ultimo
- find_first_of(), find_last_of()

MODIFICA:
- append(), +=: aggiunge
- insert(): inserisce
- erase(): rimuove
- replace(): sostituisce
- substr(): estrae sottostringa

CONFRONTO:
- ==, !=, <, >, <=, >=
- compare(): confronto con codice ritorno

CONVERSIONI:
- stoi(), stof(), stod(): da stringa a numero
- to_string(): da numero a stringa

TIPS:
- string::npos = valore speciale "non trovato"
- Range-based for per iterare: for(char c : str)
- #include <string> per std::string
- #include <cctype> per isalpha, toupper, etc.
- #include <algorithm> per reverse, transform, etc.
*/
