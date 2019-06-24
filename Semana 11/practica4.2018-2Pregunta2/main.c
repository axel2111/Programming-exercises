/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 02:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesCadenas.h" 
/*
 * 
 */
int main(int argc, char** argv) {
    char cadena[100] , cadena2[100] ;
    FILE *datos = abrirArchivo ("datos.txt" , "r");
    FILE *datos2= abrirArchivo ("datos2.txt","r");
    int sub;
    leerFrase(cadena,datos);
    printf ("CADENA CORREGIDA \n%s" , cadena);
    nombrePropio(cadena);
    leerFrase(cadena2,datos2);
    sub = subConjunto(cadena,cadena2);
    printf ("SUB: %d\n", sub);
    codigoAleatorio(cadena,"$$%^*$@");
    
    return (EXIT_SUCCESS);
}

