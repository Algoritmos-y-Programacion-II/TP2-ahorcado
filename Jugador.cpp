//
// Created by Valentina on 8/5/2020.
//

#include "Jugador.h"
// ------------------------------ METODOS PUBLICOS ----------------------------------//
// Constructor con parametros
Jugador:: Jugador(string nombreOut, int vidasOut) {
    nombre = nombreOut;
    vidas = vidasOut;
}

int Jugador:: obtenerVidas() {
    return vidas;
}

string Jugador:: obtenerNombre() {
    return nombre;
}

bool Jugador:: deseaCrearUsuario() {
    char opcion;
    bool crear;
    cout << "\n\nQueres crear un usuario con tu nombre? [s/n]\n"
            "-NOTA- De lo contrario vas a tener el nombre \"Juan/a Perez\"\n";
    cin >> opcion;
    crear = Utils::validarSiONo(opcion);
    return crear;
}

int Jugador:: pedirVidas() {
    int vidas;
    cout << "\nIngresa la cantidad de vidas (min 1 y max 7): ";
    cin >> vidas;
    Utils::validarNumero(1,7, vidas);
    return vidas;
}

string Jugador:: pedirNombre() {
    string nombre;
    cout << "Ingresa un nombre: ";
    cin >> nombre;
    Utils::validarPalabra(nombre);
    return nombre;
}

void Jugador:: crearUsuario() {
    string nombreOut = pedirNombre();
    nombre = nombreOut;
}

void Jugador:: quitarVidas(int vidasASacar) {
    vidas -= vidasASacar;
    cout << "Ooops! Incorrecto\n";
}

// ------------------------------ METODOS PRIVADOS ----------------------------------//
void Jugador:: asignarVidas(int vidasOut) {
    vidas = vidasOut;
}

void Jugador:: asignarNombre(string nombreOut) {
    nombre = nombreOut;
}
