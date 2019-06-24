/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de abril de 2019, 06:05 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    FILE *archDatos, *archReporte ; 
    char c ; 
    char espacio = ' ';
    archDatos = fopen("datos.txt" , "r") ;
    archReporte = fopen("Reporte.txt" , "w") ; 
    
    if (archDatos == NULL ){
        printf ("Error el archivo datos no existe.\n");
        exit (1);
    }
    if (archDatos == NULL ){
        printf ("Error el archivo datos no existe.\n");
        exit (1);
    }
    
    while (1){
        c = fgetc(archDatos);
        if (feof(archDatos))break;
        if (c>=' ')putchar(c);
        else printf ("%d \n" ,c); // Imprime como 10 al separador de linea
    }
    fclose(archDatos);
    fclose(archReporte);
    return (EXIT_SUCCESS);
}

