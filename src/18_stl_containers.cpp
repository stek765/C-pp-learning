
// 18_stl_containers.cpp
// STL - Container base

#include <iostream>
#include <vector> // Vettore dinamico
#include <map>    // Dizionario chiave-valore
using namespace std;

int main() {
    // VECTOR: array dinamico
    vector<int> v = {1, 2, 3};
    v.push_back(4); // aggiungi elemento
    for (int n : v) cout << n << " "; // stampa tutti
    cout << endl;

    // MAP: dizionario chiave-valore
    map<string, int> m;
    m["uno"] = 1;
    m["due"] = 2;
    cout << "m['due']: " << m["due"] << endl; // accesso per chiave
    return 0;
}
