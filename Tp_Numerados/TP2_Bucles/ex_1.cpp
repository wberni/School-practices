#include <cmath>
#include <iostream>

bool isPrime(int number) {
    if (number <= 1) return false;
    
    for (int x = 2; x*x <= number; x++) {
        if (number % x == 0) {
            return false;
        }
    }
    return true;
}

void clearConsole() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux / macOS
    #endif
}

int main() {
    bool flag;
    std::string stNumber1;
    std::string stNumber2;

    do {
        flag = false;
        std::cout << "Ingrese un Numero PRIMO \n";
        std::cin >> stNumber1;

        for (char c : stNumber1) {
            if (!isdigit(c)) {
                clearConsole();
                flag = true;
                std::cout << "No es nro entero(positivo):  ";
                break;
            }
        }

        if (flag) continue;

        if (isPrime(std::stoi(stNumber1)) == false) {
                clearConsole();
                flag = true;
                std::cout << "El nro no es Primo:  ";
        }
    } while (flag);

    clearConsole();

    do {
        flag = false;
        std::cout << "        Num 1: " << stNumber1 << "    ||  Num 2: ? " << std::endl;
        std::cout << "Ingrese un Numero PRIMO \n";
        std::cin >> stNumber2;

        for (char c : stNumber2) {
            if (!isdigit(c)) {
                clearConsole();
                flag = true;
                std::cout << "No es nro entero(positivo):  ";
                break;
            }
        }

        if (flag) continue;

        if (isPrime(std::stoi(stNumber2)) == false) {
                clearConsole();
                flag = true;
                std::cout << "El nro no es Primo:  ";
        }
    } while (flag);


    clearConsole();

        std::cout << "╔═════════════════════════════════════════════════════╗ \n";
        std::cout << "║               >>> NÚMEROS PRIMOS <<<                ║ \n";
        std::cout << "╠═════════════════════════════════════════════════════╣ \n";
        std::cout << "║                                                     ║ \n";
        std::cout << "    Número [A] ➜ " << stNumber1 << std::endl;
        std::cout << "    Número [B] ➜ " << stNumber2 << std::endl;
        std::cout << "╔═════════════════════════════════════════════════════╗ \n";
        std::cout << "║           >>> SUMA de Números PRIMOS <<<            ║ \n";
        std::cout << "╠═════════════════════════════════════════════════════╣ \n";
        std::cout << "    Número A [" + stNumber1 + "] + " + "Número B [" + stNumber2 + "]  = " << std::stoi(stNumber1) + std::stoi(stNumber2) << std::endl;

 
    return EXIT_SUCCESS;
}
