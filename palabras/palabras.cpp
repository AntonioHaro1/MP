/* 
 * File:   palabras.cpp
 * Author: David Pelta
 * 
 * Created on 1 de abril de 2021,
 */

#include "palabras.h"

/*

    Mi programa NO produce la salida esperada en algunos ejemplos del guion(casi si)

*/



int tamanio(const char s[]) {
    int cont = 0;

    while (s[cont] != TERMINADOR)
        cont++;

    return cont;
}

// funcion "privada". 
// PRE: j siempre esta en el rango correcto
bool empiezaPalabra(const char s[], int j) {
       
    bool es_letra_actual;
    bool hay_sep_previo = true;
    
    es_letra_actual = s[j] != SEP;
    if ( j > 0)
       hay_sep_previo = (s[j - 1] == SEP);
    
    
    return (es_letra_actual && hay_sep_previo);
}

// funcion "privada". 
// PRE: j siempre esta en el rango correcto
bool terminaPalabra(const char s[], int j) {
    
    bool es_letra_actual = (s[j] != SEP);
    bool hay_sep_sig = (s[j + 1] == SEP) || (s[j + 1] == TERMINADOR);

    return (es_letra_actual && hay_sep_sig);
}


int posPalabra(const char msg[], int nroPal) {
    
    int contador= 0;
    int i=0,pos=-1;

    while(msg[i]!= TERMINADOR && contador!=nroPal){

        if(i==0 && msg[i]== SEP && msg[i]!= TERMINADOR){

            contador++;

        }else{

        if(empiezaPalabra(msg,i))
            contador++;
        }
        if(contador==nroPal)
            pos=i;

     i++;

     }

    return pos;
}

int longPalabra(const char s[], int nroPal) {

       int contador=0,i;

       i= posPalabra(s,nroPal);

        if(i!=-1){
             while(!terminaPalabra(s,i+contador)){
                 contador++;
            }
            if(terminaPalabra(s,i+contador))
                contador++;
        }

    return contador;

}


int cuentaPalabras(const char msg[]) {

     int contador=0,i=0;

        while(msg[i]!= TERMINADOR){

            if(terminaPalabra(msg,i))
                contador++;
            
            i++;
        }
    return contador;
}

void extraePalabra(const char msg[], int nroPal, char salida[]) {

    int i,j;

    i=posPalabra(msg,nroPal);

    j=longPalabra(msg,nroPal);

    for(int cont=0;cont<j;cont++)
        salida[cont]= msg[i+cont];

    salida[j]=TERMINADOR;
    
}

void delReves(const char msg[], char msg_reves[]) {

    int pos_prin,longitud,numP,caracteres;

    numP = cuentaPalabras(msg);
    caracteres = tamanio(msg);

    int j=0;
    int k=0;
  

    for(int i=caracteres-1;i>=0;i--){

        if(i==0 && msg[i]!=SEP){
            pos_prin=i;
            k=0;
            while(msg[pos_prin+k]!= SEP && msg[pos_prin+k]!=TERMINADOR){
                msg_reves[j]= msg[pos_prin+k];
                j++;   
                k++;
            }
        }else{
        if(empiezaPalabra(msg,i)){
            numP--;
            pos_prin=i;
            k=0;
            
            while(msg[pos_prin+k]!= SEP && msg[pos_prin+k]!=TERMINADOR){
                msg_reves[j]= msg[pos_prin+k];
                j++;   
                k++;
            }
            if(numP!=1)
                msg_reves[j]= '-';
            j++;
        }
        }
    }
    

    msg_reves[j]= TERMINADOR;
    
}

void agregaPalabra(char msg[], const char pal[]) {
    int i=0;
    int j;

    if(tamanio(msg)==0){
        j=0;
        while(pal[i]!= TERMINADOR){
            msg[j]= pal[i];
            j++;
            i++;
        }

    }else{
        j=tamanio(msg);
        msg[j]='-';
        j++;

        while(pal[i]!=TERMINADOR){
            msg[j]=pal[i];
            j++;
            i++;
        }

    }
}