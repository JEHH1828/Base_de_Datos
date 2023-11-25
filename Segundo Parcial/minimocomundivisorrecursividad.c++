#include <iostream>

using namespace std; 

// Función para calcular el máximo común divisor (MCD) de dos números
int calcularMCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calcularMCD(b, a % b);
}

// Función para calcular el mínimo común múltiplo (MCM) de dos números
int calcularMCM(int a, int b) {
    return (a * b) / calcularMCD(a, b);
}

int main() {
    int num1, num2;

    cout << "Ingrese el primer número: ";
    cin >> num1;

    cout << "Ingrese el segundo número: ";
    cin >> num2;

    int mcm = calcularMCM(num1, num2);
    cout << "El MCM de " << num1 << " y " << num2 << " es " << mcm << endl;

    return 0;
}






