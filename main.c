#include <stdio.h>
#include <string.h>

#define Estados 20
#define Simbolos 10
#define Cadena 100

char alfabeto[Simbolos];
int numSimbolos;

int tablaTransicion[Estados][Simbolos];
int estadoInicial;
int estadosFinales[Estados];
int numEstados, numEstadosFinales;

// Función para obtener el índice de un símbolo en el alfabeto
int indiceSimbolo(char simbolo) {
    for (int i = 0; i < numSimbolos; i++) {
        if (alfabeto[i] == simbolo) return i;
    }
    return -1;
}

int esEstadoFinal(int estado) {
    for (int i = 0; i < numEstadosFinales; i++) {
        if (estado == estadosFinales[i]) return 1;
    }
    return 0;
}

void mostrarDatosGrupo() {
    printf("Autores: Perez - González\n");
    printf("Tema: Autómata Finito Determinista (AFD)\n\n");
}

void definirAFD() {
    printf("Ingrese la cantidad de símbolos del alfabeto: ");
    scanf("%d", &numSimbolos);

    printf("Ingrese los símbolos del alfabeto separados por espacio:\n");
    for (int i = 0; i < numSimbolos; i++) {
        scanf(" %c", &alfabeto[i]);
    }

    printf("Ingrese la cantidad de estados: ");
    scanf("%d", &numEstados);

    printf("Ingrese el estado inicial (número entre 0 y %d): ", numEstados - 1);
    scanf("%d", &estadoInicial);

    printf("Ingrese la cantidad de estados finales: ");
    scanf("%d", &numEstadosFinales);

    printf("Ingrese los estados finales (números entre 0 y %d):\n", numEstados - 1);
    for (int i = 0; i < numEstadosFinales; i++) {
        scanf("%d", &estadosFinales[i]);
    }

    printf("\nDefina la tabla de transición:\n");
    for (int i = 0; i < numEstados; i++) {
        for (int j = 0; j < numSimbolos; j++) {
            printf("Desde estado %d con '%c' va a estado: ", i, alfabeto[j]);
            scanf("%d", &tablaTransicion[i][j]);
        }
    }
}

void procesarCadena(char cadena[]) {
    int estadoActual = estadoInicial;
    int simboloIndex;

    for (int i = 0; i < strlen(cadena); i++) {
        simboloIndex = indiceSimbolo(cadena[i]);
        if (simboloIndex == -1) {
            printf("Cadena rechazada: símbolo '%c' no pertenece al alfabeto.\n", cadena[i]);
            return;
        }
        estadoActual = tablaTransicion[estadoActual][simboloIndex];
    }

    if (esEstadoFinal(estadoActual)) {
        printf("Cadena aceptada.\n");
    } else {
        printf("Cadena rechazada.\n");
    }
}

int main() {
    char cadena[Cadena];

    mostrarDatosGrupo();
    printf("Este programa representa un Autómata Finito Determinista (AFD).\n\n");

    definirAFD();

    while (1) {
        printf("\nIngrese una cadena para verificar (o escriba 'salir' para terminar): ");
        scanf("%s", cadena);
        if (strcmp(cadena, "salir") == 0) break;
        procesarCadena(cadena);
    }

    printf("Programa finalizado.\n");
    return 0;
}
