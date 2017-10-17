/* Movimientos de la Reina de Ajedrez */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long int x = 0, y = 0;

/* Las estructuras que almacenan los estados y la de control -------------------------------------------*/
typedef struct nodo{
 int n;
 int m;
 struct nodo *sig;
} LISTA;

/* Estructuras para los movimientos  de la reina -----------------------------------*/
LISTA *movDiag = NULL, *movDiagInv = NULL;

/*Agrega elementos a la lista de posiciones -------------------------*/
void insertar(LISTA **ptr, int elemento1, int elemento2){
LISTA *p1, *p2;
p1 = *ptr;


if(p1 == NULL){
	p1 = new(LISTA);
	if (p1 != NULL){
		p1->n = elemento1;
		p1->m = elemento2;
		p1->sig = NULL;
		*ptr = p1;
	}
}
else{
	while(p1->sig != NULL)
		p1 = p1->sig;
		p2 = new(LISTA);
		if(p2 != NULL){
			p2->n = elemento1;
			p2->m = elemento2;
			p2->sig = NULL;
			p1->sig = p2;
		}
	}
} 

/* Muestra los valorees de las posiciones -----------------------------------------------------*/
void mostrar_lista(LISTA *ptr){
	while(ptr != NULL){
		cout<<"("<<ptr->n<<","<<ptr->m<<") - ";
		ptr = ptr->sig;
	}
}

/* Movimiento diagonal invertida de la reina -----------------------------------*/
diagonalInvertidaAlfil(){
	int dif = 0;
	int cont, tempX, tempY, auxY;
	
	auxY = 7 - y;
	if((x + auxY) < 7){
		dif = x;
		tempY = y - dif;
		for(cont = 0; tempY < 7; cont++){
 			tempX = x - dif + cont;
 			tempY = y - dif + cont;
 			insertar(&movDiagInv, tempX, tempY);
		}
	 }
	 else{
	 	dif = 7 - x;
	 	tempY = y + dif;
	 	for(cont = 0; tempY > 0; cont++){
 			tempX = x + dif - cont;
 			tempY = y + dif - cont;
 			insertar(&movDiagInv, tempX, tempY);
		}
	 }
}

/* Movimiento diagonal de la reina -----------------------------------*/
diagonalAlfil(){
	int dif = 0;
	int cont, tempX, tempY;
	
	if((x + y) < 7){
 		dif = x;
 		tempY = y + dif;
 		for(cont = 0; tempY > 0; cont++){
 			tempX = x - dif + cont;
 			tempY = y + dif - cont;
 			insertar(&movDiag, tempX, tempY);
		 }
	 }
	 else{
	 	dif = 7 - x;
 		tempY = y - dif;
 		for(cont = 0; tempY < 7; cont++){
 			tempX = x + dif - cont;
 			tempY = y - dif + cont;
 			insertar(&movDiag, tempX, tempY);
		}
	 }
}

alfil(){
	diagonalAlfil();
	diagonalInvertidaAlfil();
}

main(){
	
 	cout <<"\nVamos a obtener los movimientos posibles del Alfil de Ajedrez"<< endl;
	cout <<"Cuales son los valores x e y (separados por un espacio '  '): ";
	cin >> x >> y;
 	
 	alfil();
 	
 	cout <<"\n\nLa posicion del Alfil son: x= "<<x <<" y= "<< y<< endl;
	cout <<"\nLa Lista de posiciones es: "<< endl;
	cout <<"Diagonal"<< endl;
	mostrar_lista(movDiag);
	cout <<"\n\nDiagonal Invertida"<< endl;
	mostrar_lista(movDiagInv);
}
	
