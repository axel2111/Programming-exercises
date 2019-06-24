/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FuncionesAux.h"

FILE *abrirArchivo (char *nombArch  ,char *modo){
    FILE *arch;
    arch = fopen (nombArch,modo);
    if (arch == NULL){
        printf ("Error , el archivo %s no existe\n" , nombArch);
        exit (1);
    }
    return arch;
}

void leerArregloD(double *arr,int *cont,FILE *arch){
    double dato ; 
    (*cont)=0;
    while (1){
        fscanf (arch ,"%lf" ,&dato) ;
        if (feof(arch))break;
        arr[*cont] = dato ;
        (*cont)++;
    }
}
void leerArregloI(int *arr,int *cont,FILE *arch){
    int dato ; 
    (*cont)=0;
    while (1){
        fscanf (arch ,"%d" ,&dato) ;
        if (feof(arch))break;
        arr[*cont] = dato ;
        (*cont)++;
    }
}
void eliminarPosicion(double *premios,int numPremios,int *codigo,int numCodigos){
    FILE *reporte = abrirArchivo ("reporte.txt","w");
    int posCodEliminado ;
    int contador = 1  ;
    
    while(1){
        if (numCodigos == numPremios) break;
        posCodEliminado = rand()%numCodigos ; 
        printf ("Elimina la pos %d\n" ,posCodEliminado);       
        for (int i  = posCodEliminado ; i < numCodigos-1 ; i++){
            codigo[i] = codigo[i+1];
        }
        for (int j  = 0 ; j < numCodigos-1 ; j++){
            printf ("%d\n" , codigo[j]);
        }
        numCodigos--;
    }
    while (1){
        if (numCodigos==0)break;
        posCodEliminado = rand()%numCodigos;
        fprintf (reporte,"%7d %.2lf\n" ,codigo[posCodEliminado] , premios[numPremios-1]);
        for (int i  = posCodEliminado ; i < numCodigos-1 ; i++){
            codigo[i] = codigo[i+1];
        }
        numCodigos--;
        numPremios--;
    }
     
}
