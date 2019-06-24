/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Medicos.h"
#include "Cadenas.h"
#include "Consultas.h"
#include "FuncionesMedicos.h"
void leerMedicos(struct Medicos *medicos,int *numMedicos){
    FILE *arch = fopen ("Medicos.txt","r");
    char *frase; 
    char *palabras[50]; int numPal= 0 ; 
    (*numMedicos) = 0 ;
    while (1){
        frase= leerCadenaExacta(arch);
        if (frase==NULL)break;
        sacarPalabra(frase,palabras,&numPal,",");
        medicos[*numMedicos].codigo = atoi(palabras[0]);
        strcpy(medicos[*numMedicos].nombre,palabras[1]);
        strcpy(medicos[*numMedicos].especialidad,palabras[2]);
        medicos[*numMedicos].sueldo = atof(palabras[3]);
        (*numMedicos) ++;
        free(palabras[0]);
        free(palabras[3]);
    }
}
void leerConsultas (struct Consultas *consultas,int *numConsultas){
    FILE *arch = fopen ("Consultas.txt","r");
    (*numConsultas) = 0 ;
    int codigo ; 
    while (1){
        fscanf (arch,"%*d/%*d/%*d %*d %d" , &codigo);
        if(feof(arch))break;
        consultas[*numConsultas].codigo = codigo;
        (*numConsultas)++;
    }
}
void obtenerAportes(struct Medicos *medicos,struct Consultas *consultas,int numMedicos,int numConsultas){
    for (int k = 0 ; k < numMedicos ; k++) medicos[k].aporte.aporte = 0 ; 
    for (int i = 0 ;i < numMedicos ; i++){
        for (int j= 0 ; j < numConsultas ; j++){
            if (medicos[i].codigo == consultas[j].codigo){
                medicos[i].aporte.aporte+=medicos[i].sueldo;
            }
        }
    }
}
void  ordenarAportes(struct Medicos *medicos,int numMedicos){
    for (int i = 0 ; i < numMedicos-1 ; i++){
        for (int j=i+1 ; j <numMedicos ; j++){
            if (medicos[i].aporte.aporte<medicos[j].aporte.aporte){
                cambiarS(medicos,i,j);
            }
        }
    }
}
void cambiarS(struct Medicos *medicos,int i , int j){
    struct Medicos aux ; 
    aux = medicos [i];
    medicos [i] = medicos[j];
    medicos[j] = aux ;
}