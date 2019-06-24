/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 9 de junio de 2019, 12:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#include <string.h>
#include "FuncionesDinamica.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char cadena[50] ,*palabra;  ;
    palabra = leerCadenaExacta(stdin);
    printf ("CADENA EXACTA : %s",palabra);
    return (EXIT_SUCCESS);
}

