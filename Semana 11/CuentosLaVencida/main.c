/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 11 de junio de 2019, 03:12 PM
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *archCuento = abrirArchivo ("cuentos.txt","r");
    FILE *archPalabras = abrirArchivo ("palabras.txt","r");
    FILE *archSinonimos = abrirArchivo ("sinonimos.txt", "r");
    FILE *archReporte = abrirArchivo ("reporte.txt", "w");
   
    char nombre[50],titulo[100],linea[500];
    leerCadena(nombre,50,archCuento);
    leerCadena(titulo,100,archCuento);
    int oraciones = 0 ; 
    char *palabras[50]; int numPalabras = 0 ;//GUARDA LOS DATOS DEL ARCHIVO palabras.txt
    char *sinonimos[50]; int numSinonimos = 0  ; // GUARDA LOS SINONIMOS DEL ARCHIVO sinonimos.txt;
    int palabrasRepetidas[50]={0}; // GUARDA EL NUMERO DE VECES QUE SE REPITE CADA PALABRA;
    char palindromas[200] ; int primera = 1  ;  
    int totalPalabras = 0 ;
    leerPalabras(palabras,archPalabras,&numPalabras);
    leerPalabras(sinonimos,archSinonimos,&numSinonimos);
    fprintf (archReporte,"ALUMNO: %s\n", nombre);
    fprintf (archReporte,"TITULO: %s\n",titulo);
    while (1){
        leerCadena(linea,500,archCuento);
        if (feof(archCuento))break;
        oraciones += obtenerOraciones(linea);
        totalPalabras+=sumarPalabras(linea);
        obtenerPalabrasRepetidas(palabras,numPalabras,palabrasRepetidas,linea);
        corregirTexto(linea,sinonimos,palabras,numPalabras,archReporte);
        palabrasPalindromas(linea,palindromas,&primera);
        
    }
    fprintf (archReporte,"EL TOTAL DE PALABRAS ES %d\n" , totalPalabras);
    fprintf (archReporte,"\nCANTIDAD DE ORACIONES EN EL CUENTO %d\n" , oraciones);
    fprintf (archReporte,"\nUSO DE LAS PALABRAS INDICADAS: \n");
    for (int i = 0 ; i < numPalabras ;i++){
        fprintf (archReporte,"%-8s - %d\n" , palabras[i],palabrasRepetidas[i] );
    }
    fprintf (archReporte,"\nPALABRAS PALINDROMAS UTILIZADAS: \n %s" , palindromas);
    return (EXIT_SUCCESS);
}
