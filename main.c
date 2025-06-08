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

void Interpretar_Expresion(char lista[2][100]) {

    // Lista final y lista temporal con sus respectivas posiciones
    char lista_final[3][100];
    int posicion_final = 0;
    char expresion_temp[100];
    int posicion_temp = 0;

    // Variables para la lista
    int linea = 0;
    int columna = 0;
    int repetir = 1;

    while (repetir) {

        // Cuando detecte el terminador que se pare el bucle
        if (lista[linea][columna] == '\0'){

            break;
        }

        // Cuando detecta que hay un espacio en la lista cambia la polaridad de la linea, osea de 1 pasa a 0 y de 0 a 1
        if (lista[linea][columna] == ' '){

            linea = !linea;
        }
        
        // Loop para correr la lista con parentesis o sin parentesis hasta que encuentre un espacio
        for (int i = 0; lista[linea][columna] != '\0' || lista[linea][columna] != ' '; i++) {
            
            // Adentro checkea cada operador, y si no es ninguno, solamente guarda la letra en una expresion temporal

            // Estrella, que el resultado sea solamente los primeros 3 resultados de una expresion, o se hace muy largo
            if (lista[linea][columna] = '*'){
                
                //Manda a la lista, una en cada linea, la operacion terminada
                for (int i = 0; i > 3; i++) {

                    lista_final[i][posicion_final] = expresion_temp;
                }
                // Sumarle 1 a la posicion y despues dejar la expresion temporal en blanco
                posicion_final++;
                memset(expresion_temp, 0, sizeof(expresion_temp));
            }
            
            // Guardado de el char en la expresion temporal
            expresion_temp[posicion_temp++] = lista[linea][columna];

        }   
    }

}


int main() {

    // Test de la funcion
    char expresiones[50];
    char lista_separada[2][100];
    char lista_terminada[1][100];

    printf("Ingrese su expresion regular: ");
    scanf("%s", expresiones);

    Separar_Terminos(expresiones, lista_separada);

    printf("Con parentesis: %s\n", lista_separada[0]);
    printf("Sin parentesis: %s\n", lista_separada[1]);

    return 0;
}
