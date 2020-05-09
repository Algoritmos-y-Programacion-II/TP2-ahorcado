#include "Ahorcado.h"
#include "utils.h"

int main() {

    bool jugarDeNuevo;
    Jugador jugador;

    if(deseaCrearUsuario()) {

        int vidas = pedirVidas();
        string nombre = pedirNombre();

        jugador.asignarVidas(vidas);
        jugador.asignarNombre(nombre);
    }

    string palabraAleatoria = elegirPalabraAleatoria();
    int tamanioPalabra = palabraAleatoria.length();

    do {
        Ahorcado ahorcado(jugador, palabraAleatoria, tamanioPalabra);
        ahorcado.nuevoJuego();

        jugarDeNuevo = ahorcado.deseaJugarDeNuevo();
        if (!jugarDeNuevo)
            ahorcado.mostrarDespedida();

    } while (jugarDeNuevo);

    return 0;
}