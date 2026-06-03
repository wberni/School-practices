#include <iostream>

int main() {
    int num;
    char repetir;
    do {
        int positivos=0, negativos=0, neutros=0;
        for(int i=0;i<10;i++){
            std::cin >> num;
            if(num>0) positivos++;
            else if(num<0) negativos++;
            else neutros++;
        }
        std::cout << "Positivos: " << positivos << " Negativos: " << negativos << " Neutros: " << neutros << std::endl;
        std::cout << "Desea repetir? (s/n): ";
        std::cin >> repetir;
    } while(repetir == 's' || repetir == 'S');
    return 0;
}