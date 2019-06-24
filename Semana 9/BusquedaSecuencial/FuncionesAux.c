/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
void leerDatos (int *dni , int *telefono , double *sueldo, int *numDatos){
    FILE *archDatos ;
    archDatos = fopen("personasDatos.txt", "r");
    if (archDatos == NULL){
        printf ("error el archivo personasDatos.txt no existe\n");
        exit (1);
    }
    int d , tel;
    double sueld;
    while (1){
        fscanf (archDatos,"%d %d %lf",&d ,&tel , &sueld);
        if (feof(archDatos))break;
        dni[*numDatos] = d ;
        telefono[*numDatos] = tel; 
        sueldo [*numDatos] = sueld;
        (*numDatos)++;
    }
    fclose(archDatos);
}
void imprimirDatos (int *dni , int *telefono , double *sueldo, int numDatos){

    for (int i = 0 ; i < numDatos ; i++){
        printf (" %2d) %10d %9d      %7.2lf \n",i+1 , dni[i] , telefono[i] , sueldo[i]);
    }
}

void ordenarDatos(int *dni,int *telefono,double *sueldo,int numDatos){
    for (int i = 0 ; i <numDatos-1 ; i ++){
        for (int j = i+1 ; j <numDatos ; j++){
            if (dni[i] > dni[j]){
                cambiar(dni,i,j);
            }
        }
    }
}
void cambiar (int *dni, int i ,int  j ){
    int aux ; 
    aux = dni[i];
    dni[i] = dni[j];
    dni[j] = aux;
}
int busquedaSecuencial(int *dni,int dniBuscar,int numDatos){

    for (int i = 0 ; i < numDatos ; i++){
        if (dni[i] == dniBuscar){
            return i;
        }
    }
    return -1 ;
}