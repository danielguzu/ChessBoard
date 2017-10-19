/* problema de las 8 Reinas*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int x[7], y[7], numR = 0;
int flag = 0;

/* Las estructuras que almacenan los estados y la de control -------------------------------------------*/
typedef struct nodo{
 int n;
 int m;
 int valor;
 struct nodo *sig;
} LISTA;

/* Estructuras para los movimientos  de la reina -----------------------------------*/
LISTA *bordeReina[7];

/*Agrega elementos a la lista de posiciones -------------------------*/
void insertar(LISTA **ptr, int elemento1, int elemento2, int elemento3){
LISTA *p1, *p2;
p1 = *ptr;


if(p1 == NULL){
	p1 = new(LISTA);
	if (p1 != NULL){
		p1->n = elemento1;
		p1->m = elemento2;
		p1->valor = elemento3;
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
			p2->valor = elemento3;
			p2->sig = NULL;
			p1->sig = p2;
		}
	}
} 

/* Muestra los valorees de las posiciones -----------------------------------------------------*/
void mostrar_lista(LISTA *ptr){
	while(ptr != NULL){
		cout<<"("<<ptr->n<<","<<ptr->m<<")= "<< ptr->valor <<" - ";
		ptr = ptr->sig;
	}
}

// Letreros ------------------------------------------------------------------------------------

nosePuede(int r1, int r2, int f){
	
	cout << "\n";
	if(f == 1){
		cout << "Las reinas "<< r1+1 << " y "<< r2+1 << " estan juntas." << endl;	
	} 
	else if(f == 2){
		cout << "Las reinas "<< r1+1 << " y "<< r2+1 << " estan en la misma diagonal." << endl;
	}
	else if(f == 3){
		cout << "Las reinas "<< r1+1 << " y "<< r2+1 << " estan en la misma vertical." << endl;
	}
	else if(f == 4){
		cout << "Las reinas "<< r1+1 << " y "<< r2+1 << " estan en la misma horizontal." << endl;
	}
	cout << "Asi no tiene solucion el problema." << endl;
}

// Busca que las reinas no esten juntas --------------------------------------------------------
buscaBordeRepetido(int r2X, int r2Y, LISTA *ptr, int r1, int r2){
	while(ptr != NULL){
		if((ptr->n == r2X) && (ptr->m == r2Y)){
			nosePuede(r1, r2, 1);
			flag = 0;		
		}
		ptr = ptr->sig;
	}
}
// Busca que las reinas no esten juntas --------------------------------------------------------
buscaLineasRepetida(int x1, int y1, int x2, int y2, int r1, int r2){
	if(x1+y1 == x2+y2) nosePuede(r1, r2, 2);
	else if(x1+(7-y1) == x2+(7-y2)) nosePuede(r1, r2, 2);
	else if(x1 == x2) nosePuede(r1, r2, 3);
	else if(y1 == y2) nosePuede(r1, r2, 4);
}

creaBordesdeReinas(){
	int e, f, r;
	
	for(r = 0; r < numR; r++){
		for(e = -1; e <= 1; e++){
			for(f = -1; f <= 1; f++){
				insertar(&bordeReina[r], x[r] + e, y[r] + f, 1);
			}
		}
	}
}
// Analiza las condiciones iniciales de las Reinas -----------------------------------------------------
analisaConIni(){
	int e, f, r;
	for(f = 0; f < (numR-1); f++){
		for(e = 1; e < numR; e++){
			buscaBordeRepetido(x[e+f], y[e+f], bordeReina[f], f, e+f);
		}
	}
	for(f = 0; f < (numR-1); f++){
		for(e = 1; e < (numR-1); e++){
			buscaLineasRepetida(x[f], y[f], x[e+f], y[e+f], f, e+f);
		}
	}
	
}

main(){
	int e, f, r;
 	cout <<"\nVamos a obtener la solucion del problema de las 8 Reinas"<< endl;
	cout <<"Cuantas reinas quieres colocar tu : ";
	cin >> numR;
 	
 	for(e = 0; e < numR; e++){
 		cout <<"Cuales son sus coordenadas x e y (separados por un espacio '  '): ";
		cin >> x[e] >> y[e];
	}
	creaBordesdeReinas();
	
	for(e = 0; e < numR; e++) cout <<"\nLa posicion de la reina "<< e+1 << " es: x= "<< x[e] <<" y= "<< y[e] << endl;
	
	analisaConIni();
	
	
}
