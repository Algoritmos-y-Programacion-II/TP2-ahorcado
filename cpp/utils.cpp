//
// Created by Valentina on 8/5/2020.
//

#include "headers/utils.h"
#include <ctime>
#include <regex>

int validarNumero(int min, int max, int num) {
    while (num < min || num > max) {
        cout << "El numero esta fuera del rango pedido. Reingresa: ";
        cin >> num;
    }
    return num;
}

string validarPalabra(string palabra) {
    regex string("[A-Za-z]+");
    while (!regex_match(palabra, string)) {
        cout << "La palabra ingresada no es valida. Solo puede contener letras minusculas o mayusculas. "
                "Reingresa: ";
        cin >> palabra;
    }
    return palabra;
}

string obtenerPalabraEnMayusculas() {
    string palabra, palabraEnMayusculas;
    cin >> palabra;
    for (int i = 0; i < palabra.length(); i++){
        palabraEnMayusculas += toupper(palabra[i]);
    }
    return palabraEnMayusculas;
}

int numeroRandom(int min, int max) {
    srand(time(NULL));
    return (min + rand() % (max));
}

string elegirPalabraAleatoriaSegunCategoria() {

    cout << "\nElegi la tematica de las palabras a adivinar:\n"
            "1. Verduras\n"
            "2. Frutas\n"
            "3. Paises\n"
            "4. Nombres femeninos\n"
            "5. Nombres masculinos\n";

    int opcion, random = numeroRandom(0, CANT_PALABRAS);
    string palabra;
    cin >> opcion;

    switch (validarNumero(1, 5, opcion)) {

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
    }
    return palabra;
}