#include <iostream>
#include <cmath>

using namespace std;

int contadorPasos = 0; 

// Función 
void moverDiscos(int n, int origen, int auxiliar, int destino) {
    if (n > 0) {
        // Movimiento hacia la torre auxiliar
        moverDiscos(n - 1, origen, destino, auxiliar);

        // Mostrar el movimiento
        contadorPasos++;
        cout << "Paso " << contadorPasos << ": Mover de la torre " << origen << " a la " << destino << endl;

        // Movimiento hacia el destino final
        moverDiscos(n - 1, auxiliar, origen, destino);
    }
}

int main() {
    int cantidad;
    char seguir;

    do {
        // Reiniciar el contador cada vez que el usuario eliga un disco nuevo
        contadorPasos = 0;

        cout << "--- MI JUEGO DE LAS TORRES DE HANOI ---" << endl;
        cout << "Ingresa cuantos discos quieres usar (3-7): ";
        cin >> cantidad;

        // Validación simple
        if (cantidad >= 3 && cantidad <= 7) {
            cout << "\nInstrucciones para resolverlo:" << endl;
            
            moverDiscos(cantidad, 1, 2, 3);

            // El usuario ve el resumen final
            cout << "\nTotal de movimientos realizados: " << contadorPasos << endl;
            
        
            int formula = pow(2, cantidad) - 1;
            cout << "(Segun la formula deberian ser: " << formula << ")" << endl;
        } else {
            cout << "Numero no valido, intenta de nuevo." << endl;
        }

        cout << "\n¿Quieres intentar con otro numero? (s/n): ";
        cin >> seguir;

    } while (seguir == 's' || seguir == 'S');

    cout << "Saliendo del programa..." << endl;

    return 0;
}