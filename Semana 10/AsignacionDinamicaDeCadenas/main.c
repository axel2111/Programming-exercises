/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 6 de junio de 2019, 11:37 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesCadenas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char cad[20] , *p ;
/*
    leerCadena(cad,50,stdin);
    printf ("%s\n" , cad);
    p = cad ;
    printf ("%s\n" , p );
    p = &cad[3];
    printf ("%s\n" , p );
*/
/*
    p = (char *) malloc (sizeof(char) * 100);
    leerCadena(p,100,stdin);
    printf ("%s\n" , p );
    
*/
    

    FILE *datos;
    datos = abrirArchivo ("datos.txt" , "r");
/*
    int i = 0 ;
    while (1){
        i++;
        p = leerCadenaExacta (datos); 
        if (p == NULL)break;
        printf ("%d) cadena exacta %s %d \n",i, p , strlen(p));  
        free(p);
    }
*/
/*
    int longitud;
    p=leerCadenaExacta (stdin);
    longitud = strlen(p);
    printf ("Cadena exacta %s %d\n" , p ,longitud);

    p = crecerPuntero (p , 30);
    strcat(p," perez");
    printf ("%s\n" ,p);
    
*/
    char *persona[50];
    int numDat= 0 ;
    while (1){
        persona[numDat]= leerCadenaExacta(datos);
        if (persona[numDat]==NULL)break;
        numDat++;
    }
    
    for (int i =0 ; i < numDat ; i++){
        printf ("%s\n" , persona[i]);
    }
    return (EXIT_SUCCESS);
}

