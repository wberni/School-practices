// Hacer un algoritmo que llene una matriz de 3*4. Sumar las columnas e imprimir que columna 
// tuvo la máxima suma y la suma de esa columna.

#include <iostream>


void Algoritmo(int x, int y, int Columnas[4], const int matriz[4][4]) {
    int indiceColumnaMayor = 0, sumaColumnaMayor = 0;
    for (int j = 0; j < y; j++) {
        int sumaColumna = 0;
        for (int i = 0; i < x; i++) {
            sumaColumna +=  matriz[i][j];

        }
        Columnas[j] = sumaColumna;
    }

    for (int j = 0; j < y; j++) {
        if (Columnas[j] > sumaColumnaMayor) {
            sumaColumnaMayor = Columnas[j];
            indiceColumnaMayor = j;
        }
    }

    std::cout << "La columna con la Máxima suma es la columna '" << indiceColumnaMayor + 1 << "', con la suma de [" 
              << Columnas[indiceColumnaMayor] << "] y los valores de {";
              
    for (int i = 0; i < x; i++) {
        std::cout << matriz[i][indiceColumnaMayor];
            if (i < 2) {
                std::cout << ", ";
            }
    }
    std::cout << "}\n\n";

}



int main()
{
    const int x = 3, y = 4;
    int Columnas[4];
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

    Algoritmo(x, y, Columnas, matriz);
    
    return 0;
}
