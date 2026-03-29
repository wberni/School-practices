#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> numbers;
    std::string stNum;
    std::string stExtra;
    int position;
    bool flag;

    for (int x = 0; x < 10; x++) { //cargando numeros
        do {
            flag = false;
            std::cout << "Ingrese el nro " << x+1 << std::endl;
            std::cin >> stNum;
            for (char c : stNum) {
                if (!isdigit(c)) {
                    flag = true;
                    std::cout << "Solo son validos Numeros Enteros:  ";
                    break;
                }
            }
        } while (flag);

        numbers.push_back(stNum);
    }

    std::cout << "Ingrese un numero extra" << std::endl;
    std::cin >> stExtra;

    for (int x = 0; x < numbers.size(); x++) {
        if (numbers[x] == stExtra) {
            flag = true;
            position = x;
        }
    }

    std::cout << "-Lista de Numeros- {";
    for (int x = 0; x < numbers.size(); x++) {
        std::cout << numbers[x];
        if (x != numbers.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;


    if (flag) {
        std::cout << "El numero -extra- { " + stExtra + " } se encuentra dentro de la posicion " << position + 1 << " de los nros ingresados" << std::endl;
    } else {
        std::cout << "El numero -extra- { " + stExtra + " } NO se encuentra dentro de los nros ingresados " << std::endl;
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "" << std::endl;

    return EXIT_SUCCESS;
}