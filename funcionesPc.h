#ifndef FUNCIONESPC_H_
#define FUNCIONESPC_H_
#include "tablero.h"
#include <time.h>

//Declaracion de funciones

void juagda_pc();

/*funciones para cada movimientos que quiera realizar la computadora*/

/*void en_linea_pc();
void de_lado_pc();
void simple_pc();*/

//Definicion de funciones

/*void*/ int jugada_pc(){
	int b;
	srand(time(NULL)); //elige en forma aleatoria el tipo de jugada a realizar
	b=rand()%3 +1;
	/*switch (b){
		case 1:{
			simple_pc();
			break;
		}
		case 2:{
			de_lado_pc(); 	//la funcion no esta definida, solo es una idea
			break;
		}
		case 3:{
			en_linea_pc();
			break;
		}
	}*/
	return b; //solo le puse que retorne este valor para que la variable b se "use" de esa manera
}

/*la idea con los movimientos de la computadora es que en forma aleatoria elija
 * posiciones de origen y destino, cantidad de fichas a mover y que llame
 * a las funciones correspondientes
 */

#endif /* FUNCIONESPC_H_ */
