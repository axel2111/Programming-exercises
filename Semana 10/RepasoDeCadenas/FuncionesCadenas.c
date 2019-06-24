/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include "FuncionesCadenas.h"
#include <stdlib.h>
#include <string.h>
FILE *abrirArchivo(char *nombArch,char *modo){
    FILE *arch;
    arch = fopen (nombArch,modo);
    if (arch==NULL){
        printf ("Error, el archivo %s no existe" , nombArch);
        exit(1);
    }
    return arch;
}
char *leerCadenaExacta(FILE *arch){
    char aux[50], *cad;
    leerCadena(aux,50,arch);
    if (feof(arch))return NULL;
    cad = (char*) malloc (sizeof(char)*(strlen(aux)+1));
    strcpy(cad,aux);
    return cad;
}
void leerCadena(char *aux,int numCar,FILE *arch){
    int i =0 ;
    fgets (aux , numCar , arch);
    i = strlen (aux);
    aux[i-1] = 0 ;
}
void ordenarDatos(char **arr,int numDatos){
    for (int i= 0 ; i < numDatos -1 ; i++)
        for (int j=i+1 ; j < numDatos ;j++)
            if (strcmp(arr[i],arr[j])>0)
                cambiar(arr,i,j);
}
void cambiar (char **arr , int i, int j){
    char *aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j]=aux;
}