// creazione di un object circuit, con un nome e un numero di fili,
// che prende in input il nome di ogni filo e lo salva nell'object circuit
// utilizzando modern c++ 14 metodologie, come make_unique

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Circuit
{
private:
    std::string name;
    std::vector<std::string> name_of_fili;

public:
    // Constructor
    Circuit(std::string name)
    {
        this->name = name;
    }

    // Method to add a filo name to the circuit
    void add_filo_name(std::string name_filo)
    {
        name_of_fili.push_back(name_filo);
    }

    // Metodo per dimostrare che il circuito è vivo
    void print_info()
    {
        std::cout << "\n[INFO CIRCUITO]\n";
        std::cout << "Nome: " << name << "\n";
        std::cout << "Numero fili: " << name_of_fili.size() << "\n"; // Uso la size() reale

        for (auto filo : name_of_fili)
        {
            std::cout << " - " << filo << "\n";
        }
    }
};

void add_names(Circuit &circuit, int number_of_fili)
{
    // take as input, the name of each filo and add it to the circuit
    for (int i = 0; i < number_of_fili; i++)
    {
        std::cout << "Enter the name of filo " << i + 1 << ": ";
        std::string new_name;
        std::getline(std::cin, new_name);

        circuit.add_filo_name(new_name);
    }
}

std::unique_ptr<Circuit> create_circuit()
{
    // create a circuit object
    std::cout << "Creating a circuit object...\n";
    std::cout << "-----------------------------\n";

    // take as input, number of fili in the circuit
    std::cout << "How many fili does the circuit have? ";
    int number_of_fili;
    std::cin >> number_of_fili;
    std::cin.ignore();
    // create a circuit obj
    auto ptr = std::make_unique<Circuit>("Ciruito Elettrico Stek");

    add_names(*ptr, number_of_fili);

    return ptr;
}

int main()
{
    std::cout << "Program starting...\n- - - - - - - -\n";
    auto my_circuit = create_circuit();

    my_circuit->print_info();

    return 0;
}