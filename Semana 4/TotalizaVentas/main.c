/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de abril de 2019, 06:19 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fileVentas , *reporte;
    int codigo, contVentas; 
    double sumaVentas  , ventas; 
    double promedioV;
    char c ; 
    fileVentas = fopen ("Ventas.txt", "r");
    if (fileVentas == NULL){
        printf ("Error el archivo Ventas.txt no existe\n") ;
        exit (1); 
    }
    
    reporte = fopen ("Reporte.txt", "w"); 
    if (reporte == NULL){
        printf ("Error el archivo Reporte.txt no existe\n") ;
        exit (1); 
    } 
    fprintf (reporte, "CODIGO   NUM VENTAS   SUMA   PROMEDIO\n");
    while (1){
        sumaVentas = 0 ; 
        contVentas = 0;
        fscanf (fileVentas,"%d" , &codigo);
        if ( feof(fileVentas)) break; 
        while (1){
            fscanf (fileVentas, "%lf" , &ventas);
            sumaVentas+=ventas ;
            contVentas++;
            c = fgetc(fileVentas) ; 
            if (c == '\n')break; 
        }
        promedioV = (double) sumaVentas / contVentas ; 
        fprintf(reporte , "%10d %10d %10.2lf %10.2lf\n" , codigo, contVentas
                                                , sumaVentas , promedioV);
    } 
    fclose (fileVentas);
    fclose (reporte);
    return (EXIT_SUCCESS);
}

