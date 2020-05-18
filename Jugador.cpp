//
// Created by Valentina on 8/5/2020.
//

#include "Jugador.h"

// ------------------------------ METODOS PUBLICOS ----------------------------------//

// <--------------------- constructor
Jugador:: Jugador(string nombreOut, int vidasOut) {
    nombre = nombreOut;
    vidas = vidasOut;
}
// -------------------------------->


// <--------------------- getters
int Jugador:: obtenerVidas() {
    return vidas;
}

string Jugador:: obtenerNombre() {
    return nombre;
}
// -------------------------------->


// <--------------------- setters
void Jugador:: asignarVidas(int vidasOut) {
    vidas = vidasOut;
}

void Jugador:: asignarNombre(string nombreOut) {
    nombre = nombreOut;
}
// -------------------------------->


// <--------------------- otros metodos
bool Jugador:: deseaCrearUsuario() {
    char opcion;
    bool crear;
    cout << "\n\nQueres crear un usuario con tu nombre? [s/n]\n"
            "-NOTA- De lo contrario vas a tener el nombre \"Juan/a Perez\"\n";
    cin >> opcion;
    crear = Utils::validarSiONo(opcion);
    return crear;
}

string Jugador:: pedirNombre() {
    string nombre;
    cout << "Ingresa un nombre: ";
    cin >> nombre;
    Utils::validarPalabra(nombre);
    return nombre;
}

void Jugador:: quitarVidas(int vidasASacar) {
    vidas -= vidasASacar;
    cout << "Ooops! Incorrecto\n";
}
// -------------------------------->