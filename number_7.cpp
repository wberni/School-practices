#include <iostream>
#include <string>
#include <cctype>
#include <vector>

void clearConsole() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux / macOS
    #endif
}

float ask_number(bool flag, std::string stNumber, std::string allowed, int counter) {
    do { 
                
                    flag = false;
                    clearConsole();
                    std::cout << "Ingrese el Número " << counter + 1 << std::endl;
                    std::cin >> stNumber;
                    if (stNumber.front() == '.' || stNumber.back() == '.') {
                        flag = true;
                        std::cout << "Número Invalido:  ";
                    }
                
                    if (flag) continue;
                
                for (char c : stNumber) {
                    if (allowed.find(c) == std::string::npos) {
                        flag = true;
                        std::cout << "Número Invalido:  ";
                        break;
                    }
                }
            } while (flag);

            return std::stof(stNumber);
}

int main() {
    std::string const allowed = "1234567890.";
    std::vector<float> prices;
    std::string stNumber;
    float fNumber = 0.0;
    float fTotal_prices = 0.0;
    bool flag;

    for (int x = 0; x < 3; x++) {
        fNumber = ask_number(flag, stNumber, allowed, x);
        prices.push_back(fNumber);
    }
    fTotal_prices = prices[0] + prices[1] + prices[2];
    clearConsole();
    


    std::cout << "-Lista de Precios- {";
    for (int x = 0; x < prices.size(); x++) { //mostrando números
        std::cout << "$" << prices[x];
        if (x != prices.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "} \n";
    std::cout << "" << std::endl;

    std::cout << "Precio 1 {$" << prices[0] << "}  +  Precio 2 {$" << prices[1] << "}  +  Precio 3 {$" << prices[2] << "}  =  $" << fTotal_prices << std::endl;
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "" << std::endl;

    return EXIT_SUCCESS;
}