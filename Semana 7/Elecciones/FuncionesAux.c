/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAX_CAR  40
void   leerCandidatos (int *candidatos,int *numCandidatos){
    FILE *archCandidatos ; 
    archCandidatos = fopen ("candidatos.txt","r");
    if (archCandidatos== NULL){
        printf ("ERROR EL ARCHIVO candidatos.txt no existe") ;
        exit (1);
    }
    int cand; 
    while (1){
        fscanf (archCandidatos ,"%d" ,&cand) ; 
        if (feof (archCandidatos))break;
        candidatos[*numCandidatos]=cand ;
        (*numCandidatos)++;
    }
    fclose (archCandidatos);
}
void   contarVotos (int *votos,int numCandidatos ) {

    FILE *archVotos;
    archVotos = fopen("votos.txt","r") ; 
    if (archVotos==NULL){
        printf ("Error el archivo de votos.txt no pudo abrirse");
        exit (1);
    }
    int voto ; 
    for (int v = 0 ; v<numCandidatos ; v++)votos[v] = 0;
    
    while (1){
        fscanf (archVotos, "%d" , &voto);
        if (feof(archVotos))break;
        if (voto>=1 && voto <= numCandidatos){
            votos[voto-1]++; 
        }
    }
}
void calcularPorcentaje(int *votos , int numCandidatos, double *porcentaje){
    int totalVotos = 0 ;
    for (int i = 0 ; i < numCandidatos ; i++){
        totalVotos+=votos[i] ;
    }
    for (int j = 0 ; j < numCandidatos ; j++){
        porcentaje[j] = votos[j]*100.0 / totalVotos ; 
    }
} 
void mostrarResultados(int *votos, int *candidatos,int numCandidatos , double *porcentaje) {
    int numCar , maxvotos;
     maxvotos = calculaMaximo(votos,candidatos,numCandidatos);
    for (int i = 0 ; i<numCandidatos ; i++){
        printf ("%10d      %10d     %10.2lf%% |" , candidatos[i] , votos[i],porcentaje[i]);
        numCar = votos[i]*MAX_CAR / maxvotos ;
        for (int j = 0 ; j < numCar ; j++){
            printf ("#");
        }
        printf ("\n");
    }
}
int calculaMaximo(int *votos,int *candidatos,int numCandidatos ){
    int mayor = 0 ;
    for (int i = 0 ; i< numCandidatos ; i++){
        if (mayor < votos[i]) mayor = votos[i];
    }
    return mayor; 
}