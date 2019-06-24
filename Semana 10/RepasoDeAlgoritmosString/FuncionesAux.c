/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#include <string.h>
FILE *abrirArchivo(char *nombArch,char *modo){
    FILE *arch ;
    arch = fopen (nombArch,modo);
    if (arch == NULL){
        printf ("Error, no se pudo abrir el archivo %s " , nombArch) ; 
        exit (1);
    }
    return arch ; 
}
void leerCadena(char *cad,int numCar,FILE *arch){
    int i ;
    fgets(cad,numCar,arch);
    i = lonCad(cad);
    cad[i-1] = 0 ;
}
int lonCad(char *cad){
    int i =0 ; 
    while (cad[i]!=0){
        i++;
    }
    return i ; 
}
void copiarCadena(char *destino, char *origen){
    int i=0;
    while (1){
        destino[i] = origen[i];
        if (destino[i] == 0)break;
        i++;
    }
/*
    int numCaracteres = lonCad(origen);
    for (i ; i < numCaracteres ; i++){
        destino[i] = origen[i];
    }
    destino [i] = 0 ; 
*/
    printf ("CADENA COPIADA: %s\n" , destino);
}
void concatenarCadena(char *destino,char *fuente){
    int i ;
    i = lonCad(destino);
    copiarCadena(&destino[i],fuente);
    printf ("CADENA CONCATENADA %s" , destino );
}