/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"

void reescribirArticulos(int *codArt, double *precioU, double *precioD, int *stock,
        int *numArt) {
    leerArticulos(codArt, precioU, precioD, stock, &numArt);
}

void leerArticulos(int *codArt, double *precioU, double *precioD, int *stock,
        int *numArt) {

    FILE *archArticulos;
    archArticulos = fopen("articulos.txt", "r");
    if (archArticulos == NULL) {
        printf("error , el archivo articulos.txt no pudo abrir");
    }
}
