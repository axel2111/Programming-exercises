/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesCadenas.h"
#include <string.h>

char corregirCadena(char *cad){
    int i = 0 ; 

    i = longitudCadena(cad);

    /*i = strlen(cad);*/
    printf ("longitud de la cadena: %d\n" , i);
    cad[i-1] = 0 ;
}
int longitudCadena(const char *cad){
    int i  =  0 ; 
    while (cad[i]!=0){
        i++;
    }
    return i;
}
void leerCadena(char *palabra,int numCar,FILE *arch){
    int n; 
    fgets(palabra,numCar,arch);
    n= strlen(palabra);
    palabra[n-1] = 0 ;
}
void copiarCadena(char *destino, const char *origen){
    int n = 0 ;

    while (1){
        destino[n] = origen[n];
        if (origen[n] == 0)break;
        n++;
    }
    
} 

int comparaCadena (char *cad1,char *cad2){
    int i = 0  ; 
    while (cad1[i] == cad2[i]){
        if (cad1[i] == 0)return 0;
        i++;
    }
    return cad1[i] - cad2[i];
}
void concatenarCadena(char *destino,const char *fuente){
    int j = 0 ;
    j = strlen (destino);
    copiarCadena(&destino[j],fuente);
}