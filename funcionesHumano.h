
#ifndef FUNCIONESHUMANO_H_
#define FUNCIONESHUMANO_H_
#include "tablero.h"

//Declaracion de funciones

void jugada_humano();

/*funciones para cada movimiento que quiera realizar el usuario*/

void en_linea();
void de_lado();
void simple();



//Definicion de funciones


/*Solicita al usuario que tipo de movimiento quiere realizar en cada turno
 *Parametros:
 *Ninguno
 *Retorno:
 *Ninguno
 */
void jugada_humano(){
	int nro;
	printf("\nSeleccione Tipo de movimiento: ");
	printf("\n1. Simple\n2. De Lado\n3.En Linea");
	scanf("%d", &nro);
	printf("\n\n");
	switch (nro){
		case 1:{
			simple();
			break;
		}
		case 2:{
			de_lado();
			break;
		}
		/*case 3:{
			en_linea();
			break;
		}*/
	}
}


/*Realiza movimiento simple
 *Parametros:
 *Ninguno
 *Retorno:
 *Ninguno
 */

void simple(){
	int fo, co; 	//fo: fila origen, co: columna origen
	int fd, cd;		//fd: fila destino, cd: columna destino
	char aux;
	printf("\nFila y columna origen: ");
 	scanf("%d, %d",&fo, &co);

 	printf("\nFila y columna de destino: ");
 	scanf("%d, %d", &fd, &cd);


   if(abalone[fo][co]==canica_humano && abalone[fd][cd]=='0'){
		//se verifica la adyacencia
			if(fo-1==fd && co-1==cd){
				aux=abalone[fd][cd];
				abalone[fd][cd]=abalone[fo][co];
				abalone[fo][co]=aux;
			}
			if(fo-1==fd && co+1==cd){
				aux=abalone[fd][cd];
				abalone[fd][cd]=abalone[fo][co];
				abalone[fo][co]=aux;
			}
			if(fo+1==fd && co-1==cd){
				aux=abalone[fd][cd];
				abalone[fd][cd]=abalone[fo][co];
				abalone[fo][co]=aux;
			}
			if(fo+1==fd && co+1==cd){
				aux=abalone[fd][cd];
				abalone[fd][cd]=abalone[fo][co];
				abalone[fo][co]=aux;
			}
 		}
 }


/*Realiza movimiento de lado
 *parametros:
 *ninguno
 *retorno:
 *ninguno
 */
