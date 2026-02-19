#include <iostream>
#include <unordered_map> // Este usa una tecnica llamada Hashing para implementar la Memoizacion, es el cuaderno donde se almacenan los datos resultantes
#include <chrono> //Este se usa como cronometro de presicion, para el medir cuanto tarda el proceso Collatz

using namespace std;

//Directorio global para la memoizacion (Guarda los resultados de las funciones, para que cuando el programa los vulva a ocupar)
unordered_map <long long, int> cache;

//Funcion para calcular la trayectoria de collatz optimizada
int calcularcollatz  (long long n) { //inico Funcion
    if (n == 1) return 0; // Si llegamos a uno se termina 

    //si ya se calculo antes nos regresamos al valor guardado
    if (cache.count(n)) return cache[n];

    int pasos;
    if (n % 2 == 0 ) { //Caso 1 collatz
        pasos = 1 + calcularcollatz(n / 2);
    } 
    else {//caso 2 collatz
        pasos = 1 + calcularcollatz (3 * n + 1);
    }

    //Guardar en memoria antes de return 0
    cache [n] = pasos;
    return pasos;

} //Fin funcion para calcular collatz

//interfaz de control 
void ejecutarprograma () {
    char opcion;
    do {
        long long numero;
        cout << "\n Ingresa un numero para calcular en secuencia collatz: ";
        cin >> numero;

        //Medicion de tiempo de ejecucion
        auto inicio = chrono::high_resolution_clock::now();        
        int iteraciones = calcularcollatz(numero);

        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo = fin - inicio;

        //Resultados
        cout << "------------------------------------------" << endl;
        cout << "Valor resultante: 1" << endl;
        cout << "Cantidad de iteraciones: " << iteraciones << endl;
        cout << "Tiempo de ejecucion: " << tiempo.count() << " ms" << endl;
        cout << "Elementos en memoria (cache): " << cache.size() << endl;
        cout << "------------------------------------------" << endl;

        //pedir continuar o parar
        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> opcion; 

    } 
    while (opcion == 's' || opcion == 'S');

    //Finalizar programa  
    cout << "Fin de programa" << endl;
}


int main () { //Funcion en proceso
    //Inicio caso base
    cache[1]=0;
    ejecutarprograma();
    return 0; 
}