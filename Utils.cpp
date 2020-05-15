//
// Created by Valentina on 8/5/2020.
//

#include "Utils.h"

// ------------------------------ METODOS PUBLICOS ----------------------------------//
int Utils:: validarNumero(int min, int max, int num) {
    while (num < min || num > max) {
        cout << "El numero esta fuera del rango pedido. Reingresa: ";
        cin >> num;
    }
    return num;
}

string Utils::  validarPalabra(string palabra) {
    regex string("[A-Za-z]+");
    while (!regex_match(palabra, string)) {
        cout << "La palabra ingresada no es valida. Solo puede contener letras minusculas o mayusculas. "
                "Reingresa: ";
        cin >> palabra;
    }
    return palabra;
}

bool Utils:: validarSiONo(char opcion) {
    while ('s' != opcion && 'S' != opcion && 'n' != opcion && 'N' != opcion) {
        cout << "El caracter ingresado no es valido. Reingresa [s/n]: ";
        cin >> opcion;
    }
    return ('s' == opcion || 'S' == opcion) ;
}

string Utils::  obtenerPalabraEnMayusculas() {
    string palabra, palabraEnMayusculas;
    cin >> palabra;
    for (int i = 0; i < palabra.length(); i++){
        palabraEnMayusculas += toupper(palabra[i]);
    }
    return palabraEnMayusculas;
}

string  Utils:: elegirPalabraAleatoriaSegunCategoria() {

    int opcion, random = numeroRandom(0, CANT_PALABRAS);
    string palabra;
    cin >> opcion;

    switch (validarNumero(1, 6, opcion)) {

        case VERDURAS:
            palabra = PALABRAS_VERDURAS[random];
            break;

        case FRUTAS:
            palabra = PALABRAS_FRUTAS[random];
            break;

        case PAISES:
            palabra = PALABRAS_PAISES[random];
            break;

        case NOMBRES_FEMENINOS:
            palabra = PALABRAS_NOMBRES_F[random];
            break;

        case NOMBRES_MASCULINOS:
            palabra = PALABRAS_NOMBRES_M[random];
            break;

        case COLORES:
            palabra = PALABRAS_COLORES[random];
            break;
    }
    return palabra;
}

// ------------------------------ METODOS PRIVADOS ----------------------------------//

int Utils::  numeroRandom(int min, int max) {
    srand(time(NULL));
    return (min + rand() % (max));
}