void de_lado(){
	int fo, co; 	//fo: fila origen, co: columna origen
	int fd, cd;		//fd: fila destino, cd: columna destino
	char aux; //cantidad de canicas a mover
	int i, k, cant;	 //indices
	printf("\nFila y columna origen, y cantidad a mover: "); //Es importante como se tome el origen y el destino de acuerdo a la direccion
 	scanf("%d, %d, %d",&fo, &co, &cant);					//a la que se quiera mover
 	printf("\nFila y columna de destino: ");
 	scanf("%d, %d", &fd, &cd);

 	/*Origen y destino segun direccion:
 	*arriba-derecha
 			  0	  1   2   3
 		0	|_1_|_0_|_0_|_0_| se debe tomar como origen [1,2]    	--> 0:vacio
 		1	|_x_|_x_|_x_|_1_| se debe tomar como destino [0,3]		--> 1:espacio inexistente
 																	--> x:canica
 	*arriba-izquierda
 		 	  0	  1   2   3
 		0	|_0_|_0_|_0_|_1_| se debe tomar como origen [1,1]
 		1	|_1_|_x_|_x_|_x_| se debe tomar como destino [0,0]

 	*abajo-derecha
 		 	  0	  1   2   3
 		0	|_x_|_x_|_x_|_1_| se debe tomar como origen [0,2]
 		1	|_1_|_0_|_0_|_0_| se debe tomar como destino [1,3]

 	*abajo-izquierda
		 	  0	  1   2   3
 		0	|_1_|_x_|_x_|_x_| se debe tomar como origen [0,1]
 		1	|_0_|_0_|_0_|_1_| se debe tomar como destino [1,0]
	*/
 	if(cant>0 && cant<=3){
 		if(abalone[fo][co]==canica_humano && abalone[fd][cd]=='0'){
 			//se verifica la adyacencia
  			if(fo-1==fd && co+1==cd){ 	//arriba-derecha
 				i=0;
				for(k=0; k<cant; k++){
					//se verifica que las canicas a mover sean del humano y el destino este vacio
					if(abalone[fo][co-i]==canica_humano && abalone[fd][cd-i]=='0'){
						aux=abalone[fo][co-i];
						abalone[fo][co-i]=abalone[fd][cd-i];
						abalone[fd][cd-i]=aux;
						i+=2;
					}
				}
			}
			if(fo-1==fd && co-1==cd){	//arriba-izquierda
 				i=0;
				for(k=0; k<cant; k++){
					if(abalone[fo][co+i]==canica_humano && abalone[fd][cd+i]=='0'){
						aux=abalone[fo][co+i];
						abalone[fo][co+i]=abalone[fd][cd+i];
						abalone[fd][cd+i]=aux;
					}	i+=2;
				}
			}
			if(fo+1==fd && co+1==cd){	//abajo-derecha
 				i=0;
				for(k=0; k<cant; k++){
					if(abalone[fo][co-i]==canica_humano && abalone[fd][cd-i]=='0'){
						aux=abalone[fo][co-i];
						abalone[fo][co-i]=abalone[fd][cd-i];
						abalone[fd][cd-i]=aux;
						i+=2;
					}
				}
			}
			if(fo+1==fd && co-1==cd){ 	//abajo-izquierda
 				i=0;
				for(k=0; k<cant; k++){
					if(abalone[fo][co+i]==canica_humano && abalone[fd][cd+i]=='0'){
						aux=abalone[fo][co+i];
						abalone[fo][co+i]=abalone[fd][cd+i];
						abalone[fd][cd+i]=aux;
						i+=2;
					}
				}
			}

		}
 	}else{
 		printf("\nNo valido");
 		de_lado(); //vuelve a llamar a la funcion en el caso en que la jugada no sea valida
	 }
}

/*Realiza movimientos en linea 		//falta mejorar
 *parametros:
 *ninguno
 *retorno:
 *ninguno
 */

