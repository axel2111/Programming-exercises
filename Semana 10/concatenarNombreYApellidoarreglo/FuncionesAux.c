/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"

FILE *abrirArchivo(char *nombArch, char *modo){
    FILE *arch;
    arch = fopen (nombArch,modo);
    if (arch==NULL){
        printf ("Error, el archivo %s no existe",nombArch);
        exit(1);
    }
    return arch ; 
}
void leerCadena (char *cad , int numCar , FILE *arch){
    int i ;
    fgets (cad,numCar , arch); 
    i = strlen (cad) ; 
    cad[i-1] = 0 ; 
}
char *leerCadenaExacta(FILE *arch){
    char cadAux[50] , *cad ;
    leerCadena(cadAux,50,arch);
    if (feof(arch))return NULL;
    cad = (char*)malloc (sizeof (char)*(strlen(cadAux)+1));
    strcpy(cad,cadAux);
    return cad;
}

