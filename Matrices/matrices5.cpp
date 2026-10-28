// Hacer un algoritmo que llene una matriz de 4*4 y que almacene la diagonal principal en un arreglo.
// Imprimir el arreglo resultante
#include <iostream>


void Algoritmo(int x, int y, int valoresDiagonal[4], const int matriz[4][4]) {
	for (int i = 0; i < x; i++) {
		valoresDiagonal[i] = matriz[i][i];
	}

    std::cout << "Valores diagonal principal (izquierda a derecha descendiente): {";
              
    for (int i = 0; i < x; i++) {
        std::cout << valoresDiagonal[i];
        if (i < 3) {
            std::cout << ",";
    	}	
	}
	std::cout << "}\n\n";
}



int main()
{
	const int x = 4, y = 4;
	int matriz[x][y];
    int valoresDiagonal[4];

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

    Algoritmo(x, y, valoresDiagonal, matriz);
    
    return 0;
}