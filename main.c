// Proyecto SSL - Generador de expresiones regulares

//Librerias usadas
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>

//FUNCIONES

//Funcion que analiza el uso de parentesis de la ER y segun ello guarda los valores en la matriz "grupos"
void parentesis (char expresion[50], char grupos[10][10]){
    //incializamos variables usadas para recorrer bucles
    int g = 0;
    int i,j = 0;

    //recorremos cada caracter escrito en la expresion regular del usuario
    for (i=0; expresion[i] != '\0'; i++){

        //Si encuentra el inicio de un grupo...
        if (expresion[i] == '('){
            i++; /* Siguiente elemento */
            j = 0;

            //Si no encuentra el cierre del grupo o el fin de la expresion...
            while (expresion[i] != ')' && expresion[i] != '\0')
            {
                //guarda los elementos en la misma fila
                grupos[g][j++] = expresion[i++];
            }
            g++;
        }

        //Si no encuentra el inicio de un grupo...
        else {
            j = 0;
            //Guarda el caracter en una posicion unica
            grupos[g][j] = expresion[i];
            g ++; 
        }
    }
}

//main
int main() {

    //Variables
    const int palabras_max = 10;
    char lenguaje[palabras_max];
	char expresion[50];
    char grupos[10][10];
	char opcion;
	int repetir = 1;
	
	
	//loop principal
	while (repetir){
		printf("Ingrese su expresion regular: ");
		scanf("%s", expresion);

        memset(grupos, 0, sizeof(grupos)); /*Limpia la matriz grupo de contenido basura*/

        //separacion en terminos
        parentesis(expresion, grupos);

        //bucles para 
        //bool para ?
        //bool para |
        //add a lista
        //if lista > numero, break while
        
        //mostrar el resultado
        
    	//opcion de empezar un nuevo bucle?
    	printf("Desea analizar otra expresion regular?\nInserte si/no: ");
    	scanf(" %c", &opcion);
    	if (opcion == 's'){
    		repetir = 1;
		}
		else if (opcion == 'n'){
			repetir = 0;
		}
		else {
			printf("Opcion no disponible\n");
		}
    	
    }
    
    //end
    printf("Gracias por usar nuestro interprete de expresiones regulares :)");
    return 0;
}

// Lo que tengo pensado es adentro de un while que siga recorriendo y que haga lo siguiente:
// * puede ser un contador por cada loop del while. porque va desde 0 hasta inf. tambien se podria hacer un for adentro. para agarrar
// todas las posibles combinaciones. como en: a*b* que no solamente nos tire un vacio y despues ab. sino que nos tire. vacio/a/b/ab etc
// obviamente hay que separar en terminos todo. si la expresion es a*b*c. entonces tendriamos que tomarlo como un (a*) + (b*) + (c)
// ya con la separacion de terminos es solamente empezar a poner ifs adentro del loop principal y que los resultados cuando termine el loop
// los deje en una lista. y cuando la lista tenga una longitud de alrededor de 5/10 expresiones. se corte el loop y muestre el resultado