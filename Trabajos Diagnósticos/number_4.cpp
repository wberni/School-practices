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
    std::string stNota;
    int iNota;
    std::string stMensaje_final = "";
    bool flag;


    do {
            flag = false;
            clearConsole();

            std::cout << "Ingrese una nota valida del 1-10 por favor" << std::endl;
            std::cin >> stNota;
            for (char c : stNota) {
                if (!isdigit(c)) {
                    flag = true;
                    std::cout << "La nota no es valida: ";
                    break;
                }
            }
        
            if (flag) continue;
        
        iNota =  stoi(stNota);

        if (iNota > 10 || iNota < 1) { // verificacion que este dentro del rango
            flag = true;
            std::cout << "La nota no es valida: ";
        }

    } while (flag);
    



    if (iNota <= 5) {
        stMensaje_final = "Nota: " + stNota + "  ||  Usted esta reprobado, debe de recursar";
    } else if (iNota <= 7) {
        stMensaje_final = "Nota: " + stNota + "  ||  Usted esta aprobado";
    } else if (iNota <= 9) {
        stMensaje_final = "Nota: " + stNota + "  ||  Usted esta aprobado con nota distinguida!";
    } else {
        stMensaje_final = "Nota: " + stNota + "  ||  Usted esta aprobado con una nota sobresaliente!";
    }
    clearConsole();
    std::cout << stMensaje_final << std::endl;
    return EXIT_SUCCESS;
}