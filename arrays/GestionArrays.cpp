
#include <GestionArrays.h>
#include <iostream>
using namespace std;

/* Auto-evaulacion de funciones
MaxMin: Bien
Masfrecuente:Bien
EstaOrdenado:Bien
TodosDistintos:Bien
MezclaOrdenada:Bien
Nota Autoevaluación:Bien

EstaOrdenado: 3 TEST OK

MezclaOrdenada: 3 TODOS LOS TEST OK

comentario del alumno =en el test mezclas 2 por esto -> assert(n3 == 0) supuse que cuando estan desordenados n3 es = 0 pero por si supuse mal tambien hize que ordenasen los vectores y luego lo mezclase pero esta comentada esa parte

MasFrecuente: 3 TEST OK

MaxMin: 3 TEST OK

TodosDistintos: 3 TEST OK

*/




void CargaVector(int v[], int n, int min, int max){
    int rango = max - min;
    for(int i = 0; i < n; i++)
        v[i] = random()% rango + min;
}

void CargaVectorOrdenado(int v[], int n, int inicial, int incremento){

    v[0] = inicial;
    for(int i = 1; i < n; i++)
        v[i] = v[i-1] + random() % incremento;
}

void MaxMin(int v[],int n ,int& pos_max,int& pos_min){

	int max= v[0];
	int min= v[0];
	pos_max= 0;
	pos_min= 0;
	
	for(int i=0; i<n; i++){
		if(max<v[i]){
			max= v[i];
			pos_max=i;
		}
		if(min>v[i]){
			min=v[i];
			pos_min=i;
		}
		
	}
}

void MasFrecuente(int v[],int n,int& valor,int& frec){

	int contador= 0;
	frec= 0;
	valor= v[0];
	
	
	for(int i=0; i<n; i++){
	
		contador=0;

		for(int j=i; j<n; j++){
			if(v[j]==valor)
				contador++;
		}
		if(contador>frec){
			frec= contador;
			valor = v[i];
		}
	}
}

bool EstaOrdenado(int v[],int n){

	bool ordenado=true;
	
	for(int i=1; i<n && ordenado; i++){
		if(v[i] < v[i-1])
			ordenado= false;
	}
	
	return ordenado;
}

bool TodosDistintos(int v[],int n){

	bool distintos= true;
    int valor;
	
	for(int i=0; i<n-1 && distintos; i++){
		valor=v[i];
		
		for(int j=i+1; j<n; j++){
			if(valor==v[j])
				distintos= false;
		}	
	}

	return distintos;
}

void MezclaOrdenada(int v1[], int n1,int v2[],int n2,int v3[],int& n3){
	
	//int aux_elem;
	if((n1+n2)>=MAX){
		n3=MAX;
	}else{
	n3= n1+n2;
	}
	int cont1= 0, cont2= 0,cont3= 0;
	bool terminado= false;
	
	if(!EstaOrdenado(v1,n1) || !EstaOrdenado(v2,n2)){
		n3=0;
		return;
	}
	/*if(!EstaOrdenado(v1,n1)){
		for(int i=0; i<n1; i++){
			
			for(int j=1; j<n1; j++){
				if(v1[j] < v1[j-1]){
					aux_elem = v1[j];
					v1[j] = v1[j-1];
					v1[j-1]= aux_elem;	
				}
			}
		}
	}
	if(!EstaOrdenado(v2,n2)){
		for(int i=0; i<n2; i++){
			
			for(int j=1; j<n2; j++){
				if(v2[j] < v2[j-1]){
					aux_elem = v2[j];
					v2[j] = v2[j-1];
					v2[j-1]= aux_elem;	
				}
			}
		}
	}
	*/
	
	while(!terminado && cont3<MAX){
	
		if(v1[cont1]<v2[cont2]){
			v3[cont3]= v1[cont1];
			cont1++;
			cont3++;
		}else{
			v3[cont3]= v2[cont2];
			cont2++;
			cont3++;
		}
		
		if(cont1==n1)
			terminado= true;
		
		if(cont2==n2)
			terminado= true;
		
			
	}
	
	
	
	if(cont3<MAX){
	
	if(cont1==n1){
		for(int i=cont3; i<MAX; i++,cont2++)
			v3[i]= v2[cont2];	
	}else{
		for(int i=cont3; i<MAX; i++,cont1++)
			v3[i]= v1[cont1];
	}

	}
}