/*

 void en_linea(){
  	int fo, co,f2o,c2o,f3o,c3o; //fo: fila origen, co: columna origen (con subindices)
	int nc, number; //numero de canicas a mover
	int fd, cd,f2d,c2d,f3d,c3d,cD,fD; //fd: fila destino, cd: columna destino
	char aux,aux2,aux3;
	printf("\n Ingrese la cantidad de canicas <puede ser hasta 3> que desee mover");
	scanf("%d", &nc);
	if(nc>1 && nc<=3 ){		//hasta 3 canicas se pueden mover con este movimiento
		switch (nc){
			case 2:{
				printf("¿REALIZA MOVIMIENTO O EMPUJE? Presione 1 para mov y 2 para empuje");
			  	scanf("%d",&number);
			  	if(number==1 ){
			  		printf("\nFila y columna origen de la Primera Canica: ");
			 		scanf("%d, %d",&fo, &co);
			 		printf("\nFila y columna de destino de la Primera Canica: ");
			 		scanf("%d, %d", &fd, &cd);//

			 		printf("\nFila y columna origen de la Segunda Canica: ");
			 		scanf("%d, %d",&f2o, &c2o);
			 		printf("\nFila y columna de destino de la Segunda Canica: ");
			 		scanf("%d, %d", &f2d, &c2d);//

			 		printf("\nFila y columna de Destino Final: ");
			 		scanf("%d, %d", &f3d, &c3d);

			 		if(abalone[fo][co]==canica_humano  && abalone[f2o][c2o]==canica_humano && abalone[f3d][c3d]=='0'){
						if(f2o==fo-1 && ( (f3d==f2o-1) || (f3d==fo-1) ){
						  	if ( (c2o-co==1)&& (c3d-c2o==1) ) {
						  		aux=canica_humano;
								abalone[fo][co]=='0';
								abalone[f3d][c3d]==aux;
							}
							if ( ( co-c2o==1 ) && (c3d-co==1 ) ){
								aux=canica_humano;
								abalone[f2o][c2o]=='0';
								abalone[f3d][c3d]==aux;
							}
						}
						if (f2o==fo+1 && ( (f3d==f2o+1) || (f3d==fo+1) ){
							if ( (c2o-co==1)&& (c3d-c2o==1) ) {
						  		aux=canica_humano;
								abalone[fo][co]=='0';
								abalone[f3d][c3d]==aux;
							}
							if ( ( co-c2o==1 ) && (c3d-co==1 ) ){
								aux=canica_humano;
								abalone[f2o][c2o]=='0';
								abalone[f3d][c3d]==aux;
							}
						}
					}
				}

				if (number==2){	// empuje movimiento
					printf("\nFila y columna origen de la Primera Canica: ");
			 		scanf("%d, %d",&fo, &co);
			 		printf("\nFila y columna de destino de la Primera Canica: ");
			 		scanf("%d, %d", &fd, &cd);//

			 		printf("\nFila y columna origen de la Segunda Canica: ");
			 		scanf("%d, %d",&f2o, &c2o);
			 		printf("\nFila y columna de destino de la Segunda Canica: ");
			 		scanf("%d, %d", &f2d, &c2d);//


			 		printf("\nFila y columna origen de la Tercera Canica(TIENE QUE SER DEL OPONENTE): ");
			 		scanf("%d, %d",&f3o, &c3o);
			 		printf("\nFila y columna de destino de la Tercera Canica(TIENE QUE SER DEL OPONENTE): ");
			 		scanf("%d, %d", &f3d, &c3d);//

					if(abalone[fo][co]==canica_humano  && abalone[f2o][c2o]==canica_humano && abalone[f3O][c3O]==canica_pc){

						//CASO DE EMPUJE DENTRO DEL TABLERO
						if( abalone[f3O-1][c3O+1]=='0' || abalone[f3O-1][c3O-1]=='0' ||  abalone[f3O+1][c3O+1]=='0' || abalone[f3O+1][c3O-1]=='0' ){
							printf("\nFila y columna de Destino Final: ");
			 				scanf("%d, %d", &fD, &cD);
							// ADYACENCIA VERIFICACION
							if(f2o==fo-1 && ( (f3d==f2o-1) || (f3o==fo-1) ){
						  		if ( (c2o-co==1)&& (c3o-c2o==1) ){
						  			aux==canica_pc;
									abalone[fo][co]=='0';
									abalone[fD][cD]==aux;
								}
								if ( ( co-c2o==1 ) && (c3o-co==1 ) ){
									aux==canica_pc;
									abalone[fo][co]=='0';
									abalone[fD][cD]==aux;
								}
							}
							if (f2o==fo+1 && ( (f3d==f2o+1) || (f3o==fo+1) ){
								if ( (c2o-co==1)&& (c3o-c2o==1) ){
						  			aux==canica_pc;
									abalone[fo][co]=='0';
									abalone[fD][cD]==aux;
								}
								if ( ( co-c2o==1 ) && (c3d-co==1 ) ){
									aux==canica_pc;
									abalone[fo][co]=='0';
									abalone[fD][cD]==aux;
								}
							}
						}
					}
				}

				// CASO EMPUJE FUERA DEL TABLERO
				if( abalone[f3o-1][c3o+1]=='1' || abalone[f3o-1][c3o-1]=='1' ||  abalone[f3o+1][c3o+1]=='1' || abalone[f3o+1][c3o-1]=='1' ){
					if(f2o==fo-1 && ( (f3d==f2o-1) || (f3o==fo-1) )	{
						if ( (c2o-co==1)&& (c3o-c2o==1) ){
						  	abalone[f3O][c3O]==canica_humano;
							abalone[fo][co]=='0';
							cHum++;

						}
						if ( ( co-c2o==1 ) && (c3o-co==1 ) ){
							abalone[f3O][c3O]==canica_humano;
							abalone[fo][co]=='0';
							cHum++;
						}
					}
					if (f2o==fo+1 && ( (f3d==f2o+1) || (f3o==fo+1) ){
						if ( (c2o-co==1)&& (c3o-c2o==1) ){
						  	abalone[f3O][c3O]==canica_humano;
							abalone[fo][co]=='0';
							cHum++;
						}
						if ( ( co-c2o==1 ) && (c3d-co==1 ) ){
							abalone[f3O][c3O]==canica_humano;
							abalone[fo][co]=='0';
							cHum++;
						}
					}
				}
			break;
			}
		}
	}else{
		simple():
	}
}


*/

#endif /* FUNCIONESHUMANO_H_ */
