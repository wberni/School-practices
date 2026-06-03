#include <iostream>
#include <vector>

int main() {
    char repetir;
    int N;
    std::vector<int> numeros;
    int maximo, minimo;
    int i, num;

    do {
        std::cout << "Ingrese la cantidad de numeros N: ";
        std::cin >> N;

        numeros.resize(N);

        for(i = 0; i < N; i++) {
            std::cin >> numeros[i];
        }

        maximo = numeros[0];
        minimo = numeros[0];

        for(i = 1; i < N; i++) {
            if(numeros[i] > maximo) maximo = numeros[i];
            if(numeros[i] < minimo) minimo = numeros[i];
        }

        std::cout << "Numero maximo: " << maximo << "\n";
        std::cout << "Numero minimo: " << minimo << "\n";

        std::cout << "Desea repetir? (s/n): ";
        std::cin >> repetir;
    } while(repetir == 's' || repetir == 'S');

    return 0;
}