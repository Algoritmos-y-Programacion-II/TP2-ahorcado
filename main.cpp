/*
 * 75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
 * Trabajo Practico Individual N2: Ahorcado
 * Hecho por Valentina Varela Rodriguez - 105374
 *
 * COMO JUGAR:
 *            1. Decida si desea o no crear un usuario con su nombre
 *            2. Elija la categoria a la cual pertenecera la palabra a adivinar
 *            3. Intente adivinar la palabra antes de quedarse sin vidas.
 *               Puede arriesgar una letra o toda la palabra.
 *               Si la letra no esta en la palabra PERDERA UNA vida
 *               Si la palabra no es correcta PERDERA DOS vidas.
 *               Buena suerte!
 *
 * ACLARACION EN CUANTO A LAS CLASES
 *               Decidi utilizar 3 clases: Ahorcado, Jugador y CharDinamico porque me parecia mas prolijo
 *               para ordenar los metodos y atributos. No crei que el metodo insertarCaracter(), por ejemplo,
 *               perteneciera a la clase Ahorcado que corresponde al juego.
 *               De esta manera Ahorcado tiene dos atributos de tipo CharDinamico y uno de tipo Jugador.
 */

#include "Ahorcado.h"

int main() {

    bool jugarDeNuevo;
    string palabraAleatoria;
    Jugador jugador;
    Ahorcado ahorcado;

    ahorcado.mostrarInstrucciones();

    if(jugador.deseaCrearUsuario()) {
        jugador.crearUsuario();
    }

    do {
        ahorcado.mostrarCategorias();
        palabraAleatoria = Utils::elegirPalabraAleatoriaSegunCategoria();

        ahorcado.asignarJugador(jugador);
        ahorcado.asignarPalabraAAdivinar(palabraAleatoria);
        ahorcado.asignarPalabraSecreta(palabraAleatoria.size());

        ahorcado.nuevoJuego();

        jugarDeNuevo = ahorcado.deseaJugarDeNuevo();

    } while (jugarDeNuevo);

    ahorcado.mostrarDespedida();

    return 0;
}