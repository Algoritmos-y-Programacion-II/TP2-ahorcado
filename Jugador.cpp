//
// Created by Valentina on 8/5/2020.
//

#include "Jugador.h"
// ------------------------------ METODOS PUBLICOS ----------------------------------//
// Constructor con parametros
Jugador:: Jugador(int vidasOut, string nombreOut) {
    vidas = vidasOut;
    nombre = nombreOut;
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
    cout << "\nQueres crear un usuario y elegir la cantidad de vidas? [s/n]\n"
            "--AVISO-- De lo contrario se te asignara el nombre \"Juan/a Perez\" y 3 vidas\n";
    cin >> opcion;
    crear = Utils::validarSiONo(opcion);
    return crear;
}

int Jugador:: pedirVidas() {
    int vidas;
    cout << "\nIngresa la cantidad de vidas (min 1 y max 7): ";
    cin >> vidas;
    return Utils::validarNumero(1,7, vidas);
}

string Jugador:: pedirNombre() {
    string nombre;
    cout << "Ingresa un nombre: ";
    cin >> nombre;
    return Utils::validarPalabra(nombre);
}

void Jugador:: crearUsuario() {
    string nombreOut = pedirNombre();
    int vidasOut = pedirVidas();
    asignarVidas(vidasOut);
    asignarNombre(nombreOut);
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
