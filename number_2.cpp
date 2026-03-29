#include <iostream>
#include <string>
#include <cctype>
int main() {
    bool bRepeat;
    std::string stMonto;
    float fMonto;
    float fPrecio_final;
    

    do {
        bRepeat = false;

        std::cout << "Ingrese el monto total" << std::endl;
        std::cin >> stMonto;

        for (char c : stMonto) {
        if (isalpha(c)) {
            bRepeat = true;
        }
       }
    } while (bRepeat); //verificaciòn para que el usuario no meta cualquier cosa

    fMonto = std::stof(stMonto); //monto numerico es el resultado de la conversiòn string --> float con stof()

    
    //CALCULO DE DESCUENTO Y MENSAJE FINAL
    if (fMonto > 5000) {
        fPrecio_final = fMonto - (fMonto * 0.15);
        std::cout << "PRECIO FINAL con descuento: $" << fPrecio_final << std::endl;
    } else {
        fPrecio_final = fMonto;
        std::cout << "PRECIO FINAL sin descuento: $" << fPrecio_final << std::endl;
    }

    return EXIT_SUCCESS;
}