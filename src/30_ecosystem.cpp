// 30_ecosystem.cpp
// ECOSYSTEM - Tool, build system, librerie esterne

#include <iostream>
using namespace std;

/*
In C++ l'ecosistema comprende:
- Tool di sviluppo: editor (VS Code, CLion), compilatori (g++, clang), debugger (gdb, lldb)
- Build system: Makefile, CMake, Ninja
- Librerie esterne: Boost, fmt, Eigen, OpenCV, SDL, ecc.
- Gestione pacchetti: vcpkg, Conan

Esempio di Makefile (semplificato):
all:
	g++ main.cpp -o main
clean:
	rm main

Esempio di uso libreria esterna (fmt):
#include <fmt/core.h>
int main() {
    fmt::print("Ciao da fmt!\n");
    return 0;
}

Consigli:
- Impara a usare CMake per progetti grandi
- Sfrutta le librerie esterne per non reinventare la ruota
- Usa il debugger per trovare bug velocemente
*/

int main() {
    cout << "Esempio: usa Makefile, CMake, librerie esterne!" << endl;
    return 0;
}
