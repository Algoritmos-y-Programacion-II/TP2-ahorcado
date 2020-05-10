/*
 * 75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
 * Trabajo Practico Individual N2: Ahorcado
 * Hecho por Valentina Varela Rodriguez - 105374
 */


#include "Ahorcado.h"
#include "utils.h"

int main() {

    bool jugarDeNuevo;
    Jugador jugador;

    if(jugador.deseaCrearUsuario()) {
        jugador.crearUsuario();
    }

    do {
        string palabraAleatoria = elegirPalabraAleatoriaSegunCategoria();
        int tamanioPalabra = palabraAleatoria.length();
        Ahorcado ahorcado(jugador, palabraAleatoria, tamanioPalabra);
        ahorcado.nuevoJuego();

        jugarDeNuevo = ahorcado.deseaJugarDeNuevo();
        if (!jugarDeNuevo)
            ahorcado.mostrarDespedida();

    } while (jugarDeNuevo);

    return 0;
}