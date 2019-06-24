/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAUX.h"
FILE *abrirArchivo (char *nombre, char *modo){
    FILE *arch;
    arch = fopen(nombre,modo);
    if (arch==NULL){
        printf ("Error , el archivo  %s no existe " , nombre);
        exit (1);
    }
    return arch;
}
void  leerDatos(char **nombre,int *operaciones,int *numOperaciones){
    FILE *archClientes = abrirArchivo ("Clientes.txt","r");
    char *frase  ,*cadAux; 
    char *palabras[500] ; int numPalabras = 0 ; 
    (*numOperaciones)=0;
    while (1){
        frase = leerCadenaExacta(archClientes);
        if (frase==NULL) break;
        sacarPalabras(frase,palabras,&numPalabras,",");
        operaciones[*numOperaciones] = atoi(palabras[1]);
        cadAux = (char*)malloc (sizeof(char)*(strlen(palabras[0])+1));
        strcpy(cadAux,palabras[0]);
        nombre[*numOperaciones] = cadAux;
        (*numOperaciones)++;
    }
    
}
void mostrarReporte(double tiempo,char **nombre,int *operaciones,int numOperaciones){
    double atencion , duracion=0; 
    printf ("               ATENCION DE CLIENTES POR ORDEN DE LLEGDA\n");
    printf ("               tiempo de transaccion %.2lf seg c/u\n" , tiempo );
    printf ("NOMBRE                    TRANSACCIONES          ATENCION(seg)       DURACION (seg)\n");
    for (int i = 0 ; i < numOperaciones ;i++){
        atencion = duracion;
        duracion += tiempo * operaciones[i];
        printf ("%-30s %2d           %12.2lf          %12.2lf\n",nombre[i],operaciones[i],atencion,duracion);
    }
}
void leerCadena(char *cad,int numCar,FILE *arch){
    int i ; 
    fgets (cad,numCar,arch);
    i = strlen (cad) ; 
    cad [i-1] = 0 ;
}
char *leerCadenaExacta(FILE *arch){
    char cadAux[200] , *cad;
    leerCadena(cadAux,200,arch);
    if (feof(arch))return NULL;
    cad = (char*)malloc (sizeof(char)*(strlen(cadAux)+1));
    strcpy(cad,cadAux);
    return cad;
}
void sacarPalabras(char *frase,char **palabras,int *numPalabras,char *separador){
    int i = 0 , j ; 
    char cadAux[200] , *cad;
    (*numPalabras)=0;
    while (1){
        while (frase[i]==separador[0])i++;
        if (frase[i]==0)break;
        j=0;
        while (frase[i]!=separador[0] && frase[i] != 0 ){
            cadAux[j] = frase[i];
            j++;
            i++;
        }
        cadAux[j] = 0 ; 
        cad = (char*)malloc (sizeof(char) *(strlen(cadAux)+1));
        strcpy(cad,cadAux);
        palabras[*numPalabras]= cad;
        (*numPalabras)++;
    }
}