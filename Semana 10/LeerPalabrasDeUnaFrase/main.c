/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 12:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char *frase , *palabra[50];
    int numDatos = 0 ; 
    frase = leerCadenaExacta(stdin);
    sacarPalabra(frase,palabra,&numDatos);
    for (int i = 0 ; i < numDatos ; i++){
        printf ("%s\n" , palabra[i]);
    }
    return (EXIT_SUCCESS);
}

