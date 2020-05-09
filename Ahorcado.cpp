//
// Created by Valentina on 8/5/2020.
//

#include "Ahorcado.h"
// ------------------------------ METODOS PUBLICOS ----------------------------------//
Ahorcado:: Ahorcado(int vidasOut, string nombre, string palabraAleatoria, int tamanioPalabra) : palabraAAdivinar(palabraAleatoria, tamanioPalabra), jugador(vidasOut, nombre) {
    estadoJuego = NO_EMPEZO_JUEGO;
    //jugador = Jugador(vidasOut, nombre);
    intentosFallidos = 0;
    for (int i = 0; i < tamanioPalabra ; i++) {
        palabraSecreta += '_';
    }
}

void Ahorcado:: nuevoJuego() {
    estadoJuego = EMPEZO_JUEGO;
    palabraAAdivinar.mostrarPalabra(); // Para testear
    string palabraAdivinada;
    actualizarAhorcado();
    while (estadoJuego == EMPEZO_JUEGO && jugador.obtenerVidas() > 0) {
        cout << "Ingresa una letra o palabra: ";
        cin >> palabraAdivinada;
        if (palabraAdivinada.length() > 1)
            arriesgar(palabraAdivinada);
        else arriesgar(palabraAdivinada[0]);
    }
    if (jugador.obtenerVidas() <= 0)
        estadoJuego = PERDIO_JUEGO;
    mostrarMensajeGanoOPerdio();
}

int Ahorcado:: obtenerEstadoJuego() {
    return estadoJuego;
}

bool Ahorcado:: deseaJugarDeNuevo() {
    char si = 's', opcion;
    cout << "¿Desea volver a jugar? [s/n] ";
    cin >> opcion;
    return si == opcion;
}

void Ahorcado:: mostrarMensajeGanoOPerdio() {
    string nombre = jugador.obtenerNombre();
    if (estadoJuego == GANO_JUEGO)  {
        cout << "Muy bien " << nombre << ", ganaste!\n";
    } else if (estadoJuego == PERDIO_JUEGO) {
        cout << "Lo siento " << nombre << ", esta vez perdiste :(\nLa palabra era: ";
        palabraAAdivinar.mostrarPalabra();
    }
}

void Ahorcado:: mostrarDespedida() {
    cout << "Gracias por haber jugado al ahorcado "
         << jugador.obtenerNombre() << "!\nNos vemos la próxima :)\n";
}

// ------------------------------ METODOS PRIVADOS ----------------------------------//

void Ahorcado:: arriesgar(char caracter) {
    bool coincidio = palabraAAdivinar.checkCaracterEnPalabra(caracter);
    string palabraAux;

    if (coincidio) {
        palabraAux = palabraAAdivinar.obtenerPalabra();
        for (int i = 0; i < palabraAAdivinar.obtenerTamanio(); i++) {
            if (caracter == palabraAux[i])
                palabraSecreta[i] = caracter;
            }
        if (palabraSecreta == palabraAux)
            estadoJuego = GANO_JUEGO;
        actualizarAhorcado();
    } else {
        intentosFallidos++;
        jugador.quitarVidas(1);
        cout << "Ooops! Incorrecto\nLe quedan " << jugador.obtenerVidas() << " vidas\n";
        actualizarAhorcado();
    }
}

void Ahorcado:: arriesgar(string palabra) {
    if (palabraAAdivinar.obtenerPalabra() == palabra) {
        palabraSecreta = palabra;
        actualizarAhorcado();
        estadoJuego = GANO_JUEGO;
    } else {
        intentosFallidos++;
        jugador.quitarVidas(2);
        cout << "Ooops! Incorrecto\nLe quedan " << jugador.obtenerVidas() << " vidas\n";
        actualizarAhorcado();
    }
}

void Ahorcado:: actualizarAhorcado() {
    mostrarDibujoAhorcado(intentosFallidos);
    cout << "             " << palabraSecreta;
    cout << "\n+==================================+\n\n";
}

void Ahorcado:: mostrarDibujoAhorcado(int fallos) {

    switch (fallos) {
        case 0:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 1:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 2:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 3:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |        |                 |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 4:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|                 |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 5:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|\\                |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 6:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|\\                |\n"
                    "|       |        |                 |\n"
                    "|       |       /                  |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 7:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|\\                |\n"
                    "|       |        |                 |\n"
                    "|       |       / \\                |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;

    }
}