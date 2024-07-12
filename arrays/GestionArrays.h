#ifndef _GestionArrays_h
#define _GestionArrays_h

const int MAX=20;

// carga un vector con valores al azar entre min, max
void CargaVector(int v[], int n, int min, int max);
    

// genera un vector ordenado. El primer valor es "inicial" y los siguientes 
// son incrementos al azar entre [0, incremento-1]
void CargaVectorOrdenado(int v[], int n, int inicial, int incremento);

// te devuelve por referencia el valor maximo y el minimo
void MaxMin(int v[],int n ,int& pos_max,int& pos_min);

// te devuelve por referencia el valor mas frecuente y su frecuencia
void MasFrecuente(int v[],int n,int& valor,int& frec);

// te devuelve true si v esta ordenado de forna creciente
bool EstaOrdenado(int v[],int n);

// te devuelve si todos son distintos
bool TodosDistintos(int v[],int n);

// devuelve la mezcla de ambos vectores ordenada 
void MezclaOrdenada(int v1[], int n1,int v2[],int n2,int v3[],int& n3);

#endif /* _GestionArrays_h */
