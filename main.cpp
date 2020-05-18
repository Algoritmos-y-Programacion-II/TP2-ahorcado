/*
  75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
  Trabajo Practico Individual N2: Ahorcado
  Hecho por Valentina Varela Rodriguez - 105374

 * ACLARACIONES
             * Inicialmente Utils era una clase con metodos estaticos y sin atributos, pregunte por el grupo de
               Telegram y Andy me dijo que la podía dejar. Sin embargo luego de investigar vi que en muchos foros se
               desaconsejaba ese tipo de clases, y se recomendaba en to do caso utilizar namespaces.

             * El metodo main de la clase Ahorcado es para utilizarse en caso de que no se desee hacer la implementacion
               del juego en la funcion principal
 */

#include "Ahorcado.h"

int main() {

    bool jugarDeNuevo;
    string palabraAleatoria;

    Jugador jugador;
    Ahorcado ahorcado(jugador);

    ahorcado.mostrarInstrucciones();

    if(jugador.deseaCrearUsuario()) {
        jugador.crearUsuario();
        ahorcado.asignarNombreJugador(jugador);
    }

    do {

        string palabraIngresada;

        ahorcado.mostrarCategorias();
        ahorcado.elegirCategoria();
        ahorcado.elegirPalabraAleatoriaSegunCategoria();
        ahorcado.actualizarAhorcado();

        while (ahorcado.obtenerEstadoJuego() == EMPEZO_JUEGO && jugador.obtenerVidas() > 0) {

            cout << "Ingresa una letra o palabra: ";
            palabraIngresada = Utils::obtenerPalabraEnMayusculas();
            Utils::validarPalabra(palabraIngresada);

            if (palabraIngresada.length() > 1)
                ahorcado.arriesgar(palabraIngresada); // Metodo que recibe string

            else
                ahorcado.arriesgar(palabraIngresada[0]); // Metodo que recibe caracter

            ahorcado.actualizarAhorcado();
        }

        ahorcado.mostrarMensajeGanoOPerdio();

        jugarDeNuevo = ahorcado.deseaJugarDeNuevo();

        if (jugarDeNuevo)
            ahorcado.resetearJuego();

    } while (jugarDeNuevo);

    ahorcado.mostrarDespedida();

    return 0;
}