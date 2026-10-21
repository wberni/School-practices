// Hacer un algoritmo que llene una matriz de 4*4. Calcular la suma de cada fila y almacenarla en un arreglo,
// la suma de cada columna y almacenarla en otro arreglo.
#include <iostream>


void Arreglar(int x, int y, int Filas[4],int Columnas[4], const int matriz[4][4]) {
    for (int i = 0; i < x; i++) {
        int sumaFila = 0;
        for (int j = 0; j < y; j++) {
            sumaFila += matriz[i][j];
        }
        Filas[i] = sumaFila;
    }

    for (int j = 0; j < y; j++) {
        int sumaColumna = 0;
        for (int i = 0; i < x; i++) {
            sumaColumna +=  matriz[i][j];
        }
        Columnas[j] = sumaColumna;
    }
}

void mostrarArreglos(int x, int y, int Filas[4], int Columnas[4]) {
    // recorriendo y mostrando nros para verificar
    std::cout << "Sumas de Filas: ";
    for (int n = 0; n < x; n++) {
        std::cout << "[" << Filas[n] << "]";
    }
    std::cout << "\n";

    std::cout << "Sumas de Columna: ";
    for (int n = 0; n < y; n++) {
        std::cout << "[" << Columnas[n] << "]";
    }
    std::cout << "\n";
}



int main()
{
    const int x = 4, y = 4;
    int Columnas[4];
    int Filas[4];
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

    Arreglar(x, y, Filas, Columnas, matriz);
    mostrarArreglos(x, y, Filas, Columnas);
    
    return 0;
}