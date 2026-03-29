#include <iostream>
#include <string>
#include <cctype>

void clearConsole() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux / macOS
    #endif
}

int main() {
    bool flag;
    int iNumber;
    std::string stNumber;

        do {
            
                flag = false;
                clearConsole();
                std::cout << "Ingrese un Numero ENTERO del 1-10" << std::endl;
                std::cin >> stNumber;
                for (char c : stNumber) {
                    if (!isdigit(c)) {
                        flag = true;
                        std::cout << "Número Invalido:  ";
                        break;
                    }
                }
            
                if (flag) continue;

            if (std::stoi(stNumber) < 1 || std::stoi(stNumber) > 10) {
                flag = true;
                std::cout << "Número Invalido:  ";
            }
        } while (flag);

        iNumber = std::stoi(stNumber);

        clearConsole();

    std::cout << "Tabla de multiplicar del número ingresado  {"<< stNumber << "} " << std::endl;
        for (int x = 0; x < 12 ; x++) {
            std::cout << iNumber << " x " << x+1 << " = " << iNumber * (x+1) << std::endl;
        }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "" << std::endl;


    return EXIT_SUCCESS;
}