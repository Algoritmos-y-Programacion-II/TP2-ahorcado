//
// Created by Valentina on 8/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_JUGADOR_H
#define TRABAJOPRACTICO2AHORCADO_JUGADOR_H

#include <string>
using namespace std;

class Jugador {
    private:
        int vidas;
        string nombre;

    public:

        // PRE: vidasOut tiene que ser mayor a 3, string tiene que ser valido
        // POST: construye un jugador
        Jugador(int vidasOut = 3, string nombreOut = "Jane/John Doe");
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

        void quitarVidas(int vidasASacar);


};


#endif //TRABAJOPRACTICO2AHORCADO_JUGADOR_H
