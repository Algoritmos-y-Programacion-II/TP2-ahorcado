//
// Created by Valentina on 8/5/2020.
//

#include "Ahorcado.h"
// ------------------------------ METODOS PUBLICOS ----------------------------------//
// Constructor
Ahorcado:: Ahorcado() : palabraAAdivinar(0),
                        palabraSecreta(0) {
    estadoJuego = NO_EMPEZO_JUEGO;
}

void Ahorcado:: asignarJugador(Jugador jugadorOut) {
    jugador = jugadorOut;
}

void Ahorcado:: asignarPalabraSecreta(int tamanioOut) {
    string palabraSecretaNueva;
    for (int i = 0; i < tamanioOut; i++) {
        palabraSecretaNueva += "_";
    }
    palabraSecreta.asignarPalabra(palabraSecretaNueva);
}

void Ahorcado:: asignarPalabraAAdivinar(string palabra) {
    palabraAAdivinar.asignarPalabra(palabra);
    estadoJuego = EMPEZO_JUEGO;
}

void Ahorcado:: nuevoJuego() {

    string palabraAdivinada;
    actualizarAhorcado();

    while (estadoJuego == EMPEZO_JUEGO && jugador.obtenerVidas() > 0) {

        cout << "Ingresa una letra o palabra: ";
        palabraAdivinada = Utils::obtenerPalabraEnMayusculas();
        palabraAdivinada = Utils::validarPalabra(palabraAdivinada);

        if (palabraAdivinada.length() > 1)
            arriesgar(palabraAdivinada); // Metodo que recibe string

        else
            arriesgar(palabraAdivinada[0]); // Metodo que recibe caracter

        actualizarAhorcado();
    }

    mostrarMensajeGanoOPerdio();
}

bool Ahorcado:: deseaJugarDeNuevo() {
    char opcion;
    bool crear;
    cout << "\nQueres jugar de nuevo? [s/n] ";
    cin >> opcion;
    crear = Utils::validarSiONo(opcion);
    return crear;
}

void Ahorcado:: mostrarMensajeGanoOPerdio() {
    string nombre = jugador.obtenerNombre();
    if (estadoJuego == GANO_JUEGO)  {
        cout << "Esta vez me ganaste " << nombre << "! Ya vas a ver la proxima...\n";
    } else if (estadoJuego == PERDIO_JUEGO) {
        cout << "   ___   _   __  __ ___    _____   _____ ___ \n"
                "  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\\n"
                " | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /\n"
                "  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\\n\n";
        cout << "Que pena " << nombre << ", esta vez perdiste. Quizas la proxima me ganas.\nLa palabra era: ";
        palabraAAdivinar.mostrarCaracteres();
        cout << "\n";
    }
}

void Ahorcado:: mostrarDespedida() {
    cout << "\nGracias por haber jugado al ahorcado "
         << jugador.obtenerNombre() << "!\nNos vemos la proxima :D\n";
}

void Ahorcado:: mostrarCategorias() {

    cout << "\nElegi la tematica de las palabras a adivinar:\n"
            "1. Verduras\n"
            "2. Frutas\n"
            "3. Paises\n"
            "4. Nombres femeninos\n"
            "5. Nombres masculinos\n"
            "6. Colores\n";
}

void Ahorcado:: mostrarInstrucciones() {
    cout << "\n\n    _   _  _  ___  ___  ___   _   ___   ___  \n"
            "   /_\\ | || |/ _ \\| _ \\/ __| /_\\ |   \\ / _ \\ \n"
            "  / _ \\| __ | (_) |   / (__ / _ \\| |) | (_) |\n"
            " /_/ \\_\\_||_|\\___/|_|_\\\\___/_/ \\_\\___/ \\___/ \n\n";
    cout << "COMO JUGAR:\n"
            "            1. Decida si desea o no crear un usuario con su nombre\n"
            "            2. Elija la categoria a la cual pertenecera la palabra a adivinar\n"
            "            3. Intente adivinar la palabra antes de quedarse sin vidas (tendra 7)\n"
            "               Puede arriesgar una letra o toda la palabra\n"
            "               Si la letra no esta en la palabra PERDERA UNA vida\n"
            "               Si la palabra no es correcta PERDERA DOS vidas\n"
            "               Buena suerte!\n";
}

// ------------------------------ METODOS PRIVADOS ----------------------------------//

void Ahorcado:: arriesgar(char caracter) {
    string palabraAux;

    if (palabraAAdivinar.checkCaracterEnPalabra(caracter)) {
        for (int i = 0; i < palabraAAdivinar.obtenerTamanio(); i++) {
            if (caracter == palabraAAdivinar.obtenerElemento(i))
                palabraSecreta.insertarCaracter(caracter, i);
            }
        if (palabraSecreta.obtenerPalabra() == palabraAAdivinar.obtenerPalabra())
            estadoJuego = GANO_JUEGO;
    }
    else {
        jugador.quitarVidas(1);

        if (jugador.obtenerVidas() <= 0)
            estadoJuego = PERDIO_JUEGO;
    }
}

void Ahorcado:: arriesgar(string palabra) {

    if (palabraAAdivinar.obtenerPalabra() == palabra) {
        palabraSecreta.asignarPalabra(palabra);
        estadoJuego = GANO_JUEGO;
    }

    else {
        jugador.quitarVidas(2);

        if (jugador.obtenerVidas() <= 0)
            estadoJuego = PERDIO_JUEGO;
    }
}

void Ahorcado:: actualizarAhorcado() {
    mostrarDibujoAhorcado();
    cout << "             ";
    palabraSecreta.mostrarCaracteres();
    cout << "\n+==================================+\n\n";
}

void Ahorcado:: mostrarDibujoAhorcado() {

    if (jugador.obtenerVidas() > 0)
        cout << "\nTe quedan " << jugador.obtenerVidas() << " vidas\n";

    switch (jugador.obtenerVidas()) {
        case 7:
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
        case 6:
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
        case 5:
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
        case 4:
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
        case 3:
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
        case 2:
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
        case 1:
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
        case 0:
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