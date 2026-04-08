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

void wait() {
    std::cout << "                                                Toque alguna tecla para continuar...";
    #ifdef WIN_32
        _getch();
    #else //Linux //MacOS
        termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    #endif
}


int main() {
    int const PIN = 2564;
    int iFailed_Attemps = 0;
    bool bInput_flag = false;
    bool bFailed_access = false;
    std::string stPin_attempt;
    std::string const allowed = "1234567890.";
    
    std::string stOption = "";
    int iOption;
    std::string stDeposit;
    std::string stGet_Money;
    float fSaldo = 1000.00;

            do {
                bInput_flag = false;                                                    
                std::cout << "                                                +-----------------------------------+\n";
                std::cout << "                                                |        ACCESO AL CAJERO           |\n";
                std::cout << "                                                +-----------------------------------+\n";
                std::cout << "                                                | Ingrese PIN (4 digitos):          |\n";
                std::cout << "                                                |> ";
                std::cin >> stPin_attempt;
                for (char c : stPin_attempt) {
                    if (!isdigit(c)) {
                        bInput_flag = true;
                        clearConsole();
                        std::cout << "\n                                                Caracteres invalidos:  " << std::endl;
                        break;
                    }
                }

                if (bInput_flag) continue; // si hay una flag, volver al comienzo del bucle


                if (stPin_attempt.length() != 4) {
                    bInput_flag = true;
                    clearConsole();
                    std::cout << "\n                                                El PIN debe tener 4 digitos:  " << std::endl;
                }


                if (bInput_flag) continue;



                if (PIN != std::stoi(stPin_attempt)) {
                    iFailed_Attemps += 1;
                        if (iFailed_Attemps == 2) {
                            clearConsole();
                            std::cout << "\n                                                Te queda 1 intento: " << std::endl;
                        } else if (iFailed_Attemps < 2){
                            clearConsole();
                            std::cout << "\n                                                Te quedan " << 3 - iFailed_Attemps << " intentos: " << std::endl;
                        } else {
                            bFailed_access = true;
                        }
                } else {
                    break;
                }
            } while (iFailed_Attemps < 3);
            clearConsole();

do {
        if (!bFailed_access) { //Si el entró en tres intentos
                    do {
                        bInput_flag = false;
                        std::cout << "\n                                                +-----------------------------------+\n";
                        std::cout << "                                                |          MENU PRINCIPAL           |\n";
                        std::cout << "                                                +-----------------------------------+\n";
                        std::cout << "                                                | [1] Consultar Saldo               |\n";
                        std::cout << "                                                | [2] Retirar Dinero                |\n";
                        std::cout << "                                                | [3] Depositar                     |\n";
                        std::cout << "                                                | [4] Salir                         |\n";
                        std::cout << "                                                +-----------------------------------+\n";
                        std::cout << "                                                |>";
                        std::cin >> stOption;
                        std::cin.ignore(1000, '\n'); //limpio el buffer hasta q halla un salto de linea o los 1ros 1k chars

                        for (char c : stOption) {
                            if (!isdigit(c)) {
                                bInput_flag = true;
                                clearConsole();
                                std::cout << "\n                                                Caracteres invalidos:  ";
                                break;
                            }
                        }
                        
                        if (bInput_flag) continue;
                        
                        if (stOption.length() != 1) {
                            bInput_flag = true;
                            clearConsole();
                            std::cout << "\n                                                Ingrese 1 solo caracter:  ";
                        }


                        if (bInput_flag) continue;


                        if ((stOption) != "1" && (stOption) != "2" && (stOption) != "3" && (stOption) != "4") {
                            clearConsole();
                            bInput_flag = true;
                            std::cout << "\n                                                Elegir una opción Válida:  ";
                        }

                    } while (bInput_flag);
                    clearConsole();
                    iOption = std::stoi(stOption);
                
                switch (iOption) {
                    case 1:
                        std::cout << "\n                                                      Dinero Disponible: $" << fSaldo << "\n";
                        wait();
                        clearConsole();
                        break;
                    case 2:
                        do {

                            bInput_flag = false;
                            std::cout << "\n                                                 Dinero Disponible: $" << fSaldo << "\n";
                            std::cout << "                                              +----------------------------+";
                            std::cout << "\n                                     - ¿Cuánto desea Retirar? [0 para volver al menú] - \n";
                            std::cout << "\n";
                            std::cout << "                                                >$ ";
                            std::cin >> stGet_Money;
                            if (stGet_Money == "0") {
                                break;
                            }
                            
                            if (stGet_Money.front() == '.' || stGet_Money.back() == '.') {
                                bInput_flag = true;
                                clearConsole();
                                std::cout << "\n                                       |++++++++++++++++++++++++++++++++++++++++++++| " << "\n";
                                std::cout << "                                       |      [.] No permitido en frente/dorso      |" << "\n";
                                std::cout << "                                       |++++++++++++++++++++++++++++++++++++++++++++| " << "\n";
                            }

                            if (bInput_flag) continue;

                            for (char c : stGet_Money) {
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
                            
                            if ((fSaldo - std::stof(stGet_Money)) < 0) {
                                bInput_flag = true;
                                clearConsole();
                                std::cout << "\n                                                |++++++++++++++++++++++++++| " << "\n";
                                std::cout << "                                                |   Saldo INSUFICIENTE     |" << "\n";
                                std::cout << "                                                |++++++++++++++++++++++++++| " << "\n";
                            }
                        } while (bInput_flag);
                        
                        if (!(stGet_Money == "0")) {
                            fSaldo = fSaldo - std::stof(stGet_Money);
                            clearConsole();
                            std::cout << "\n                                                  Cantidad [$" << stGet_Money << "] retirada con Éxito!" << "\n";
                            std::cout << "                                              |---------------------------------------| " << "\n";
                            std::cout << "                                                      Saldo Actual = $" << fSaldo << "\n";
                            std::cin.ignore(1000, '\n');
                            wait();
                        }
                        clearConsole();
                        break; 
                    case 3:
                        do {
                            bInput_flag = false;
                            std::cout << "\n                                                - ¿Cuánto desea Depositar? [0 para volver al menú]- \n";
                            std::cout << "                                                >$ ";
                            std::cin >> stDeposit;
                            if (stDeposit == "0") {
                                break;
                            }
                            
                            if (stDeposit.front() == '.' || stDeposit.back() == '.') {
                                clearConsole();
                                bInput_flag = true;
                                std::cout << "\n                                                  |++++++++++++++++++++++++++++++++++++++++++++| " << "\n";
                                std::cout << "                                                  |      [.] No permitido en frente/dorso      |" << "\n";
                                std::cout << "                                                  |++++++++++++++++++++++++++++++++++++++++++++| " << "\n";
                            }

                            if (bInput_flag) continue;

                            for (char c : stDeposit) {
                                if (allowed.find(c) == std::string::npos) {
                                    clearConsole();
                                    bInput_flag = true;
                                std::cout << "\n                                                          |++++++++++++++++++++++++++++++| " << "\n";
                                std::cout << "                                                          |     Caracteres Inválidos     |" << "\n";
                                std::cout << "                                                          |++++++++++++++++++++++++++++++| " << "\n";
                                    break;
                                }
                            }
                        } while (bInput_flag);
                        if (!(stDeposit == "0")) {
                            fSaldo += std::stof(stDeposit);
                            clearConsole();
                            std::cout << "\n                                                Cantidad [$" << stDeposit << "] depositada con Éxito!" << "\n";
                            std::cout << "                                              |---------------------------------------| " << "\n";
                            std::cout << "                                                      Dinero Disponible: $" << fSaldo << "\n";
                            std::cout << "\n";
                            std::cin.ignore(1000, '\n');
                            wait();
                        }
                        clearConsole();
                        break;
                    case 4:

                        std::cout << "\n";
                        std::cout << "\n" << std::endl;
                        std::cout << "                                                 █████╗ ██╗   ██╗    ██████╗ ███████╗██╗   ██╗ ██████╗ ██╗██████╗     ██╗" << std::endl;
                        std::cout << "                                                ██╔══██╗██║   ██║    ██╔══██╗██╔════╝██║   ██║██╔═══██╗██║██╔══██╗    ██║" << std::endl;
                        std::cout << "                                                ███████║██║   ██║    ██████╔╝█████╗  ██║   ██║██║   ██║██║██████╔╝    ██║" << std::endl;
                        std::cout << "                                                ██╔══██║██║   ██║    ██╔══██╗██╔══╝  ╚██╗ ██╔╝██║   ██║██║██╔══██╗    ╚═╝" << std::endl;
                        std::cout << "                                                ██║  ██║╚██████╔╝    ██║  ██║███████╗ ╚████╔╝ ╚██████╔╝██║██║  ██║    ██╗" << std::endl;
                        std::cout << "                                                ╚═╝  ╚═╝ ╚═════╝     ╚═╝  ╚═╝╚══════╝  ╚═══╝   ╚═════╝ ╚═╝╚═╝  ╚═╝    ╚═╝" << std::endl;                        break;
                }

        } else { //Si no entró en 3 intentos

            std::cout << "\n                                                - Te vas por no acordarte el pin, boludazo -" << std::endl;
            break;
        }


    } while (iOption != 4);
    return EXIT_SUCCESS;
}

