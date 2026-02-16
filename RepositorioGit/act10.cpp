#include <iostream>
#include <limits>
using namespace std;


// Funcion 
void analizarMultiplos(int limite) { 
    // Variables de la Funcion
    int cont3 = 0;
    int cont5 = 0;
    long sumatoriaTotal = 0;

    //Instruccioens 
    for (int i = 1; i <= limite; i++) {
        bool esMultiplo = false;
        // Multiplos de 3
        if (i % 3 == 0) {
            cont3++;
            esMultiplo = true;
        }
        //Multiplos de 5 
        if (i % 5 == 0) {
            cont5++;
            esMultiplo = true;
        }

        // Si fue múltiplo de cualquiera de los dos, se suma al total
        if (esMultiplo) {
            sumatoriaTotal += i;
        }
    }
    // Muestra los Multiplos y el resultado de la suma
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Multiplos de 3 encontrados: " << cont3 << endl;
    cout << "Multiplos de 5 encontrados: " << cont5 << endl;
    cout << "Sumatoria total de ambos: " << sumatoriaTotal << endl;
    cout << "------------------" << endl;
} // fin Funcion

//Variables 
int n = 0;
char continuar = 's';

//Inicio main
main(){
     //Ciclo While para continuar o parar
 
    while (continuar == 's' || continuar == 'S'){
         //Validar que el numero sea "Correcto"
        cout << "Ingrese un numero del 0 al 1000:" << endl;
        
        if (!(cin >> n) || n < 0 || n > 1000) {
            cout << "Error, ingrese un numero entero entre 0 y 1000 sin simbolos." << endl;

            // Limpia el estado de error de cin y el buffer para evitar ciclos infinitos
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Salta al inicio del ciclo para volver a pedir el dato
        }

        // --- LLAMADA A LA FUNCIÓN ---
        analizarMultiplos(n);

        // --- OPCIÓN DE CONTINUAR ---
        cout << "\n¿Desea continuar analizando otro numero? (s/n): ";
        cin >> continuar;
    }

    cout << "\nPrograma finalizado con exito." << endl;

    return 0;
     
     
} //Fin main