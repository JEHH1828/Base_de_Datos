//7.-Programar un algoritmo recursivo que permita hacer la "división por restas sucesivas."
#include <iostream>

using namespace std;

int divisionPorRestasSucesivas(int dividendo, int divisor) {
    if (divisor == 0) {
        cerr << "Error: No se puede dividir por cero." << endl;
        return -1;
    }

    if (dividendo < divisor) {
        return 0;
    } else {
        return 1 + divisionPorRestasSucesivas(dividendo - divisor, divisor);
    }
}

int main() {
    int dividendo, divisor;
    cout << "Ingrese el dividendo: ";
    cin >> dividendo;
    cout << "Ingrese el divisor: ";
    cin >> divisor;

    int resultado = divisionPorRestasSucesivas(dividendo, divisor);

    cout << "El resultado de la división es: " << resultado << endl;

    return 0;
}
