#include <iostream>

int main() {
    const int personas = 5;
    char repetir;
    do {
        float horas, tarifa, salario, totalSalarios = 0.0;

        for(int i = 1; i <= personas; i++) {
            std::cout << "Ingrese las horas trabajadas de la persona " << i << ": ";
            std::cin >> horas;
            std::cout << "Ingrese la tarifa por hora de la persona " << i << ": $";
            std::cin >> tarifa;
            salario = horas * tarifa;
            totalSalarios += salario;
            std::cout << "Salario persona " << i << ": $" << salario << "\n";
        }

        std::cout << "Sumatoria de todos los salarios: $" << totalSalarios << "\n";

        std::cout << "Desea repetir? (s/n): ";
        std::cin >> repetir;
    } while(repetir == 's' || repetir == 'S');

    return 0;
}