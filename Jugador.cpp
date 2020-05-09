//
// Created by Valentina on 8/5/2020.
//

#include "Jugador.h"
using namespace std;
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
    cout << "¿Queres crear un usuario y elegir la cantidad de vidas? [s/n]\n"
            "(De lo contrario se te asignara un nombre y una cantidad de vidas predeterminadas)\n";
    cin >> opcion;
    return opcion == 's';
}

int Jugador:: pedirVidas() {
    int vidas;
    cout << "\nIngrese la cantidad de vidas que desea: ";
    cin >> vidas;
    return vidas;
}

string Jugador:: pedirNombre() {
    string nombre;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    return nombre;
}

void Jugador:: crearUsuario() {
    int vidasOut = pedirVidas();
    string nombreOut = pedirNombre();
    asignarVidas(vidasOut);
    asignarNombre(nombreOut);
}

void Jugador:: asignarVidas(int vidasOut) {
    vidas = vidasOut;
}

void Jugador:: asignarNombre(string nombreOut) {
    nombre = nombreOut;
}

void Jugador:: quitarVidas(int vidasASacar) {
    vidas -= vidasASacar;
}