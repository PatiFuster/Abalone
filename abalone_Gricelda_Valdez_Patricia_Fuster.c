#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionesHumano.h"
#include "funcionesPc.h"
#define negra 'y'
#define blanca 'x'
#define true 1
#define false 0

//En "tablero.h" se declaro variables globales

//Declaracion de funciones

int quien_inicia(int a);
void color_canica(int a);
void imprimir_tablero();
int fin_juego();
void resultados();

//Definicion de funciones

/*Indica quien inicia la partida
*Parametros:
*a-->eleccion del usuario
*Retorno:
*b--> 1 si es usuario y 0 si es computadora
*/
int quien_inicia(int a){
	int b=0, c;

	switch(a){
		case 1:{
			b=1;
			printf("Inicia humano\n");
			break;
		}
		case 2:{
			printf("Inicia pc\n");
			break;
		}
		case 3:{
			srand(time(NULL));
			c=rand()%(2-1+1)+1; 	//(LIMSUP-LIMINF+1) + LIMINF
			if(c==1){
				b=1;
				printf("Inicia humano\n");
			}else{
				printf("Inicia pc\n");
			}
			break;
		}
	}
	return b;
}


/*Asigna color de canica para cada jugador (humano-pc)
*Parametros:
*a-->eleccion del usuario
*Retorno:
*Ninguno
 */
void color_canica(int a){
	char b;
	switch (a){
		case 1:{
			canica_humano=negra;
			canica_pc=blanca;
			break;
		}
		case 2:{
			canica_humano=blanca;
			canica_pc=negra;
			break;
		}
		case 3:{
			srand(time(NULL));
			b=rand()%(2-1+1)+1; 	//(LIMSUP-LIMINF+1) + LIMINF
			if(b==1){
				canica_humano=negra;
				canica_pc=blanca;
			}else{
				canica_humano=blanca;
				canica_pc=negra;
			}
			break;
		}
	}
}

/*Imprime matriz del abalone
 * Parametros:
 * Ninguno
 * Retorno:
 * Ninguno
 */
void imprimir_tablero(){
	int i, j;
	for(i=0; i<9; i++){
		for(j=0; j<17; j++){
			if(abalone[i][j]=='1'){ //Imprime espacio en blanco cuando encuentra
				printf("  ");		//una posicion que "no existe"
			}else{
				printf(" %c", abalone[i][j] );
			}
		}
		printf("\n");
		printf("\n");
	}
}

/*Verifica si uno de los jugadores saco 6 canicas del enemigo fuera del tablero
 *Parametros:
 *Ninguno
 *Retorno:
 *Ninguno
 */
int fin_juego(){
	if(cHum==6 || cPc==6){
		return true;
	}else{
		return false;
	}
}

/*Imprime resultados de la partida jugada
 * Parametros:
 * Ninguno
 * Retorno:
 * Ninguno
 */
void resultados(){
	if(contador_humano>contador_pc || cHum==6){
		printf("\nHa ganado el usuario");
	}
	if(contador_pc>contador_humano || cPc==6){
		printf("\nHa ganado la computadora");
	}
	if(	contador_humano==contador_pc){
		printf("\nEs un empate");
	}
}
int main(void){
		printf("* * * B I E N V E N I D O    A   A B A L O N E * * *\n");
		printf("\n \n \n");
		printf("Elija quien inicia la partida\n\n");	//Eleccion o sorteo del turno
		printf("1. Humano\n2. PC\n3. Aleatorio\n");
		int eleccion, turno;
		printf("\nNumero:\t");
		scanf("%d", &eleccion);
		printf("\n");
		turno=quien_inicia(eleccion);

		printf("\n \n \n");
		printf("Elija color de canica\n\n");
		printf("1. Negra\n2. Blanca\n3. Aleatorio\n");	//Eleccion o sorteo del color de canica
		printf("\nNumero:\t");
		scanf("%d", &eleccion);
		printf("\n");
		color_canica(eleccion);


		printf("\n\nDefina una cantidad maxima de jugadas\n");
		int max, cant_max=0; 	//Se define cantidad maxima de jugadas
		printf("\nNumero:\t");
		scanf("%d", &max);
		printf("\n\n");
		imprimir_tablero();
		printf("\n\n\n");
		if(max<=0){
			while(fin_juego()){
				if(turno==1){
					printf("\n");
					jugada_humano();
					printf("\n\n");
					imprimir_tablero();
					printf("\n");
					turno=0;
				}
				if(turno==0){
					printf("\n");
					jugada_pc();
					printf("\n\n");
					imprimir_tablero();
					printf("\n");
					turno=1;
				}
			}
		}else{
			while(cant_max<=max || fin_juego()==false){
				//if(turno==1){
					printf("\n");
					jugada_humano();
					printf("\n\n");
					imprimir_tablero();
					printf("\n");
					turno=0;
				/*}
				if(turno==0){
					printf("\n");
					jugada_pc();
					printf("\n\n");
					imprimir_tablero();
					printf("\n");
					turno=1;
				}*/
				cant_max++;
			}
		}
		//resultados();
		return 0;
}
