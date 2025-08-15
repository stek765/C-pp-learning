// 03_operatori.cpp
// OPERATORI - Fare calcoli e confronti

#include <iostream>
using namespace std;

int main() {
    // VARIABILI PER I TEST
    int a = 10, b = 3;
    float x = 7.5, y = 2.5;
    
    cout << "=== OPERATORI ARITMETICI ===" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    // OPERATORI BASE
    cout << "a + b = " << (a + b) << endl;    // Addizione: 13
    cout << "a - b = " << (a - b) << endl;    // Sottrazione: 7
    cout << "a * b = " << (a * b) << endl;    // Moltiplicazione: 30
    cout << "a / b = " << (a / b) << endl;    // Divisione intera: 3 (non 3.33!)
    cout << "a % b = " << (a % b) << endl;    // Modulo (resto): 1
    
    // DIVISIONE CON FLOAT
    cout << "x / y = " << (x / y) << endl;    // Divisione reale: 3
    cout << "a / (float)b = " << (a / (float)b) << endl; // Cast: 3.33333
    
    cout << "\n=== OPERATORI DI ASSEGNAMENTO ===" << endl;
    int numero = 5;
    cout << "numero iniziale: " << numero << endl;
    
    numero += 3;  // equivale a: numero = numero + 3
    cout << "dopo += 3: " << numero << endl;  // 8
    
    numero -= 2;  // equivale a: numero = numero - 2
    cout << "dopo -= 2: " << numero << endl;  // 6
    
    numero *= 2;  // equivale a: numero = numero * 2
    cout << "dopo *= 2: " << numero << endl;  // 12
    
    numero /= 4;  // equivale a: numero = numero / 4
    cout << "dopo /= 4: " << numero << endl;  // 3
    
    cout << "\n=== OPERATORI DI INCREMENTO/DECREMENTO ===" << endl;
    int contatore = 0;
    cout << "contatore: " << contatore << endl;
    
    // PRE-INCREMENTO (prima incrementa, poi usa)
    cout << "++contatore: " << ++contatore << endl;  // stampa 1
    cout << "contatore ora: " << contatore << endl;   // 1
    
    // POST-INCREMENTO (prima usa, poi incrementa)
    cout << "contatore++: " << contatore++ << endl;  // stampa 1
    cout << "contatore ora: " << contatore << endl;   // 2
    
    cout << "\n=== OPERATORI DI CONFRONTO ===" << endl;
    int primo = 5, secondo = 8;
    cout << "primo = " << primo << ", secondo = " << secondo << endl;
    
    cout << "primo == secondo: " << (primo == secondo) << endl;  // 0 (false)
    cout << "primo != secondo: " << (primo != secondo) << endl;  // 1 (true)
    cout << "primo < secondo: " << (primo < secondo) << endl;    // 1 (true)
    cout << "primo > secondo: " << (primo > secondo) << endl;    // 0 (false)
    cout << "primo <= secondo: " << (primo <= secondo) << endl;  // 1 (true)
    cout << "primo >= secondo: " << (primo >= secondo) << endl;  // 0 (false)
    
    cout << "\n=== OPERATORI LOGICI ===" << endl;
    bool vero = true, falso = false;
    
    cout << "vero && falso: " << (vero && falso) << endl;   // AND: 0 (false)
    cout << "vero || falso: " << (vero || falso) << endl;   // OR: 1 (true)
    cout << "!vero: " << (!vero) << endl;                   // NOT: 0 (false)
    
    // ESEMPIO PRATICO
    int eta = 18;
    bool maggiorenne = (eta >= 18);
    bool minorenne = !maggiorenne;
    
    cout << "Età: " << eta << endl;
    cout << "Maggiorenne: " << maggiorenne << endl;
    cout << "Minorenne: " << minorenne << endl;
    
    return 0;
}

/*
PRECEDENZA OPERATORI (dall'alto al basso):
1. () parentesi
2. !, ++, --, + unario, - unario
3. *, /, %
4. +, -
5. <, <=, >, >=
6. ==, !=
7. &&
8. ||
9. = e varianti (+=, -=, etc.)

TIPS:
- Usa sempre parentesi per chiarezza: (a + b) * c
- Attento alla divisione intera: 5/2 = 2, non 2.5
- Per divisione reale: 5.0/2 oppure (float)5/2
*/
