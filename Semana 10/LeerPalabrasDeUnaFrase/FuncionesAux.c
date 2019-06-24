/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"

char *leerCadenaExacta(FILE *arch){
    char cadAux[100] , *cad;
    leerCadena(cadAux,100,arch);
    if (feof(arch)) return NULL;
    cad = (char*) malloc (sizeof(char) * (lonCad(cadAux)+1));
    copiarCadena(cad,cadAux);
    return cad ; 
}
void leerCadena(char *cad,int numCar,FILE *arch){
    int i ; 
    fgets (cad,numCar,arch);
    i = lonCad(cad); 
    cad[i-1] = 0;
} 
int lonCad(char *cad){
    int i = 0  ;
    while (cad[i]!=0){
        i++;
    }
    return i;
}
void copiarCadena(char *destino,char *fuente){
    int i = 0 ; 
    while (1){
        destino[i] = fuente[i];
        if (fuente[i] == 0) break;
        i++;
    }
}
void sacarPalabra(char *frase,char **palabra,int *numDatos){
    int i = 0 , j  ;
    char *ptPal , palAux[100];
    while (1){
        while (frase[i] ==' ') i++;
        if (frase[i] == 0 ) break;
        j= 0 ;
        while (frase[i] != ' ' && frase[i] != 0){
            palAux[j] = frase[i];
            j++;
            i++;
        }
        palAux[j] = 0 ;
        ptPal=(char*) malloc (sizeof(char)*(lonCad(palAux)+1));
        copiarCadena(ptPal,palAux);
        palabra[*numDatos] = ptPal;
        (*numDatos)++;
    }
}
