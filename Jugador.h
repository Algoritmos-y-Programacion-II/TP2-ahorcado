//
// Created by Valentina on 17/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_JUGADOR_H
#define TRABAJOPRACTICO2AHORCADO_JUGADOR_H

#include "Utils.h"

class Jugador {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int vidas;
        string nombre;

    // -------------------------- METODOS -------------------------- //
    public:

        // PRE: El string tiene que ser valido, el entero tiene que ser mayor a cero
        // POST: Construye un jugador con nombre y vidas
        Jugador(string nombreOut = "Juan/a Perez", int vidas = 3);

        // PRE: -
        // POST: Devuelve las vidas del jugador
        int obtenerVidas();

        // PRE: -
        // POST: Devuelve el nombre del jugador
        string obtenerNombre();

        // PRE: vidasOut > 0
        // POST: Le asigna vidasOut vidas al jugador
        void asignarVidas(int vidasOut);

        // PRE: nombreOut != ""
        // POST: Le asigna nombreOut al jugador
        void asignarNombre(string nombreOut);

        // PRE: vidasASacar > 0
        // POST: Le saca vidasASacar cantidad de vidas al jugador
        void quitarVidas(int vidasASacar);

        // PRE: -
        // POST: Devuelve true si el usuario desea crear un usuario, de lo contrario false
        bool deseaCrearUsuario();

        // PRE: -
        // POST: Devuelve el nombre ingresado por el usuario
        string pedirNombre();
};


#endif //TRABAJOPRACTICO2AHORCADO_JUGADOR_H
