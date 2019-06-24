/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de abril de 2019, 04:57 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDatos, *archReporte ;
    int dato,cont=0;
    int suma=0;
    double promedio;
    archDatos = fopen ("datos.txt" , "r");
    archReporte = fopen ("Reporte.txt", "w");
    
    if (archDatos == NULL){
        printf ("Error, no se ha podido abrir el archivo datos.txt\n");
        exit (1);
    }// VALIDACION DE EL ARCHIVO DE DATOS
    if (archReporte == NULL){
        printf ("Error, no se ha podido abrir el archivo Reporte.txt\n");
        exit (1);
    }//VALIDACION DE EL ARCHIVO DE REPORTE
    fprintf (archReporte,"Reporte de datos:\n");
    while (1){
     fscanf(archDatos , "%d" , &dato);
     if (feof(archDatos))break;
      
     suma += dato ; 
     cont++;
     fprintf (archReporte,"%2d): %5d\n" , cont , dato);
    }
    
    promedio = (double)suma / cont ; 
    fprintf (archReporte,"Se ingresaron: %10d datos\n", cont);
    fprintf (archReporte,"El promedio de todos los datos es: %10.2lf\n", promedio);
    fclose(archDatos);
    fclose(archReporte);
    return (EXIT_SUCCESS);
}

