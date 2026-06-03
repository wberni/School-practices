#include <iostream>

int main() {
    int n;
    do {
        std::cin >> n;
        if(n >= 0){
            int fact = 1;
            for(int i=2;i<=n;i++) fact *= i;
            std::cout << fact << std::endl;
        } else {
            std::cout << "Debe ser un nro >= 0" << std::endl;
        }
    } while(n >= 0);
    return 0;
}