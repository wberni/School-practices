#include<iostream>

struct nroMayor {
        int value = 0;
        int posX = 0;
        int posY = 0;
};

void CompararMayor(nroMayor *Mayor, int matriz[4][4], int i, int j) {
    if (matriz[i][j] > Mayor->value) {
        Mayor->value = matriz[i][j];
        Mayor->posX = i;
        Mayor->posY = j;
    }
}

int main()
{
    const int x = 4, y = 4;
    int matriz[x][y];
    nroMayor Mayor;

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

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            CompararMayor(&Mayor, matriz, i, j);
        }
    }

    std::cout << "Mayor: " << Mayor.value << "\n";
    std::cout << "Posición: [" << Mayor.posX << "][" << Mayor.posY << "]\n";

    return 0;
}