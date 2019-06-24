/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LeerFunciones.h"
#include "Facturas.h"
#include "Cadenas.h"

void leerFacturas(struct Facturas *facturas, int *numFacturas ){
    FILE *arch= fopen ("facturas.txt","r");
    char *palabras[100] ; int numPal = 0 ; 
    char *frase ; 
    int numProd = 0 ; 
    int i = 0 ;
    (*numFacturas) = 0 ; 
    while (1){
        frase = leerCadenaExacta (arch);
        if (frase== NULL )break; 
        sacarPalabra(frase, palabras,&numPal, ",");
        facturas[*numFacturas].persona.dni = atoi (palabras[0]);
        facturas[*numFacturas].persona.nombre = (char*)malloc (sizeof (char) *(strlen(palabras[1])+1));
        strcpy (facturas[*numFacturas].persona.nombre , palabras[1]);
        leerFechas(facturas,numFacturas , palabras[2]);
        numProd = (numPal-3) / 3 ;
        int m =0 ;
        facturas[*numFacturas].compras = (struct Productos*)malloc (sizeof(struct Productos)*numProd);
        for (int i = 0 ;i < numProd;i++){
            strcpy (facturas[*numFacturas].compras[i].codigo,palabras[3+m]);
            facturas[*numFacturas].compras[i].cant=atoi(palabras[4+m]);
            facturas[*numFacturas].compras[i].precio=atof(palabras[5+m]);
            facturas[*numFacturas].total += (facturas[*numFacturas].compras[i].cant*
                    facturas[*numFacturas].compras[i].precio);
            m +=3;
        }
        
        (*numFacturas) ++;
    }
}
void leerFechas (struct Facturas *facturas,int *numFacturas ,char *fecha){
      char *palabras[100] ; int numPal = 0 ; 
      sacarPalabra(fecha , palabras,&numPal,"/");
      facturas[*numFacturas].fecha.dd = atoi(palabras[0]);
      facturas[*numFacturas].fecha.mm =atoi (palabras[1]);
      facturas[*numFacturas]. fecha.aa = atoi(palabras[2]);
}
void  ordenarDatos(struct Facturas *facturas,int numFacturas){
    for (int i = 0 ; i < numFacturas-1;i++){
        for (int j = i+1 ; j < numFacturas;j++ ){
            if (facturas[i].total < facturas[j].total){
                cambiarS(facturas,i,j);
            }
        }
    }
}
void cambiarS(struct Facturas *facturas,int i,int j){
    struct Facturas aux ; 
    aux = facturas[i];
    facturas[i] = facturas[j];
    facturas[j] = aux ;
}