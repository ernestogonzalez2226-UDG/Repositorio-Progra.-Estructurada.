#include <iostream>
#include <string>

using namespace std;

// esta funcion la hice para que dibuje al ahorcado por partes
// recibe el numero de errores y dependiendo de eso imprime mas lineas
void dibujarAhorcado(int errores) {
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    
    // Si tiene un error, dibujo la cabeza
    if (errores >= 1) cout << "  O   |" << endl; else cout << "      |" << endl;
    
    // aqui se dibuja el tronco y los brazos segun vayan fallando
    if (errores == 2) cout << "  |   |" << endl;
    else if (errores == 3) cout << " /|   |" << endl;
    else if (errores >= 4) cout << " /|\\  |" << endl; // Los brazos y el cuerpo
    else cout << "      |" << endl;
    
    // Al final dibujo las piernas
    if (errores == 5) cout << " /    |" << endl;
    else if (errores >= 6) cout << " / \\  |" << endl;
    else cout << "      |" << endl;
    
    cout << "=========" << endl;
}

int main() {
    // variables para que el juego funcione
    string palabraSecreta;
    string progreso = "";
    int intentos = 0;
    int maxIntentos = 6;
    char letra;
    bool acertado;
    char respuesta;

    do {
        // reseteo los intentos cada que empieza un juego nuevo
        intentos = 0;
        cout << "--- JUEGO DEL AHORCADO ---" << endl;
        
        // El primer usuario mete la palabra (en mayusculas para que no haya falla)
        cout << "Introduce la palabra para jugar (MAYUSCULAS): ";
        cin >> palabraSecreta;

        // Con este for lleno la cadena de progreso con puros guiones
        // asi el jugador no sabe que letras hay al principio
        progreso = "";
        for (int i = 0; i < palabraSecreta.length(); i++) {
            progreso += "_";
        }

        // Ciclo principal, corre mientras no pierdas y no adivines
        while (intentos < maxIntentos && progreso != palabraSecreta) {
            dibujarAhorcado(intentos); //funcion del dibujo
            
            cout << "\nPalabra actual: " << progreso << endl;
            cout << "Errores: " << intentos << " de " << maxIntentos << endl;
            cout << "Dame una letra: ";
            cin >> letra;

            acertado = false;
            // Recorro toda la palabra para ver si la letra que pusieron si esta
            for (int i = 0; i < palabraSecreta.length(); i++) {
                if (palabraSecreta[i] == letra) {
                    progreso[i] = letra; // Sustituyo el guion por la letra real
                    acertado = true;
                }
            }

            // Si despues de revisar toda la palabra no hubo match, sumo un error
            if (acertado == false) {
                intentos++;
                cout << "Fallo! Esa letra no era." << endl;
            } else {
                cout << "Bien! Si esta la letra." << endl;
            }
        }

        // Checo si gano porque completo la palabra o si perdio por intentos
        dibujarAhorcado(intentos);
        if (progreso == palabraSecreta) {
            cout << "\n¡GANASTE! Adivinaste la palabra: " << palabraSecreta << endl;
        } else {
            cout << "\nPERDISTE... Te quedaste sin intentos." << endl;
            cout << "La palabra era: " << palabraSecreta << endl;
        }

        // Pregunto para el bucle de reinicio
        cout << "\nQuieres jugar de nuevo? (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    cout << "Fin del programa." << endl;

    return 0;
}