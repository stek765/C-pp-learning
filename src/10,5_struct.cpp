// 10,5_struct.cpp

// Il primo passo derivante da C, per creare nuovi tipi di dato è l'uso delle struct
#include <iostream>
using namespace std;

struct Vector {
    int size; // dimensione del vettore
    double* elements; // puntatore agli elementi del vettore
};

void vector_init(Vector& v, int size) {
    v.size = size;
    v.elements = new double[size];  // alloco memoria per gli elementi del vettore
                                    // double[size] significa che sto creando un array di double di dimensione totale "size"
}

// Legge n elementi in CIN, e li somma
double read_and_sum(int n_elements){
    Vector v;
    vector_init(v, n_elements); // Inizializza il vettore

    double sum = 0.0;
    for (int i = 0; i < n_elements; ++i) {
        cout << "Inserisci elemento " << i << ": ";
        cin >> v.elements[i];
        sum += v.elements[i];
    }
    return sum;
}

// Esempio accesso agli elementi della struct (. o ->):
void print_vector(const Vector& v) {
    cout << "Vector (size=" << v.size << "): ";
    for (int i = 0; i < v.size; ++i) {
        cout << v.elements[i] << " ";
    }
    cout << endl;
}