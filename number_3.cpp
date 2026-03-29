#include <iostream>
#include <string>

void clearConsole() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux / macOS
    #endif
}

int main() {
    std::string stNum1;
    float fNum1;
    std::string stNum2;
    float fNum2;
    bool repeat;
    char cOption_menu;
    const std::string stOpciones_menu = "AaBbCcDd";
    float fResultado_final;

    do {
    repeat = false;
    std::cout << "Ingrese el 1er numero real \n";
    std::cin >> stNum1;
        for (char c : stNum1) {
            if (isalpha(c)) {
                clearConsole();
                repeat = true;
            }
        }
    } while (repeat);
    fNum1 = std::stof(stNum1); // valor numerico de nro 1 guardado


    do {
    repeat = false;
    std::cout << "Ingrese el 2do numero real \n";
    std::cin >> stNum2;
        for (char c : stNum2) {
            if (isalpha(c)) {
                clearConsole();
                repeat = true;
            }
        }
    } while (repeat);
    fNum2 = std::stof(stNum2); // valor numerico de nro 2 guardado


    do {
    repeat = false;
        clearConsole();
        std::cout << "        Num 1: " << fNum1 << "    ||  Num 2: " << fNum2 << std::endl;
        std::cout << "╔═════════════════════════════════════════════╗ \n";
        std::cout << "║        >>> CALCULADORA SYSTEM <<<           ║ \n";
        std::cout << "╠═════════════════════════════════════════════╣ \n";
        std::cout << "║                                             ║ \n";
        std::cout << "║   [A] ➜ Sumar los números                   ║ \n";
        std::cout << "║   [B] ➜ Restar los números                  ║ \n";
        std::cout << "║   [C] ➜ Multiplicar los números             ║ \n";
        std::cout << "║   [D] ➜ Dividir los números                 ║ \n";
        std::cout << "║        (validar que el segundo ≠ 0)         ║ \n";
        std::cout << "║                                             ║ \n";
        std::cout << "╠═════════════════════════════════════════════╣ \n";
        std::cout << "╠═════════════════════════════════════════════╣";
        std::cout << "   Seleccione una opción: ";
        std::cin >> cOption_menu;

        //VALIDACIÒN
        if (stOpciones_menu.find(cOption_menu) == std::string::npos) {
            repeat = true;
        }
    } while (repeat);



    //CALCULANDO RESULTADOS
    if (cOption_menu == 'A' || cOption_menu == 'a') {
        fResultado_final = (fNum1 + fNum2);
        
    } else if (cOption_menu == 'B' || cOption_menu == 'b') {
        fResultado_final = (fNum1 - fNum2);
    } else if (cOption_menu == 'C' || cOption_menu == 'c') {
        fResultado_final = (fNum1 * fNum2);
    } else if (cOption_menu == 'D' || cOption_menu == 'd') {
        if (fNum2 != 0) {
            fResultado_final = (fNum1 / fNum2);
        }
    }

    //MENSAJE
    if ((cOption_menu == 'D' || cOption_menu == 'd') && (fNum2 == 0)) {
       std::cout << "No sé puede dividir por cero (0) " << std::endl;
    } else {
        std::cout << "El resultado final es: " << fResultado_final << std::endl;
    }
    

    

}