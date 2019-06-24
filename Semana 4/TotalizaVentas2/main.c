/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de abril de 2019, 07:00 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fileVentas , *reporte;
    int codigo, contVentas ; 
    double sumaVentas , ventas; 
    double promedioV;
    char c , d; 
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
    

    while (1){
        sumaVentas = 0 ; 
        contVentas = 0;
        fscanf (fileVentas,"%d" , &codigo);

        d = fgetc(fileVentas);
        
        if (d == '\n'){
            fprintf (reporte,"  %d \tNO TUVO NINGUNA VENTA EN EL DIA\n" ,codigo); 
            continue;
        }

        
        if ( feof(fileVentas)) break; 
        
        while (1){
            fscanf (fileVentas, "%lf" , &ventas);
            sumaVentas+=ventas ;
            contVentas++;
            c = fgetc(fileVentas) ; 
            if (c == '\n')break; 
        }
        promedioV =  sumaVentas / contVentas ; 
        fprintf(reporte, "%10d %10d %12.2lf %12.2lf\n" , codigo, contVentas
                                                , sumaVentas , promedioV);
    } 
    fclose (fileVentas);
    fclose (reporte);
    return (EXIT_SUCCESS);
}

