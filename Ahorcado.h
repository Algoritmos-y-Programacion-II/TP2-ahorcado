//
// Created by Valentina on 8/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_AHORCADO_H
#define TRABAJOPRACTICO2AHORCADO_AHORCADO_H


#include "Jugador.h"
#include "CharDinamico.h"

const int EMPEZO_JUEGO = 0;
const int GANO_JUEGO = 1;
const int PERDIO_JUEGO = 2;

class Ahorcado {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int intentosFallidos, estadoJuego;
        CharDinamico palabraAAdivinar, palabraSecreta;
        Jugador jugador;

    // -------------------------- METODOS -------------------------- //
    public:

        // PRE: vidasOut y tamanioPalabra > 0, nombreJugadorOut y palabraAleatoria != ""
        // POST: Crea un jugador con vidasOut cantidad de vidas, nombreJugadorOut nombre,
        //       Crea una palabraAAdivinar con palabra = palabraAleatoria y tamanio = tamanioPalabra
        Ahorcado(Jugador jugadorOut, string palabraAleatoria, int tamanioPalabra);

        // PRE: -
        // POST: Comienza un nuevo juego
        void nuevoJuego();

        // PRE: -
        // POST: Si el usuario ingresa s, devuelve true, de lo contrario false
        bool deseaJugarDeNuevo();

        // PRE: -
        // POST: Muestra por pantalla el mensaje correspondiente de acuerdo a si el jugador gano o perdio
        void mostrarMensajeGanoOPerdio();

        // PRE: -
        // POST: Muestra por pantalla un mensaje de despedida
        void mostrarDespedida();

    private:
        // PRE: caracter debe ser una letra [a-z]
        // POST: permite que el usuario arriesgue una letra
        void arriesgar(char caracter);

        // PRE: palabra debe ser un string válido que solo contenga letras [a-z]
        // POST: permite que el usuario arriesge una palabra
        void arriesgar(string palabra);

        // PRE: -
        // POST: muestra por pantalla el dibujo del ahorcado y la palabra secreta actualizados
        void actualizarAhorcado();

        // PRE: 0 <= fallos <= 7
        // POST: muestra el dibujo
        void mostrarDibujoAhorcado();


};

#endif //TRABAJOPRACTICO2AHORCADO_AHORCADO_H
