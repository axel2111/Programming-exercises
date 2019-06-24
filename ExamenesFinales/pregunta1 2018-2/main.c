/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 13 de junio de 2019, 03:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *archLista = abrirArchivo("ListaDeArchivos.txt","r");
    char *lista[200]; int numArchivos = 0 ; 
    
    leerListaDeArchivos(lista,&numArchivos,archLista);
    ordenarArchivos(lista,numArchivos);
    char *buscar ,cadAux[25];
    leerCadena(cadAux,25,stdin);
    buscar = (char*) malloc(sizeof(char)*(strlen(cadAux)+1));
    strcpy(buscar,cadAux);
    
    obtenerReporte(buscar,lista,numArchivos);
    return (EXIT_SUCCESS);
}

