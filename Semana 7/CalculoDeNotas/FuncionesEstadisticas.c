/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FuncionesEstadisticas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leerNotas(int *notas, int *numNotas){
    FILE *archNotas ;
    archNotas= fopen ("notas.txt", "r") ;
    if (archNotas==NULL){
        printf ("Error el archivo notas no existe:\n");
        exit (1);
    }
    int nta ; 
    while (1){
        fscanf (archNotas , "%d" , &nta);
        if (feof (archNotas))break;
        notas[*numNotas] = nta;
        (*numNotas)++;
    }
    fclose (archNotas); 
}
void imprimeNotas(int *nota,int datos){
    for (int i = 0 ; i<datos; i++){
        printf ("%d) %d\n",i+1 , nota[i]);
    }
}
double promedio (int *nota,int numNotas){
    int suma =0 ;
    double prom ; 
    for (int i = 0 ; i<numNotas ; i++){
        suma+=nota[i];
    }
    prom = (double)suma/numNotas;
    return prom; 
}
double desviacionEstandar (double prom,int *nota,int numNotas){
    double suma = 0 ; 
    double desvEst ;
    for (int i = 0 ; i < numNotas ; i++){
        suma+=(nota[i]-prom)*(nota[i]-prom);
    }
    desvEst = sqrt(suma/(numNotas-1));
    return desvEst;
}