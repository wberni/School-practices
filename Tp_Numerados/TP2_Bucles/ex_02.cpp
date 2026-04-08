#include <iostream>
#include <string>
#include <cctype>
#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

void clearConsole() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux / macOS
    #endif
}

int main() {
    int iUser_option = 9; // inicializar
    std::string const allowed = "012";
    std::string stUser_option = "";
    int iEven_add_result = 0, iOdd_add_result = 0;
    bool bInput_flag;
    
    do {
        bInput_flag = false;
        std::cout << "\n                                             ============================\n";
        std::cout << "                                                     MINI MENU\n";
        std::cout << "                                             ============================\n";
        std::cout << "                                             1) Sumar numeros PARES (1-50)\n";
        std::cout << "                                             2) Sumar numeros IMPARES (1-50)\n";
        std::cout << "                                             0) Salir\n";
        std::cout << "                                             ============================\n";
        std::cout << "                                             Elegi una opcion: ";
        std::cin >> stUser_option;
        
        
        if (stUser_option.length() != 1) {
            bInput_flag = true;
            clearConsole();
            std::cout << "\n                                                Ingrese 1 solo caracter:  ";
        }
    
        if(bInput_flag) continue;
        
        for (char c : stUser_option) {
            if (allowed.find(c) == std::string::npos) {
                bInput_flag = true;
                clearConsole();
                std::cout << "\n                                             |++++++++++++++++++++++++++++++| " << "\n";
                std::cout << "                                             |     Caracteres Inválidos     |" << "\n";
                std::cout << "                                             |++++++++++++++++++++++++++++++| " << "\n";
                break;
            }
        }
    
        if (bInput_flag) continue;
        
        iUser_option = std::stoi(stUser_option);
    } while (bInput_flag);
    
    if (iUser_option == 1) { //Pares
        clearConsole();
        std::cout << "\n                                                     SUMA PARES (1-50)\n";
        std::cout << "                                             =================================\n";
        
        for (int x = 0; x <= 50; x++) {
            if (x % 2 == 0) {
                iEven_add_result += x;
                std::cout << "                                                      " << x << " +\n";
            }
        }
        std::cout << "\n";
        std::cout << "                                             ==================================\n";
        std::cout << "                                                         RESULTADO:\n";
        std::cout << "                                                            " << iEven_add_result << "\n";
        
    } else if (iUser_option == 2) { //Impares
        clearConsole();
        std::cout << "\n                                                    SUMA IMPARES (1-50)\n";
        std::cout << "                                             =================================\n";
        
        for (int x = 0; x <= 50; x++) {
            if (!(x % 2 == 0)) {
                iOdd_add_result += x;
                std::cout << "                                                      " << x << " +\n";
            }
        }
        std::cout << "\n";
        std::cout << "                                             ==================================\n";
        std::cout << "                                                         RESULTADO:\n";
        std::cout << "                                                            " << iOdd_add_result << "\n";
    } else { // Salida
        std::cout << "\n";
        std::cout << "\n" << std::endl;
        std::cout << "                                     █████╗ ██╗   ██╗    ██████╗ ███████╗██╗   ██╗ ██████╗ ██╗██████╗     ██╗" << std::endl;
        std::cout << "                                    ██╔══██╗██║   ██║    ██╔══██╗██╔════╝██║   ██║██╔═══██╗██║██╔══██╗    ██║" << std::endl;
        std::cout << "                                    ███████║██║   ██║    ██████╔╝█████╗  ██║   ██║██║   ██║██║██████╔╝    ██║" << std::endl;
        std::cout << "                                    ██╔══██║██║   ██║    ██╔══██╗██╔══╝  ╚██╗ ██╔╝██║   ██║██║██╔══██╗    ╚═╝" << std::endl;
        std::cout << "                                    ██║  ██║╚██████╔╝    ██║  ██║███████╗ ╚████╔╝ ╚██████╔╝██║██║  ██║    ██╗" << std::endl;
        std::cout << "                                    ╚═╝  ╚═╝ ╚═════╝     ╚═╝  ╚═╝╚══════╝  ╚═══╝   ╚═════╝ ╚═╝╚═╝  ╚═╝    ╚═╝" << std::endl;    
    }
    
    return EXIT_SUCCESS;
}



