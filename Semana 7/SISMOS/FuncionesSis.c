/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesSis.h"
#define MAX_CAR 40

void leerSismos(double *sismos , int *cantSismos, int *fechaSismos){
    FILE *archSismos;
    archSismos = fopen ("Sismos.txt", "r") ; 
    if (archSismos == NULL){
        printf ("ERROR  el archivo sismos.txt no se encontro\n");
        exit (1);
    }
    int dd,mm,aa, duracion ;
    double intensidad;
    while ( feof(archSismos)== 0){
        fscanf (archSismos, "%d/%d/%d %d %lf" , &dd,&mm,&aa,&duracion,&intensidad);
        fechaSismos[*cantSismos] = aa*10000 + mm * 100 +dd;
        sismos[*cantSismos] = intensidad; 
        (*cantSismos)++;
    }
    fclose (archSismos);
}
void contarSismos(int *fechaSismos , double *sismos,int cantSismos,int *contSismos,int fechaI,int fechaF){
    
    for (int i = 0 ; i < cantSismos ; i++){
        if ((fechaSismos[i]>=fechaI) && (fechaSismos[i]<=fechaF)){
            if (sismos[i]>0 && sismos[i] < 10){
                contSismos[(int) sismos[i]]++;
            }
        }
    }
}
void mostrarSismos(double *sismos,int *contSismos,int cantSismos){
    
    int masLargo ;
    int numCar = 0 ;
    masLargo = calcularMaximo(contSismos , cantSismos) ;
    
    for(int i = 0 ; i<cantSismos ; i++ ){
        numCar = MAX_CAR*contSismos[i]/masLargo;
        printf ("           %2d                [%2d , %2d]       ||  " , contSismos[i] , i ,i+1);
        for (int j = 0 ; j <numCar ; j++){
            printf (" ");
        }
        printf ("*\n");
    }
}
int calcularMaximo(int *cantSismos , int contSismos){
    int mayor = 0 ; 
    for (int i = 0 ; i<contSismos ; i++){
        if (mayor < cantSismos[i]){
            mayor = cantSismos[i];
        }
    }
    return mayor ;
}