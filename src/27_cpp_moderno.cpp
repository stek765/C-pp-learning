// 27_cpp_moderno.cpp
// C++ MODERNO - Novità e sintassi

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // auto: deduce il tipo
    auto x = 42;
    auto v = vector<int>{1,2,3};
    // range-based for
    for (auto n : v) cout << n << " ";
    cout << endl;
    // nullptr, smart pointer, lambda, ecc.
    return 0;
}
