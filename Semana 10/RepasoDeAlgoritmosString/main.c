/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 9 de junio de 2019, 11:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"


/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDatos , *archCopiar;
    archDatos = abrirArchivo("datos.txt", "r");
    archCopiar = abrirArchivo("copiar.txt", "w");
    
    char palabra[50] , cadena[50];

    leerCadena(palabra,50,stdin);
    leerCadena(cadena,50,stdin);
    copiarCadena(cadena, palabra);

    concatenarCadena(palabra," juan");
    return (EXIT_SUCCESS);
}

