/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 16 de junio de 2019, 12:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cadenas.h"
#include "Factura.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char *frase , *palabras[100] ;int numPal=0; 
    struct Factura factura[20] ; 
    frase = leerCadenaExacta(stdin);
    sacarPalabra(frase,palabras,&numPal,",");
    strcpy(factura[0].compra[0].codigo,palabras[3]);
    factura[0].compra[0].cant = atoi (palabras[4]);
    factura[0].compra[0].precio = atof(palabras[5]);
    printf ("\n%s %d %lf",factura[10].compra[0].codigo,factura[0].compra[0].cant,factura[0].compra[0].precio);
    return (EXIT_SUCCESS);
}

