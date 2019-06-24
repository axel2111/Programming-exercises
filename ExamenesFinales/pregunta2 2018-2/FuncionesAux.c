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
    arch= fopen (nombre,modo);
    if (arch == NULL ){
        printf ("Error el archivo %s no existe\n",nombre);
        exit (1);
    }
    return arch; 
}
void leerCadena(char *cadAux,int numCar,FILE *arch){
    int i ;
    fgets (cadAux , numCar,arch);
    i = strlen(cadAux);
    cadAux [i-1] = 0 ;
}
char *leerCadenaExacta (FILE *arch){
    char cadAux[200] , *cad;
    leerCadena(cadAux,200,arch);
    if (feof(arch))return NULL;
    cad= (char*)malloc (sizeof (char)*(strlen(cadAux)+1));
    strcpy(cad,cadAux);
    return cad;
}
void leerDatosConsulta(int *conMed,int *numConsultas){
    FILE *archConsultas= abrirArchivo ("consultas.txt","r");
    (*numConsultas) = 0 ;
    int a,b,c ,d;
    int consultasMed; 
    while (1){
        fscanf (archConsultas,"%d/%d/%d %d %d",&a,&b,&c,&d , &consultasMed);
        if (feof(archConsultas))break;
        conMed[*numConsultas] = consultasMed;
        (*numConsultas)++;
    }
}
void sacarPalabras(char *frase , char **palabras,int *numPal ,char *separador ) {
    int i = 0 , j ;
    char cadAux[200] , *cad;
    (*numPal)=0;
    while (1){
        while (frase[i]==separador[0])i++;
        if (frase[i] == 0 )break;
        j=0;
        while (frase[i]!=separador[0] && frase[i]!= 0){
            cadAux[j] = frase[i];
            i++;
            j++;
        }
        cadAux[j] = 0 ;
        cad = (char*)malloc (sizeof (char)*(strlen(cadAux)+1));
        strcpy(cad,cadAux);
        palabras[*numPal] = cad; 
        (*numPal)++;
    }
}
void leerDatosMedico(int *codigo,double *tarifa,char **nombre,char **especialidad,int *numMed){
    FILE *archMedicos = abrirArchivo("Medicos.txt","r");
    char *palabras[60];int numPal = 0 ; 
    char *frase , *cadAux ,*cadAux2; 
    (*numMed) = 0 ;
    while (1){
        frase = leerCadenaExacta (archMedicos);
        if (frase==NULL)break;
        sacarPalabras(frase , palabras,&numPal,",");
        codigo[*numMed] = atoi(palabras[0]);
        tarifa[*numMed] = atof(palabras[3]);
        cadAux = (char*) malloc (sizeof (char )*(strlen(palabras[1])+1));
        strcpy(cadAux,palabras[1]);
        nombre[*numMed] = cadAux;
        cadAux2 = (char*) malloc (sizeof (char )*(strlen(palabras[2])+1));
        strcpy(cadAux2,palabras[2]);
        especialidad[*numMed] = cadAux2;
        (*numMed)++;
        
    }
}
void  mostrarReporte(int *codigo,double *tarifa,char **nombre,char **especialidad,
                    int numMed,int *conMed,int numConsultas){
    double aporte[200]= {0};
    obtenerAportes(codigo,conMed,tarifa,numMed,numConsultas,aporte);
    ordenarAportes(codigo,nombre,especialidad,aporte,numMed);
    for (int i = 0 ; i < 5 ;i++){
        printf ("%d.-  %6d %-30s %-20s  %.2lf\n",i+1 , codigo[i],nombre[i],especialidad[i],aporte[i]);
    }
    
}
void ordenarAportes(int *codigo,char **nombre,char **especialidad,double *aporte,int numMed){
    for (int i = 0 ;i < numMed-1 ; i++){
        for (int j= i+1 ; j <numMed; j++){
            if (aporte[i] < aporte[j]){
                cambiarI(codigo,i,j);
                cambiarC(nombre,i,j);
                cambiarC(especialidad,i,j);
                cambiarD(aporte,i,j);
            }
        }
    }
}
void cambiarI(int *arr ,int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux; 
}
void cambiarD(double *arr ,int i, int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux; 
}
void cambiarC(char **arr ,int i, int j){
    char *aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux; 
}
void obtenerAportes(int *codigo,int *conMed,double *tarifa,int numMed,int numConsultas,double *aporte){
    for (int i = 0 ; i < numMed ; i++){
        for (int j=0 ; j < numConsultas ; j++){
            if (codigo[i] == conMed[j]){
                aporte[i] += tarifa[i];
            }
        }
    }
}