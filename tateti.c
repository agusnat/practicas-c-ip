#include <stdio.h>
#include <stdlib.h>

int main() {
    // declaro variables
    int jugadorTurno = 0, movimientos = 10, posicion, tabla[3][3], contador = 1, x, y;

    // inicializo el arreglo
    for(x = 0; x < 3; x++) {
        for(y = 0; y < 3; y++) {
            tabla[x][y] = contador;
            // contador para asignar un numero entre 1 y 9 a cada casillero
            contador++;
        }
    }

    // comienzo los turnos
    while(movimientos != 0) {
        // limpio la consola
        system("cls");

        // muestro el tablero
        printf("---------------\n");

        for(x = 0; x < 3; x++) {
            for(y = 0; y < 3; y++) {
                int valor = tabla[x][y];
                char celda;
                // convierto el entero a char
                celda = valor + '0';

                if(valor == -1) {
                    celda = 'X';
                } else if(valor == 0) {
                    celda = 'O';
                }
                printf("| %c |", celda);
            }
            printf("\n---------------\n");
        }

        // si queda un movimiento terminar el juego
        if(movimientos == 1) {
            printf("Termino el juego!");
            break;
        }
        // le pregunto a el jugador que ingrese posicion
        printf("\nJugador #%d (Ingrese posicion 1-9): ", jugadorTurno + 1);
        scanf("%d", &posicion);

        for(x = 0; x < 3; x++) {
            for(y = 0; y < 3; y++){
                // chequeo si la posicion es valida comparando el numero de casillero con el digito ingresado
                if(tabla[x][y] == posicion) {
                    // multiplico por -1 para invertir el signo y corroborar despues que la posicion es del jugador 1 o 2
                    tabla[x][y] = jugadorTurno * -1;

                    // cambio el turno del jugador
                    jugadorTurno = !jugadorTurno;

                    // resto un movimiento
                    movimientos--;
                }
            }
        }
    }
    return 0;
}
