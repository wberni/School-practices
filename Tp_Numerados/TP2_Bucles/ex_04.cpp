#include <iostream>
#include <vector>

int main() {
    char repetir;
    do {
        std::vector<int> notas(10);
        int suma=0, peorNota=10;
        for(int i=0;i<10;i++){
            std::cin >> notas[i];
            suma += notas[i];
            if(notas[i] < peorNota) peorNota = notas[i];
        }
        double promedio = suma / 10.0;
        std::cout << promedio << " " << peorNota << std::endl;
        std::cout << "Desea repetir? (s/n): ";
        std::cin >> repetir;
    } while(repetir == 's' || repetir == 'S');
    return 0;
}