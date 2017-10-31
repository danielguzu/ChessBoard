/* problema de las 8 Reinas*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define TRUE  1
#define FALSE 0

int cont = 1;


void mostrarTablero (short int tab[], int nR){
  	short int e, f;
	
	cout << "R: " << cont << "  ";
  	for (e=0; e < nR; e++) {
    	  cout << "(" <<e <<","<<tab[e] <<") - ";
  	}
  	printf("\n");
  	cont++;
}

int comprobar (short int fila, short int tabl[]){
  	short int e, f, r;

  	for (e=0; e < fila; e++){
  		if((tabl[e] == tabl[fila]) || (abs(fila-e) == abs(tabl[fila]-tabl[e]))) 
         	return FALSE;
	}
  	return TRUE;
}

colocarReina(short int fila, short int tablero[], short int nR){
	short int valor;
	
	if (fila < nR){
	    for (tablero[fila] = 0; tablero[fila] < nR; tablero[fila]++) {
	    	valor = comprobar(fila, tablero);
	        if (valor == TRUE) colocarReina (fila+1, tablero, nR);
	    } 
	  
	}else mostrarTablero(tablero, nR);
	
}


main(){
	short int e, f, r;
	
	short int *Tablero;  
  	short int numReinas = 8;  
	
 	cout <<"\nVamos a obtener la solucion del problema de las 8 Reinas"<< endl;
	if (numReinas > 0){
		Tablero = new(short int);
		
      	for (e=0; e < numReinas; e++) Tablero[e] = -1;
		      	
		colocarReina(0, Tablero, numReinas);

      	free (Tablero);
  	}
}
