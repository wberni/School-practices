#include <iostream>
#include <string>

int main() {
    std::string stName;
    std::string stAge;
    bool flag;

    std::cout << "HOLA, Bienvenido! \n";
    std::cout << "Cuál es tu Nombre?: ";
    std::getline(std::cin, stName);
    std::cout << "\n";

    do {
            flag = false;
            std::cout << "Genial!, aunque no se tu edad. ¿Cuántos años tenés?: ";
            std::cin >> stAge;
            for (char c : stAge) {
                if (!isdigit(c)) {
                    flag = true;
                    std::cout << "La edad debe ser numerica!:  ";
                    break;
                }
            }
    } while (flag);
    
    std::cout << "Bienvenido " << stName << " que tiene " << stAge << " años!" << std::endl;

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "" << std::endl;


    return EXIT_SUCCESS;
}