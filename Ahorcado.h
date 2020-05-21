//
// Created by Valentina on 17/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_AHORCADO_H
#define TRABAJOPRACTICO2AHORCADO_AHORCADO_H


#include "Jugador.h"
#include "CharDinamico.h"

// Estados del juego
const int EMPEZO_JUEGO = 0;
const int GANO_JUEGO = 1;
const int PERDIO_JUEGO = 2;
const int CANT_VIDAS = 7;

class Ahorcado {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int estadoJuego, categoria;
        string letrasErroneas;
        CharDinamico palabraAAdivinar, palabraSecreta;
        Jugador jugador;

    // -------------------------- METODOS -------------------------- //
    public:

        // PRE: -
        // POST: Construye un ahorcado con estadoJuego en EMPEZO_JUEGO
        Ahorcado();

        // PRE: jugadorOut tiene que ser un objeto valido
        // POST: Construye un ahorcado con el jugadorOut, asignandole CANT_VIDAS al jugador, e inicializando
        //       estadoJuego en EMPEZO_JUEGO
        Ahorcado(Jugador jugadorOut);

        // PRE: -
        // POST: Es la estructura del juego, utilizar este metodo si no se desea implementar la logica en el main
        void main();

        // PRE: jugadorOut tiene que ser un objeto valido
        // POST: Le asigna el nombre de jugadorOut al atributo jugador
        void asignarNombreJugador(Jugador jugadorOut);

        // PRE: tamanioOut tiene que ser mayor o igual a cero
        // POST: Le asigna a palabraSecreta tamanioOut cantidad de guiones bajos (´_´)
        void asignarPalabraSecreta(int tamanioOut);

        // PRE: palabra debe contener solo letras (mayusculas o minusculas) de la A-Z exceptuando la Ñ
        // POST: Le asigna a palabraAAdivinar el string palabra
        void asignarPalabraAAdivinar(string palabra);

        // PRE: opcion debe ser un entero mayor a cero y menor o igual a CANT_CATEGORIAS
        // POST: Le asigna al atributo categoria la opcion recibida por parametro
        void asignarCategoria(int opcion);

        // PRE: -
        // POST: Devuelve un entero que representa el estado del juego
        int obtenerEstadoJuego();

        // PRE: -
        // POST: Devuelve la categoria
        int obtenerCategoria();

        // PRE: -
        // POST: Devuelve el jugador
        Jugador obtenerJugador();

        // PRE: -
        // POST: Devuelve las letras erroneas
        string obtenerLetrasErroneas();

        // PRE: -
        // POST: Le pide al usuario que elija una categoria y se la asigna al atributo
        void elegirCategoria();

        // PRE: -
        // POST: Asigna una palabra aleatoria de la categoria correspondiente al atributo palabraAleatoria
        //       A palabraSecreta se le asigna la cantidad de '_' que correspondan
        void elegirPalabraAleatoriaSegunCategoria();

        // PRE: -
        // POST: El estadoJuego vuelve a ser EMPEZO_JUEGO, se reinician las vidas del jugador y letrasErroneas es ""
        void resetearJuego();

        // PRE: -
        // POST: Si el usuario ingresa s, devuelve true, de lo contrario false
        bool deseaJugarDeNuevo();

        // PRE: -
        // POST: Muestra por pantalla el logo
        void mostrarLogo();

        // PRE: -
        // POST: Muestra por pantalla las instrucciones
        void mostrarInstrucciones();

        // PRE: -
        // POST: Muestra por pantalla las categorias disponibles
        void mostrarCategorias();

        // PRE: El estadoJuego debe ser igual a GANO_JUEGO o PERDIO_JUEGO
        // POST: Muestra por pantalla el mensaje correspondiente de acuerdo a si el jugador gano o perdio
        void mostrarMensajeGanoOPerdio();

        // PRE: -
        // POST: Muestra por pantalla un mensaje de despedida
        void mostrarDespedida();

        // PRE: caracter debe ser una letra [a-z]
        // POST: -
        void arriesgar(char caracter);

        // PRE: palabra debe ser un string válido que solo contenga letras [a-z]
        // POST: -
        void arriesgar(string palabra);

        // PRE: -
        // POST: muestra por pantalla el dibujo del ahorcado y la palabra secreta actualizados
        void actualizarAhorcado();

        // PRE: 0 <= fallos <= 7
        // POST: muestra el dibujo
        void mostrarDibujoAhorcado();

        // PRE: -
        // POST: Comienza un nuevo juego
        void nuevoJuego();
};

#endif //TRABAJOPRACTICO2AHORCADO_AHORCADO_H
