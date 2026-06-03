#include <iostream>

int main() {
    char repetir;
    do {
        int N;
        std::cout << "Ingrese N para calcular S = 1 + 4 + 9 + ... + N^2: ";
        std::cin >> N;
        int suma = 0;
        for(int i=1; i<=N; i++) suma += i*i;
        std::cout << "La sumatoria de los cuadrados hasta " << N << " es: " << suma << std::endl;
        std::cout << "Desea repetir? (s/n): ";
        std::cin >> repetir;
    } while(repetir == 's' || repetir == 'S');
    return 0;
}