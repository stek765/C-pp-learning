// enum e enum class
// vengono usati per creare tipi enumerativi, cioè tipi che possono assumere un insieme limitato di valori

#include <iostream>
using namespace std;

enum Color { RED, GREEN, BLUE }; // enum "vecchio stile", i valori sono in uno scope globale
enum class TrafficLight { RED, YELLOW, GREEN }; // enum class, i valori sono in uno scope separato

int main() {
    Color c = RED; // OK, RED è accessibile direttamente
    // Color c2 = TrafficLight::RED; // Errore, RED non è accessibile direttamente

    TrafficLight light = TrafficLight::RED; // OK, uso lo scope di TrafficLight
    if (light == TrafficLight::RED) {
        cout << "Stop!" << endl;
    }

    // Conversione tra enum e int
    int color_value = static_cast<int>(c); // Conversione esplicita da enum a int
    cout << "Color value: " << color_value << endl;

    // Non è possibile convertire implicitamente da int a enum class
    // TrafficLight light2 = 1; // Errore

    // Ma si può fare una conversione esplicita
    TrafficLight light2 = static_cast<TrafficLight>(1); // OK, ma attenzione ai valori validi
    if (light2 == TrafficLight::YELLOW) {
        cout << "Caution!" << endl;
    }

    return 0;
}
