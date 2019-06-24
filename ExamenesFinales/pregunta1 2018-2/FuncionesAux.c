/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
FILE *abrirArchivo(char *nombre,char *modo){
    FILE *arch;
    arch = fopen (nombre,modo);
    if (arch == NULL){
        printf ("Error, el archivo %s no existe " , nombre);
        exit (1);
    }
    return arch; 
}
void leerCadena(char *cad , int numCar,FILE *arch){
    int i ; 
    fgets (cad,numCar,arch);
    i = strlen(cad);
    cad[i-1] = 0 ;
}
char *leerCadenaExacta(FILE *arch){
    char cadAux[100] , *cad;
    leerCadena (cadAux,100,arch);
    if (feof(arch))return NULL;
    cad=(char*) malloc (sizeof(char)*(strlen(cadAux)+1));
    strcpy(cad,cadAux);
    return cad;
}
void leerListaDeArchivos(char **lista,int *numArchivos, FILE *archLista){
    while (1){
        lista[*numArchivos] = leerCadenaExacta(archLista);
        if (lista[*numArchivos] == NULL )break;
        (*numArchivos)++;
    }
}
void cambiarC(char **arr , int i , int j ){
    char *aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux ;
}
void ordenarArchivos(char **lista,int numArchivos){
    for (int i = 0 ; i < numArchivos-1;i++){
        for (int j = i+1 ; j<numArchivos ; j++){
            if (strcmp(lista[i],lista[j])>0){
                cambiarC(lista,i,j);
            }
        }
    }
}
void obtenerReporte(char *buscar,char **lista,int numArchivos){
    FILE *reporte = abrirArchivo("reporte.txt","w");
    FILE *arch;
    int encontrar = 0;
    
    for (int i =0  ;i < numArchivos ;i++){
        arch=verificarArchivo(lista,i);
        int posLinea[100] = {0} , numPosLinea = 0;
        if (arch != NULL){
            printf ("%s " , lista[i]);
            buscarPalabra(posLinea,&numPosLinea,buscar,arch);
            if (numPosLinea > 0){
                mostrarReporte(reporte,posLinea,numPosLinea);
            }   
            printf ("\n");
        }
        else {
            printf ("%s No se encontro el archivo\n",lista[i]);
        }
    }
}
void mostrarReporte(FILE *reporte,int *posLinea,int numPosLinea){
    for (int i = 0 ; i < numPosLinea;i++){
       printf (" %d " , posLinea[i]); 
    }
}
void buscarPalabra(int *posLinea,int *numPosLinea,char *buscar,FILE *arch){
    char separador[1]  ,frase[300]; 
    char *palabras[200] ;int numPalabras =0 ;
    int comp = 0 ,linea = 0 ;
    
    while(1){
        
        leerCadena(frase,300,arch);
        if (feof(arch))break;//FUnciona como fin de archivo
        buscarSeparador(separador,frase);
        linea++;
        sacarPalabras(frase,palabras,&numPalabras,separador);
       
        for (int i = 0 ; i < numPalabras ; i++){
            comp = strcmp(buscar,palabras[i]);
            if (comp==0) {
                posLinea[*numPosLinea] = linea;
                (*numPosLinea)++;
                break;
                
            }
        }
    }
    
}
FILE *verificarArchivo(char **lista,int i ){
    FILE *arch ; 
    arch = fopen(lista[i],"r");
    return arch;
}
void buscarSeparador(char *separador,char *frase){
    int i =0;
    separador [0] = 0 ;
    separador[1] = 0 ; 
    while ((frase[i] >= 'a' && frase[i] <= 'z')||frase[i] >= 'A' && frase[i] <= 'Z'||
            frase[i]>='0' && frase[i] <= '9') i++;
    separador[0] = frase[i];
}
void sacarPalabras(char *frase,char **palabras,int *numPalabras,char *separador){
    int i = 0  , j ;
    char cadAux[200] , *cad ;
    (*numPalabras)=0;
    while (1){
        while (frase[i]==separador[0])i++;
        if (frase[i]==0)break;
        j=0;
        while (frase[i] != separador[0] && frase[i]!=0){
            cadAux[j] =frase[i];
            i++;
            j++;
        }
        cadAux[j] = 0 ;
        cad = (char*) malloc (sizeof(char) * (strlen(cadAux)+1));
        strcpy(cad,cadAux);
        palabras[*numPalabras] = cad ; 
        (*numPalabras)++;
       
    }
}