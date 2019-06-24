/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
void leerDatos (int *dni , int *telefono ,double *sueldo, int *numDatos){
    FILE *archDatos ; 
    archDatos = fopen ("personasDatos.txt","r");
    if (archDatos == NULL){
        printf ("Error, el archivo personasDatos.txt no existe ") ;
        exit (1);
    }
    
    int dniAD,telefonoAD;
    double sueldoAD;
    (*numDatos) = 0 ; 
    while (1){
        fscanf (archDatos,"%d %d %lf",&dniAD,&telefonoAD,&sueldoAD);
        if (feof(archDatos))break;
        dni[*numDatos] = dniAD;
        telefono[*numDatos] = telefonoAD;
        sueldo[*numDatos] = sueldoAD;
        (*numDatos)++;
    }
 
}
void imprimirDatos(int *dni,int *telefono,double *sueldo,int numDatos) {
    for (int i = 0 ;i < numDatos ;i++){
        printf ("%3d)     %8d     %9d     %8.2lf\n",i+1,dni[i],telefono[i],sueldo[i]);
    }
}
void ordenarDatos(int *dni,int *telefono,double *sueldo,int numDatos){
    for(int i = 0 ;i < numDatos-1;i++){
        for (int j = i+1 ; j<numDatos ; j++){
            if (sueldo[i] > sueldo[j]){//sueldo
                cambiar(dni,i,j);
                cambiar(telefono,i,j);
                cambiarD(sueldo,i,j);
            }    
        }
    }
}
void cambiar (int *dni,int i , int j ){
    int aux;
    aux = dni[i];
    dni[i]=dni[j];
    dni[j]=aux;
}
void cambiarD (double *sueldo,int i , int j ){
    double aux;
    aux = sueldo[i];
    sueldo[i]=sueldo[j];
    sueldo[j]=aux;
}