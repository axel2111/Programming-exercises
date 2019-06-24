/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
#include "Nombre.h"
void leerCadena(char*cad,int numCar , FILE *arch){
    int i ; 
    fgets(cad,numCar,arch);
    i = strlen(cad);
    cad[i-1]=0;
}
char *leerCadenaExacta(FILE *arch){
    char cadAux[50] , *cad;
    leerCadena(cadAux,50,arch);
    if (feof(arch)) return NULL;
    cad= (char*) malloc (sizeof(char)*(strlen(cadAux)+1));
    strcpy(cad,cadAux);
    return cad;
}
void sacarPalabras(char *frase,char **palabras,int *numPal){
    char cadAux[50] , *cad ;
    int i = 0 , j ;
    (*numPal) = 0 ;
    while (1){
        while (frase[i]==',')i++ ; 
        if (frase[i] == 0 )break;
        j=0;
        while (frase[i] != ',' && frase[i]!=0){
            cadAux[j] = frase[i];
            i++;
            j++;
        }
        cadAux[j] = 0;
        cad = (char*)malloc(sizeof(char)*(strlen(cadAux)+1));
        strcpy(cad,cadAux);
        palabras[*numPal] = cad;
        (*numPal)++;
    }
}
void leerDatos (struct Nombre *nombre,int *numDatos){
    FILE *arch = fopen ("datos.txt" , "r");
    (*numDatos) = 0 ; 
    char *frase , *cadAux , *cadAux2 ;
    char *palabras[50]; int numPal = 0 ;
    while (1){
        frase = leerCadenaExacta (arch);
        if (frase == NULL)break;
        sacarPalabras(frase,palabras,&numPal);
        nombre->codigo[*numDatos] = atoi(palabras[0]);
        nombre->sueldo[*numDatos] = atof(palabras[3]);
        cadAux = (char*) malloc (sizeof(char)*(strlen(palabras[1])+1) );
        strcpy(cadAux,palabras[1]);
        nombre->nombre[*numDatos] = cadAux;
        cadAux2 = (char*) malloc (sizeof(char)*(strlen(palabras[2])+1) );
        strcpy(cadAux2,palabras[2]);
        nombre->especialidad[*numDatos] = cadAux2;
        (*numDatos)++;
    }
}
void obtenerAportes(struct Nombre *nombre,struct Consultas consultas,int numDatos , int numConsultas){
    for (int k =0 ; k <numDatos ; k++) nombre->aporte[k] = 0 ; 
    for (int i = 0 ; i < numDatos ; i++){
        for (int j = 0 ; j < numConsultas ;j++){
            if (nombre->codigo[i] == consultas.dniMed[j]){
                nombre->aporte[i] += nombre->sueldo[i]; 
            }
        }
    }
}
void obtenerConsultas(struct Consultas *consultas,int *numConsultas){
    FILE *arch = fopen ("consultas.txt" , "r") ; 
    (*numConsultas) = 0 ; 
    int codMed;
    while (1){
        fscanf (arch,"%*d/%*d/%*d %*d %d" , &codMed);
        if (feof(arch))break;
        consultas->dniMed[*numConsultas] = codMed;
        (*numConsultas)++;
    }
}