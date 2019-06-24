/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 4 de junio de 2019, 08:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesCadenas.h"
#include <math.h>
/*
 * 
 */
int main(int argc, char** argv) {
/*
    char palabra[100] , copiar[100] ;

    fgets (palabra,100,stdin);
    corregirCadena(palabra);

    leerCadena(palabra,100,stdin);
    printf ("%s\n" , palabra); 
    printf ("fin\n");

    copiarCadena(copiar, palabra) ; 

    strcpy(copiar,palabra);
    printf ("CADENA COPIADA %s\n" , copiar );
    printf ("MAYUSCULAS\n");
    int numLetras = strlen (palabra) ;
    for (int i= 0 ; i < numLetras ;i++){
        palabra[i] =(palabra[i]>='a' && palabra[i]<='z')?(palabra[i]-32):palabra[i];
    }
    printf ("%s\n" , palabra);
    
    printf ("Palabra con palabra[0]\n");    
    printf ("%s\n" , palabra) ;         
    
*/
    char cad1[50],cad2[50] ; 
    int compara = 0 ; 
    leerCadena (cad1 , 50 , stdin);
    leerCadena (cad2 , 50 , stdin); 
/*
    concatenarCadena(cad1,cad2);
*/
    strcat(cad1,"/");
    strcat(cad1,cad2);
    printf ("%s\n" , cad1 );

    /*
    compara = comparaCadena (cad1,cad2); 
 * compara = 0 ; son iguales
 * compara<0 cad1 < cad2 ;
 * compara>0 cad2 > cad1;
 
 */
/*
    compara = strcmp(cad1,cad2);
    if (compara == 0 ){
        printf ("Las cadenas cad1: %s y cad2: %s son iguales \n",cad1 , cad2);
    }
    else {
        printf ("Las cadenas cad1: %s y cad2: %s son diferentes \n",cad1 , cad2);
    }
*/
    return (EXIT_SUCCESS);
}

