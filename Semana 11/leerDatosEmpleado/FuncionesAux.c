/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"

int lonCad(char *cad){
    int i = 0 ; 
    while (1){
        if (cad[i]==0)break;
        i++;
    }
    return i ; 
}
void leerCadena(char *cad , int numCar , FILE *arch ){
    int i ; 
    fgets (cad,numCar,arch);
    i = lonCad(cad);
    cad[i-1]=0;
}
void copiarCadena(char *destino,char *fuente){
    int i =0 ;
    while (1){
        destino[i] = fuente[i];
        if (destino[i]==0) break;
        i++;
    }
}
void concatenar(char *destino,char *fuente){
    int i = 0 ; 
    i = lonCad(destino);
    copiarCadena(&destino[i], fuente);
}
char *leerCadenaExacta(FILE *arch){
    char cadAux[300] , *cad;
    leerCadena(cadAux,300,arch);
    if (feof(arch))return NULL;
    cad = (char*)malloc (sizeof(char)*(lonCad(cadAux)+1));
    copiarCadena(cad,cadAux);
    return cad;
}
void buscarSeparador (char *separador,char *frase){
    int i = 0  , n ;
    n = lonCad(frase);
    while ((frase[i]>='a' && frase[i]<='z') ||(frase[i]>='A' && frase[i]<='Z')
            || frase[i] >= '0' && frase[i]<='9'){
        i++;
    }
    separador[0] = frase[i];
    separador[1] = 0 ;
}
void sacarPalabra(char *frase , char **arr ,int *num , char*separar ){
    char cadAux[100], *cad;
    int i = 0 , j , k=0;
    (*num) = 0 ;
    while (1){
        while (frase[i]==separar[k])i++;
        if (frase[i]==0)break;
        j=0;
        while (frase[i] != separar[k] && frase [i] != 0){
            cadAux[j] = frase[i];
            i++;
            j++;
        }
        cadAux[j] = 0 ;
        cad=(char*) malloc (sizeof (char) * (lonCad(cadAux)+1));
        copiarCadena(cad,cadAux);
        arr[*num] = cad;
        (*num)++;
    }
    
}
void leerDatosEmpleado(FILE *arch,char *nombre,int *codigo,double *sueldo){
    char *frase , *palabra[50];
    char separador[10];
    int numPalabras = 0 ; 
    frase = leerCadenaExacta (arch);
    buscarSeparador (separador,frase);
    sacarPalabra(frase,palabra,&numPalabras,separador);    
    (*codigo) = atoi(palabra[0]);
    (*sueldo) = atof(palabra[numPalabras-1]);
    copiarCadena(nombre,palabra[numPalabras-3]);
    concatenar(nombre,"/");
    concatenar(nombre,palabra[numPalabras-2]);
    concatenar(nombre,"/");
    concatenar(nombre,palabra[1]);
    for(int i = 2; i < numPalabras-3;i++){
        concatenar(nombre,"/");
        concatenar(nombre,palabra[i]);
    }
}
