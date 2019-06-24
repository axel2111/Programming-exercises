/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
FILE *abrirArchivo (char *nomb,char *modo){
    FILE *arch ;
    arch = fopen (nomb,modo);
    if (arch==NULL){
        printf ("Error el archivo %s no existe \n" , nomb);
        exit (1);
    }
    return arch ; 
}
void leerCadena(char *arr,int numCar,FILE *arch){
    int i ;
    fgets (arr,numCar,arch);
    i = lonCad(arr);
    arr[i-1] = 0 ;
}
int lonCad(char *arr){
    int i = 0  ; 
    while (1){
        if (arr[i] == 0) break;
        i++;
    }
    return i  ;
}
int obtenerOraciones(char *linea){
    int oraciones=0 , i = 0;
    int numCar = lonCad(linea);
    for (i;i<numCar;i++){
        if (linea[i]=='.') oraciones++;
    }
    return oraciones ; 
}
void leerPalabras(char **palabras,FILE *archPalabras,int *numPalabras){
    (*numPalabras)=0;
    while (1){
        palabras[*numPalabras] = obtenerCadenaExacta(archPalabras);
        if (palabras[*numPalabras]==NULL)break;
        (*numPalabras)++;
    }
}
char *obtenerCadenaExacta(FILE *arch){
    char cadAux[50] , *cad;
    leerCadena(cadAux,50,arch);
    if(feof(arch)) return NULL;
    cad = (char*)malloc(sizeof(char) * (lonCad(cadAux)+1));
    copiarCadena(cad,cadAux);
    return cad;
}
void copiarCadena(char *destino,char *fuente){
    int i = 0 ; 
    while (1){
        destino[i] = fuente[i];
        if (destino[i] == 0) break;
        i++;
    }
}
void obtenerPalabrasRepetidas(char **palabrasLista,int numPalabrasLista,int *palabrasRepetidas,char *linea){
    char *palabrasLinea[100]; int numPalabrasLinea = 0 ;
    sacarPalabras(linea,palabrasLinea,&numPalabrasLinea);
    int compara = 1 ;
    char cadAux[100],signo[100];
    for (int i = 0 ; i < numPalabrasLinea ; i++){
        copiarCadena(cadAux,palabrasLinea[i]);
        corregirCadena(cadAux,signo);
        for (int j = 0 ; j < numPalabrasLista;j++){
            compara = comparaCadena(cadAux,palabrasLista[j]);
            if(compara==0){
                palabrasRepetidas[j]++;
            }
        }
    }
}
int comparaCadena(char *arr1,char *arr2){
    int i =0 ;
    while (arr1[i]==arr2[i]){
        if (arr1[i]==0)return 0;
        i++;
    }
    return arr1[i]-arr2[i];
}
void sacarPalabras(char *frase,char **arr,int *cant){
    int i= 0,j ;
    char cadAux[100]  , *cad; 
    (*cant) = 0;
    while (1){
        while (frase[i]==' ' ) i++;
        if (frase[i] == 0 )break;
        j=0;
        while (frase[i]!=' '  && frase[i]!=0 ){
            cadAux[j] = frase[i];
            i++;
            j++;
        }
        cadAux[j] = 0 ;
        cad = (char*)malloc(sizeof(char)*(lonCad(cadAux)+1));
        copiarCadena(cad,cadAux);
        arr[*cant] = cad;
        
        (*cant)++;
    }    
}   

void corregirTexto(char *linea,char **sinonimos,char **palabras,int numPalabras,
                        FILE *archReporte){
    char *palabrasLinea[150];int numPalabrasLinea = 0 ;
    char cadAux[100],signoRaro[20];
    sacarPalabras(linea,palabrasLinea,&numPalabrasLinea);
    int comp =  1; 
    for (int i = 0 ; i < numPalabrasLinea;i++){
        copiarCadena(cadAux,palabrasLinea[i]);
        corregirCadena(cadAux,signoRaro);
        for (int j=0;j < numPalabras ; j++){
            comp = comparaCadena(cadAux,palabras[j]);
            if (comp==0) {
                copiarCadena(palabrasLinea[i] , sinonimos[j]);
                concatenar(palabrasLinea[i],signoRaro);
            }
        }
        fprintf (archReporte,"%s " ,palabrasLinea[i] );
    }
    fprintf (archReporte,"\n") ;
}
void corregirCadena(char *cad,char *signo){
    int i = lonCad(cad);
    signo[0] = 0 ;
    if (cad[i-1]=='.'||cad[i-1]==','||cad[i-1]=='?'||cad[i-1]=='!') {
        signo[0] = cad[i-1];
        cad[i-1] = 0 ;
        signo[1] = 0 ;
    }
   
}

void palabrasPalindromas(char *linea,char *palindromas,int *primera){
    char *palabrasLinea[150] ; int numPalabrasLinea  = 0 ;
    sacarPalabras(linea,palabrasLinea,&numPalabrasLinea);
    char cadAux[100],signoRaro[100];
    int pal =  0 , longitud; 
    for (int i = 0 ; i < numPalabrasLinea ; i++){
        copiarCadena(cadAux,palabrasLinea[i]);
        convertirMayuscula(cadAux);
        corregirCadena(cadAux,signoRaro);
        pal = obtenerPalindroma(cadAux);
        longitud = lonCad(cadAux);
        if (pal == 1 && longitud >=2) {
            if (*primera == 1 ){
                copiarCadena (palindromas,palabrasLinea[i]);
                (*primera)++;
            }
            else{
                concatenar(palindromas," ");
                concatenar(palindromas,palabrasLinea[i]);
            }
        }
    }
}        
int sumarPalabras(char *linea){
    char *palabrasLinea[150] ; int numPalabrasLinea  = 0 ;
    sacarPalabras(linea,palabrasLinea,&numPalabrasLinea);
    return numPalabrasLinea;
}
void concatenar(char *destino , char *fuente){
    int i ;
    i = lonCad(destino);
    copiarCadena(&destino[i],fuente);
}
void convertirMayuscula(char *cad){
    int longitud ; 
    longitud  = lonCad(cad);
    for (int i = 0 ; i < longitud ; i++){
        cad[i] = (cad[i]>='a' && cad[i]<='z')?cad[i]-32:cad[i];
    }
    
}
int obtenerPalindroma(char *cadAux){
    int pal =0 ; 
    int i  =0 , j = lonCad(cadAux);
    while (cadAux[i]==cadAux[j-1]){
        i++;
        j--;
        if (i >= j) return 1;
    }
    return pal;
}