#include <iostream>
#include <string>
#include <cctype>

int main() {
    bool flag;
    std::string stNumber;

        do {
            flag = false;
            std::cout << "Ingrese un Numero ENTERO natural por favor" << std::endl;
            std::cin >> stNumber;
            for (char c : stNumber) {
                if (!isdigit(c)) {
                    flag = true;
                    std::cout << "Solo son validos ENTEROS naturales:  ";
                    break;
                }
            }
        } while (flag);

    std::cout << "Conteo Numeros del 1 al "<< stNumber << ": \n";
    for (int x = 0; x < std::stoi(stNumber); x++) {
        std::cout << x + 1 << std::endl;
    }

    return EXIT_SUCCESS;
}