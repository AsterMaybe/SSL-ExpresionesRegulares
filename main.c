#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Variables

// ----------------------------------------------------------------------------------------

// Constantes para los tamaños
#define estadosMaximos 21  
#define simbolosMaximos 10
#define cadenaMaxima 100

// Variables globales para definir el AFD
char alfabeto[simbolosMaximos];
int numSimbolos;

int tablaTransicion[estadosMaximos][simbolosMaximos];
int estadoInicial;
int estadosFinales[estadosMaximos];
int numEstados, numEstadosFinales;
int estadoVacio;  // Estado vacio al que se dirige si no hay transicion definida

// ----------------------------------------------------------------------------------------

// funcion que devuelve el indice de un simbolo en el alfabeto
int indiceSimbolo(char simbolo) {
    for (int i = 0; i < numSimbolos; i++) {
        if (alfabeto[i] == simbolo) {
            return i;
        }
    }
    return -1; 

}

// funcion que verifica si un estado es final
int esEstadoFinal(int estado) {
    for (int i = 0; i < numEstadosFinales; i++) {
        if (estado == estadosFinales[i]) {
            return 1;
        }
    }
    return 0;
}

// Datos del grupo
void mostrarDatosGrupo() {
    printf("Autores: Agustin Chaumont, Gaston fernandez, Ezequiel Mautino, Pablo burgos, Ignacio Diaz Vicencio, Brenda Beldarrein\n");
    printf("Tema: Automata Finito Determinista (AFD)\n");
}

// Define los componentes del AFD
void definirAFD() {

    // se define el alfabeto
    printf("Ingrese la cantidad de simbolos del alfabeto: ");
    scanf("%d", &numSimbolos);

    printf("Ingrese los simbolos del alfabeto separados por espacio:\n");
    for (int i = 0; i < numSimbolos; i++) {
        scanf(" %c", &alfabeto[i]);
    }

    // Definir estados (sin contar el vacío)
    printf("Ingrese la cantidad de estados: ");
    scanf("%d", &numEstados);

    // asignar el estado vacio como el siguiente disponible
    estadoVacio = numEstados;
    printf("Se agregará automáticamente un estado vacío como estado %d.\n", estadoVacio);

    // definir estado inicial
    printf("Ingrese el estado inicial (entre 0 y %d): ", numEstados - 1);
    scanf("%d", &estadoInicial);

    // definir estados finales
    printf("Ingrese la cantidad de estados finales: ");
    scanf("%d", &numEstadosFinales);

    printf("Ingrese los estados finales (números entre 0 y %d):\n", numEstados - 1);
    for (int i = 0; i < numEstadosFinales; i++) {
        scanf("%d", &estadosFinales[i]);
    }

    // definir la tabla de transicion
    printf("\nDefina la tabla de transicion (use - para indicar que no hay transicion):\n");
    for (int i = 0; i < numEstados; i++) {
        for (int j = 0; j < numSimbolos; j++) {
            char entrada[10];
            printf("Desde estado %d con '%c' va a estado: ", i, alfabeto[j]);
            scanf("%s", entrada);

            if (entrada[0] == '-') {
                // Si el usuario ingresa '-', se asigna el estado vacio
                tablaTransicion[i][j] = estadoVacio;
            } else {
                // Si no, se convierte la string a int
                tablaTransicion[i][j] = atoi(entrada);
            }
        }
    }

    // Todas las transiciones del estado vacio se hacen vacio
    for (int j = 0; j < numSimbolos; j++) {
        tablaTransicion[estadoVacio][j] = estadoVacio;
    }

    // +1 al numero de estados porque para vacio necesita uno mas
    numEstados++;
}

// procesa una cadena ingresada 
void procesarCadena(char cadena[]) {
    int estadoActual = estadoInicial;
    int simboloIndex;

    // Recorrer cada simbolo de la cadena
    for (int i = 0; i < strlen(cadena); i++) {
        simboloIndex = indiceSimbolo(cadena[i]);

        // Si el simbolo no pertenece al alfabeto, se rechaza
        if (simboloIndex == -1) {
            printf("Cadena rechazada: símbolo '%c' no pertenece al alfabeto.\n", cadena[i]);
            return;
        }

        // Mover al siguiente estado segun la tabla de transicion
        estadoActual = tablaTransicion[estadoActual][simboloIndex];
    }

    // Verificar si el estado final alcanzado es aceptado
    if (esEstadoFinal(estadoActual)) {
        printf("Cadena aceptada.\n");
    } else {
        printf("Cadena rechazada.\n");
    }
}

// main
int main() {
    char cadena[cadenaMaxima];

    mostrarDatosGrupo();

    definirAFD();

    // while para verificar multiples cadenas hasta que el usuario escriba salir
    while (1) {
        printf("\nIngrese una cadena para verificar (o escriba 'salir' para terminar): ");
        scanf("%s", cadena);
        if (strcmp(cadena, "salir") == 0) {
            break;
        }
        procesarCadena(cadena);
    }

    printf("Programa finalizado.\n");
    return 0;
}
