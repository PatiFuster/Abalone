
#ifndef TABLERO_H_
#define TABLERO_H_

//Variables globales

/*Elementos de la matriz
 * y: negra
 * x: blanca
 * 0:espacio vacio
 * 1:espacio inexistente
 */
char abalone[9][17]={
	'1','1','1','1','x','1','x','1','0','1','y','1','y','1','1','1','1',
	'1','1','1','x','1','x','1','x','1','y','1','y','1','y','1','1','1',
	'1','1','0','1','x','1','x','1','0','1','y','1','y','1','0','1','1',	//Matriz del abalone
	'1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','0','1',
	'0','1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','0',
	'1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','0','1',
	'1','1','0','1','y','1','y','1','0','1','x','1','x','1','0','1','1',
	'1','1','1','y','1','y','1','y','1','x','1','x','1','x','1','1','1',
	'1','1','1','1','y','1','y','1','0','1','x','1','x','1','1','1','1',
};

/*Contador de canicas en el tablero para humano y pc respectivamente*/
int contador_humano=14, contador_pc=14;

/*contador de canicas que salen del tablero para humano y pc respectivamente*/
int cHum=0, cPc=0;

/*canica para cada jugador*/
char canica_humano, canica_pc;

#endif /* TABLERO_H_ */
