/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FuncionesAux.h"
#include <stdio.h>
#include <stdlib.h>

void leerDatos (int *datos , int *numDatos){
    FILE *archDatos ; 
    archDatos  = fopen ("datos.txt","r");
    if (archDatos == NULL){
        printf ("Error el archivo datos.txt no existe");
        exit(1);
    }
    int num ;  
    (*numDatos) = 0 ; 
    while (1){
        fscanf (archDatos,"%d",&num);
        if (feof (archDatos))break;
        datos[*numDatos] = num ;
        (*numDatos)++;
    }
}
void ordenar(int *datos,int numDatos){
    int aux;
    for (int i = 0 ;i < numDatos-1 ; i++){
        for (int j=i+1;j<numDatos;j++){
            if (datos[i]>datos[j]){//DETERMINA SI SE QUIERE ORDENAR DE MAYOR A MENOR
                cambiar(datos,i,j);
            }

        }
    }
}
void cambiar(int *datos,int i,int j){
    int aux ;
    aux = datos[i];
    datos[i] = datos[j];
    datos[j] = aux ;
}
void imprimirDatos(int *datos,int numDatos){
    for (int i = 0 ; i < numDatos ; i++){
        printf (" %7d\n" , datos[i]);
    }
}