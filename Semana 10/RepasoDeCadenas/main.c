/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 9 de junio de 2019, 10:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesCadenas.h"
#include <string.h>
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archNombre, *archApellido ; 
    archNombre = abrirArchivo("nombres.txt","r");
    archApellido = abrirArchivo("apellidos.txt","r");
    char *nombre[20], *apellido[20];
    int numDatos = 0 ;
    while (1){
        nombre[numDatos] = leerCadenaExacta(archNombre);
        apellido[numDatos] = leerCadenaExacta(archApellido);
        if (nombre[numDatos] == NULL) break;
        strcat(nombre[numDatos],"/");
        strcat(nombre[numDatos],apellido[numDatos]);
        numDatos++;
    }
    for (int i = 0 ; i <numDatos ; i++ ){
        printf ("%s\n" , nombre[i]);
    }
    ordenarDatos(nombre,numDatos);
    printf ("ORDENADO\n");
    for (int i = 0 ; i <numDatos ; i++ ){
        printf ("%s\n" , nombre[i]);
    }
    return (EXIT_SUCCESS);
}

