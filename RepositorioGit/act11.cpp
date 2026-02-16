#include <iostream>
#include <limits>

using namespace std;

// Funcion para verificar si un numero es primo
bool esPrimo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}// Fin funcion

void calcularPrimos(int limite) { // Funcion para calcular primos
    int sumaTotal = 0;
    cout << "Identificar: ";
    
    bool primero = true;
    for (int i = 2; i <= limite; i++) { //for inicio
        if (esPrimo(i)) {
            if (!primero) cout << ", ";
            cout << i;
            sumaTotal += i;
            primero = false;
        } //Fin for
    } //Fin funcion
    
    cout << "\nLos números primos son la suma total es: " << sumaTotal << endl;
}
//Variable
int n;
int main() { //inicio main
    
    cout << "Actividad: Sumatoria de Números Primos" << endl;
    cout << "Ingrese el límite superior: ";
    
    if (!(cin >> n) || n < 2) {
        cout << "Error: Ingrese un número entero positivo mayor o igual a 2." << endl;
        return 1;
    }

    calcularPrimos(n);
    return 0;
} //FIn main