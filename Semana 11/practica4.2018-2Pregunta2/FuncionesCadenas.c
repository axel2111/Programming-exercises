/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FuncionesCadenas.h"

FILE *abrirArchivo (char *nombArch  ,char *modo){
    FILE *arch;
    arch = fopen (nombArch,modo);
    if (arch == NULL){
        printf ("Error , el archivo %s no existe\n" , nombArch);
        exit (1);
    }
    return arch;
}

void leerFrase(char *cadena,FILE *arch){
    char cadAux[100];
    int palabra=1;
    while (1){
        fscanf (arch, "%s" , cadAux );
        if (feof(arch))break;
        if (palabra==1){
            copiarCadena(cadena,cadAux);
            palabra++;
        }
        else{
            concatenar(cadena," ");
            concatenar(cadena,cadAux);
            
        }
        
        
    }
}
void nombrePropio(char *cadena){
    int i = 0 , palabra=1; 
    int numCar=lonCad(cadena);
    for (i ; i < numCar ; i++){
        if (palabra ==1){
            cadena[i] = (cadena[i]>='a' && cadena[i]<='z')?cadena[i]-32:cadena[i];
            palabra++;
        }
        if (cadena[i] == ' '){
            cadena[i+1] = (cadena[i+1]>='a' && cadena[i+1]<='z')?cadena[i+1]-32:cadena[i+1];
        }
    }
    printf ("\n%s\n" , cadena ); 
}
void concatenar(char *destino,char *fuente){
    int i = 0 ;
    i = lonCad(destino);
    copiarCadena(&destino[i],fuente);
}
void copiarCadena(char *destino,char *fuente){
    int i =  0 ;
    while (1){
        destino[i] = fuente [i] ;
        if (fuente[i] == 0 ) break;
        i++;
    }
}
int lonCad(char *cad){
    int i =0 ;
    while (1){
        if (cad[i]==0) break;
        i++;
    }
    return i ;
}
int subConjunto(char *cadena1,char *cadena2){
    int i = 0 ,contador=0;
    int numCar1 = lonCad(cadena1);
    int numCar2 = lonCad(cadena2);
    int cumple = 0 ;
    while(cadena2[i]!=0){
        for (int j = 0 ; j <numCar1 ;j++){
            if (cadena1[j] == cadena2[i]){
                contador++;
                break;
            }
        }
        i++;
    }
    
    if (contador == numCar2 ) return 1;
    else return 0;
     
}
void codigoAleatorio(char *codigo,char *cadena){
    srand(time(NULL));
    char mayusculaC[5];    
    int mayuscula;
    mayuscula = 'A' + rand()%('Z'-'A');
    mayusculaC[0] = (char)mayuscula;
    printf ("CODIGO ALEATORIO : %s\n" , mayusculaC);

}