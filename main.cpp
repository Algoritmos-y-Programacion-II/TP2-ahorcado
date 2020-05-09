#include "Ahorcado.h"
#include "utils.h"

int main() {
    bool jugarDeNuevo;
    do {
        int vidas = pedirVidas();
        string nombre = pedirNombre();
        string palabraAleatoria = elegirPalabraAleatoria();
        int tamanioPalabra = palabraAleatoria.length();

        Ahorcado ahorcado(vidas, nombre, palabraAleatoria, tamanioPalabra);
        ahorcado.nuevoJuego();

        jugarDeNuevo = ahorcado.deseaJugarDeNuevo();
        if (!jugarDeNuevo)
            ahorcado.mostrarDespedida();

    } while (jugarDeNuevo);

    return 0;
}