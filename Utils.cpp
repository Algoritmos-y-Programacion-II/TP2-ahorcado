//
// Created by Valentina on 17/5/2020.
//

#include "Utils.h"

void Utils:: validarNumero(int min, int max, int &num) {
    while (num < min || num > max) {
        cout << "El numero esta fuera del rango pedido. Reingresa: ";
        cin >> num;
    }
}

void Utils:: validarPalabra(string &palabra) {
    regex string("[A-Za-z]+");
    while (!regex_match(palabra, string)) {
        cout << "La palabra ingresada no es valida. Solo puede contener letras minusculas o mayusculas. "
                "Reingresa: ";
        cin >> palabra;
    }
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

int Utils::  numeroRandom(int min, int max) {
    srand(time(NULL));
    return (min + rand() % (max));
}
