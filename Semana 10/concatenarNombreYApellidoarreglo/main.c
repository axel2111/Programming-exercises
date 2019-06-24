/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 6 de junio de 2019, 04:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archNombre,*archApellido;
    archNombre = abrirArchivo("nombres.txt", "r");
    archApellido = abrirArchivo("apellidos.txt", "r");
    
    char *nombre[20];
    int numDatos = 0 ; 
    while (1){
        nombre[numDatos] = leerCadenaExacta(archNombre);
        if (nombre[numDatos] == NULL)break;
        numDatos++;
    }
    for (int i = 0 ; i < numDatos ;i++){
        printf ("%s\n" , nombre[i]);
    }
    
    return (EXIT_SUCCESS);
}

