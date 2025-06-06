// Proyecto SSL - Generador de expresiones regulares

//Librerias usadas
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>
using namespace std;

// funciones





// main
int main() {

    //Variables
	string expresion;
	string opcion;
	bool repetir = true;
	int palabras_max = 10;
	char lenguaje[palabras_max];
	
	
	//loop principal
	while (repetir){
		cout<<"Ingrese su expresion regular: ";
		cin>>expresion;
        //separacion en terminos
        //bucles para * y +
        //bool para ?
        //bool para |
        //add a lista
        //if lista > numero, break while
        
        //mostrar el resultado
        
    	//opcion de empezar un nuevo bucle?
    	cout<<"Desea analizar otra expresion regular?\nInserte si o no en caso negativo: ";
    	cin>>opcion;
    	if (opcion == "si"){
    		repetir = true;
		}
		else if (opcion == "no"){
			repetir = false;
		}
		else {
			cout<<"Opcion no disponible"<<endl;
		}
    	
    }
    
    //end
    cout<<"Gracias por usar nuestro interprete de expresiones regulares :)"<<endl;
    
    return 0;
}


// Lo que tengo pensado es adentro de un while que siga recorriendo y que haga lo siguiente:
// * puede ser un contador por cada loop del while. porque va desde 0 hasta inf. tambien se podria hacer un for adentro. para agarrar
// todas las posibles combinaciones. como en: a*b* que no solamente nos tire un vacio y despues ab. sino que nos tire. vacio/a/b/ab etc
// obviamente hay que separar en terminos todo. si la expresion es a*b*c. entonces tendriamos que tomarlo como un (a*) + (b*) + (c)
// ya con la separacion de terminos es solamente empezar a poner ifs adentro del loop principal y que los resultados cuando termine el loop
// los deje en una lista. y cuando la lista tenga una longitud de alrededor de 5/10 expresiones. se corte el loop y muestre el resultado