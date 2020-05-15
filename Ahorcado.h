//
// Created by Valentina on 8/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_AHORCADO_H
#define TRABAJOPRACTICO2AHORCADO_AHORCADO_H


#include "Jugador.h"
#include "CharDinamico.h"

const int NO_EMPEZO_JUEGO = -1;
const int EMPEZO_JUEGO = 0;
const int GANO_JUEGO = 1;
const int PERDIO_JUEGO = 2;

class Ahorcado {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int estadoJuego;
        CharDinamico palabraAAdivinar, palabraSecreta;
        Jugador jugador;

    // -------------------------- METODOS -------------------------- //
    public:
        Ahorcado();
        void asignarJugador(Jugador jugadorOut);
        void asignarPalabraSecreta(int tamanioOut);
        void asignarPalabraAAdivinar(string palabra);

        // PRE: -
        // POST: Comienza un nuevo juego
        void nuevoJuego();

        // PRE: -
        // POST: Si el usuario ingresa s, devuelve true, de lo contrario false
        bool deseaJugarDeNuevo();

        // PRE: El estadoJuego debe ser igual a GANO_JUEGO o PERDIO_JUEGO
        // POST: Muestra por pantalla el mensaje correspondiente de acuerdo a si el jugador gano o perdio
        void mostrarMensajeGanoOPerdio();

        // PRE: -
        // POST: Muestra por pantalla un mensaje de despedida
        void mostrarDespedida();

        void mostrarCategorias();
        void mostrarInstrucciones();

    private:
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
};

#endif //TRABAJOPRACTICO2AHORCADO_AHORCADO_H
