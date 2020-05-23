/*
  75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
  Trabajo Practico Individual N2: Ahorcado
  Hecho por Valentina Varela Rodriguez - 105374

 * ACLARACION
               Utils inicialmente era una clase con metodos estaticos y sin atributos, pregunte por el grupo de
               Telegram y Andy me dijo que la podía dejar así.
               Sin embargo había algo en esto que no me terminaba de cerrar y luego de investigar vi que en varios foros
               se desaconsejaban este tipo de clases porque probablemente son metodos que podrian implementarse en las
               clases existentes o utilizando herencia y polimorfismo.
               En caso de "necesitar" o mejor dicho querer implementar una clase de ese estilo, recomendaban utilizar
               un namespace y eso fue lo que hice.
               Links:
               https://www.vojtechruzicka.com/avoid-utility-classes/
               https://stackoverflow.com/questions/3070805/c-how-to-design-a-utility-class
               https://softwareengineering.stackexchange.com/questions/134540/are-utility-classes-with-nothing-but-static-members-an-anti-pattern-in-c
 */

#include "Ahorcado.h"
#include <iostream>

int main() {

    bool jugarDeNuevo;
    string palabraAleatoria;

    Jugador jugador;
    Ahorcado ahorcado(jugador);

    ahorcado.mostrarLogo();
    ahorcado.mostrarInstrucciones();

    if(jugador.deseaCrearUsuario()) {
        ahorcado.asignarNombreJugador(jugador.pedirNombre());
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