/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
FILE *abrirArchivo (char *nombre,char *modo){
    FILE *arch;
    arch = fopen (nombre,modo);
    if (arch==NULL){
        printf ("error el archivo %s no existe" , nombre);
        exit(1);
    }
    return arch ; 
}
void leerCadena(char *cad,int numCar,FILE *arch){
    int n ;
    fgets (cad,numCar,arch);
    n= strlen(cad);
    cad [n-1] = 0 ; 
}
char *leerCadenaExacta(FILE *arch){
    char cadAux[200] , *cad;
    leerCadena(cadAux,200,arch);
    if (feof (arch)) return NULL;
    cad = (char*) malloc (sizeof(char) * (strlen(cadAux)+1));
    strcpy(cad,cadAux);
    return cad;
}
void buscarSeparador(char *separador,char *frase){
    int i =0;
    separador [0] = 0 ;
    separador[1] = 0 ; 
    while ((frase[i] >= 'a' && frase[i] <= 'z')||frase[i] >= 'A' && frase[i] <= 'Z'||
            frase[i]>='0' && frase[i] <= '9') i++;
    separador[0] = frase[i];
}
void sacarPalabra(char *frase,char **palabras,int *numPalabras,char *separador){
    int i = 0 , j ;
    char cadAux [100], *cad;
    (*numPalabras=0);
    while (1){
        while(frase[i]==separador[0]) i++;
        if (frase[i] == 0 )break;
        j= 0 ; 
        while (frase[i]!=separador[0] && frase[i]!= 0){
            cadAux [j] = frase[i];
            j++;
            i++;
        }
        cadAux[j] = 0;
        cad = (char*) malloc(sizeof(char)*(strlen(cadAux)+1));
        strcpy(cad,cadAux);
        palabras[*numPalabras] = cad;
        (*numPalabras)++;
    }
}
void leerDatosEmpleado(FILE *arch ,int *codigo,double *sueldo,char **nombre,int *numEmpleados){
    char *frase , separador [10]; 
    char *palabras[50]; int numPalabras ;
    (*numEmpleados) = 0 ;
    char *cadAux;
    while (1){
        frase = leerCadenaExacta(arch);
        if (frase == NULL)break;
        numPalabras =0 ;
        buscarSeparador(separador,frase);
        sacarPalabra(frase,palabras,&numPalabras,separador);
        codigo[*numEmpleados] = atoi(palabras[0]);
        sueldo[*numEmpleados] = atof(palabras[2]);
        cadAux = (char*)malloc (sizeof(char)*(strlen(palabras[1])+1));
        strcpy(cadAux,palabras[1]);
        nombre[*numEmpleados] = cadAux;
        (*numEmpleados)++;
    }
}
void cambiarI(int *arr,int i,int j){
    int aux ;
    aux=arr[i];
    arr[i]=arr[j];
    arr[j] = aux;
}
void cambiarD(double *arr,int i,int j){
    double aux ;
    aux=arr[i];
    arr[i]=arr[j];
    arr[j] = aux;
}
void cambiarC(char **arr,int i,int j){
    char *aux ;
    aux=arr[i];
    arr[i]=arr[j];
    arr[j] = aux;
}
void ordenarDatosEmpleado(int *codigo,double *sueldo,char **nombre, int numEmpleados){
    for (int i = 0 ; i < numEmpleados-1 ; i++){
        for (int j = i+1 ; j < numEmpleados ;j++){
            if (codigo[i] > codigo[j]){
                cambiarI(codigo,i,j);
                cambiarD(sueldo,i,j);
                cambiarC(nombre,i,j);
            }
        }
    }
}