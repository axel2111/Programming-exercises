/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 10:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archCuentos = abrirArchivo("cuento.txt", "r");
    FILE *archReporte = abrirArchivo ("reporte.txt","w");
    char nombre[50] , titulo[50] , linea[500];
    char  *palabras[50] , *sinonimos[50];
    int numPalabras = 0 ;
    int palabrasUsadas[50]  ={0}; 
    char palindromas[500];
    leerPalabrasSinonimos(palabras,sinonimos,&numPalabras);
    leerDatos(nombre,archCuentos);
    leerDatos(titulo,archCuentos);
    fprintf (archReporte,"ALUMNO: %s\n",nombre);
    fprintf (archReporte,"TITUTLO: %s\n" , titulo);
    int cantidad=1;
    while (1){
        leerDatos(linea,archCuentos);
        if (feof(archCuentos))break;
        contarPalabrasUsadas(linea,palabras,palabrasUsadas,numPalabras);
        reemplazarSinonimos(linea,palabras,sinonimos,numPalabras,archReporte);
        obtenerPalindromas(palindromas,linea,&cantidad);
    }
    fprintf (archReporte,"\nUSO DE LAS PALABRAS INDICADAS\n");
    for (int i = 0 ; i < numPalabras;i++){
        fprintf (archReporte,"%-10s - %8d\n" , palabras[i] , palabrasUsadas[i]);
    }
    fprintf (archReporte,"PALABRAS PALINDROMAS UTILIZADAS:\n %s" , palindromas);

    return (EXIT_SUCCESS);
}

