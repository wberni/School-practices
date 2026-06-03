#include <iostream>

int main() {
    char repetir;
    do {
        int N, num;
        std::cout << "Ingrese la cantidad de numeros N: ";
        std::cin >> N;

        int sumaPares = 0, cantPares = 0;
        int sumaImpares = 0, cantImpares = 0;

        for(int i = 0; i < N; i++) {
            std::cin >> num;
            if(num % 2 == 0) {
                sumaPares += num;
                cantPares++;
            } else {
                sumaImpares += num;
                cantImpares++;
            }
        }

        float promedioImpares = (float)sumaImpares / cantImpares;

        std::cout << "Suma de pares: " << sumaPares << "\n";
        std::cout << "Cantidad de pares: " << cantPares << "\n";
        std::cout << "Promedio de impares: " << promedioImpares << "\n";

        std::cout << "Desea repetir? (s/n): ";
        std::cin >> repetir;
    } while(repetir == 's' || repetir == 'S');

    return 0;
}