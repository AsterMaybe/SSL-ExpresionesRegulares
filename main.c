// Librerias
#include <stdio.h>
#include <string.h>

// Funcion para separar en terminos las expresiones
void Separar_Terminos(char expresion[50], char listas[2][100]) {
    int parentesis = 0;
    int no_parentesis = 1;
    int columna = 0;

    // Recorrer la expresion dada
    for (int i = 0; expresion[i] != '\0'; i++) {

        //Detecta cuando uno de los caracteres es un (
        if (expresion[i] == '('  && expresion[i] != '\0') { 
            
            // Empieza a guardar todo hasta que el parentesis se cierre en la linea 0, y guarda vacios en la linea 1
            while (expresion[i] != ')') {

                listas[parentesis][columna] = expresion[i];
                listas[no_parentesis][columna] = ' ';
                columna++;
                i++;
            }
            
            // Añade un parentesis al final de la expresion entre parentesis
            listas[parentesis][columna] = ')';
            listas[no_parentesis][columna] = ' ';
            columna++;

            // Si despues del parentesis hay un algun *+? los guarda en la lista de parentesis
            if (strchr("*+?", expresion[i + 1])){
                i++;
                listas[parentesis][columna] = expresion[i];
                listas[no_parentesis][columna] = ' ';
                columna++;
            }
        
        }
        //Cuando no hay parentesis guarda en la linea sin parentesis y vacios en la linea parentesis
        else {
            listas[no_parentesis][columna] = expresion[i];
            listas[parentesis][columna] = ' ';
            columna++;
        }
    }

    // Añade un cierre cuando termina de separar y guardar la expresion
    listas[parentesis][columna] = '\0';
    listas[no_parentesis][columna] = '\0';
}


int main() {
    
    // Test de la funcion
    char expresiones[50];
    char lista[2][100];

    printf("Ingrese su expresion regular: ");
    scanf("%s", expresiones);

    Separar_Terminos(expresiones, lista);

    printf("Con parentesis: %s\n", lista[0]);
    printf("Sin parentesis: %s\n", lista[1]);

    return 0;
}
