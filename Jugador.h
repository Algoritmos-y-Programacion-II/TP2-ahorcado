//
// Created by Valentina on 8/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_JUGADOR_H
#define TRABAJOPRACTICO2AHORCADO_JUGADOR_H

#include <string>
using namespace std;

class Jugador {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int vidas;
        string nombre;

    // -------------------------- METODOS -------------------------- //
    public:

        // PRE: vidasOut tiene que ser mayor a 3, string tiene que ser valido
        // POST: construye un jugador
        Jugador(int vidasOut = 3, string nombreOut = "Juan/a Perez");

        // PRE: -
        // POST: Devuelve las vidas del jugador
        int obtenerVidas();

        // PRE: -
        // POST: Devuelve el nombre del jugador
        string obtenerNombre();

        // PRE: vidasASacar > 0
        // POST: Le saca vidasASacar cantidad de vidas al jugador
        void quitarVidas(int vidasASacar);

        // PRE: vidasOut > 0
        // POST: Le asigna vidasOut vidas al jugador
        void asignarVidas(int vidasOut);

        // PRE: nombreOut != ""
        // POST: Le asigna nombreOut al jugador
        void asignarNombre(string nombreOut);
};


#endif //TRABAJOPRACTICO2AHORCADO_JUGADOR_H
