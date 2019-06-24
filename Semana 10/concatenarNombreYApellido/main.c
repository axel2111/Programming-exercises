/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 6 de junio de 2019, 01:47 PM
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
    archNombre = abrirArchivo ("nombres.txt", "r");
    archApellido = abrirArchivo ("apellidos.txt", "r");
    char *nombre , *apellido ; 
    while (1){
        nombre = leerCadenaExacta(archNombre);
        apellido = leerCadenaExacta(archApellido);
        if (nombre == NULL) break;
        if (apellido == NULL) break;

        nombre = crecerPuntero (nombre, 30);

        strcat(nombre,"/");
        strcat(nombre,apellido);
        printf ("%s\n", nombre); 
        free(nombre);
    }
    return (EXIT_SUCCESS);
}

