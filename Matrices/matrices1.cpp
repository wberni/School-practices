// Hacer un algoritmo que almacene números en una matriz de 3*4. Imprimir la suma de los números pares almacenados en la matriz
#include <iostream>

int sumarPares(const int matriz[3][4]) {
    int suma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] % 2 == 0) {
                suma += matriz[i][j];
            }
        }
    }
    return suma;
}

int main()
{
    const int x = 3, y = 4;
    int matriz[x][y];

    std::cout << "Ingrese un valor\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << "Direccion [" << i << "][" << j << "]\n";
            std::cin >> matriz[i][j];
        }
    }

    std::cout << "Valores de la matriz\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << matriz[i][j];
            if (j < 3) {
                std::cout << " ";
            } else {
                std::cout << "\n";
            }
        }
    }

    std::cout << "La suma de todos los pares es: " << sumarPares(matriz) << "\n";

    return 0;
}