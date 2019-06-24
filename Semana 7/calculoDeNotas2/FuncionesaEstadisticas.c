/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FuncionesEstadisticas.h"
#define MAX_CARACTER 70
#define NOTA_MAX 20 

void  leerNotas(int *notas,int *numeroDeNotas){
    
    FILE *archNotas ;
    archNotas = fopen ("notas.txt" , "r");
    if (archNotas==NULL){
        printf ("ERROR EL ARCHIVO notas.txt NO EXISTE");
        exit (1);
    }
    int nta; 
    while (1){
        fscanf (archNotas,"%d" , &nta );
        if (feof(archNotas))break;;
        notas[*numeroDeNotas]  = nta ;
        (*numeroDeNotas)++;
    }
    fclose (archNotas) ; 
}
void  contarNotas(int *notas,int *contNotas,int numeroDeNotas) {
    for (int i = 0 ; i < numeroDeNotas; i++){
        contNotas[notas[i]-1]++;
    }
}
double porcentajeAprob(int *notas,int numeroDeNotas) {
    double porcentajeA  = 0 ; 
    int aprobados = 0 ;
    for (int i = 0 ; i < numeroDeNotas ; i++){
        if (notas[i] > 10){
            aprobados ++ ;
        }
    }
    porcentajeA = (double) aprobados / numeroDeNotas * 100;
    return porcentajeA;
}
double promedio (int *notas,int numeroDeNotas){
    double prom , suma  = 0  ; 
    
    for (int i = 0 ; i<numeroDeNotas ; i++){
        suma += notas[i];
    }
    prom  = suma / numeroDeNotas ; 
    return prom;
}
double desviacionEstandar (double prom , int *notas , int numeroDeNotas){
    double desvEst , suma  = 0 ; 
    for (int i = 0 ; i < numeroDeNotas; i++){
        suma+= (notas[i] - prom)*(notas[i] - prom); 
    }
    desvEst = sqrt (suma / (numeroDeNotas - 1 ));
    return desvEst; 
}

void imprimeResultados  (int *contNotas , double prom , double desvEst,int numeroDeNotas,double porcentajeA) {
    int max , numCar;  
    max = calcularMaximo(contNotas,numeroDeNotas);// ENCUENTRA QUE NOTA SE REPITE MAS
    
    for (int i = 0 ; i < NOTA_MAX ;i++){
        
        if (contNotas[i]  > 0){
            numCar = MAX_CARACTER * contNotas[i] / max ; 
            printf ("     %02d     %2d || "  , i+1,  contNotas [i]);
            for (int j = 0 ;j <numCar ; j++){
                printf ("*");
            }
            printf ("\n");
        }
    }
    printf ("Aprobados: %2.2lf%%         Desaprobados: %2.2lf%%\n" , porcentajeA,100-porcentajeA);
    printf ("El promedio final es: %.2lf\n" , prom);
    printf ("La desviacion estandar es: %.2lf\n" , desvEst);
}
int calcularMaximo (int *contNotas, int numeroDeNotas){
    int mayor = 0  ;
    for (int i = 0 ; i < NOTA_MAX ; i++){
        if (mayor < contNotas[i]){
            mayor = contNotas[i];
        }
    }
    return mayor; 
}