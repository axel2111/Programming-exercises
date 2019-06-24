/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 12 de mayo de 2019, 04:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAX_CAR 80
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archClientes , *archPremios , *archVentas , *archProductos,*reporte ; 
    
    archClientes  = fopen ("clientes.txt","r");
    if (archClientes == NULL ){
        printf ("error , el archivo clientes.txt no pudo abrirse\n") ; 
        exit (1);
    }
    archPremios  = fopen ("premios.txt","r");
    if (archPremios == NULL ){
        printf ("error , el archivo premios.txt no pudo abrirse\n") ; 
        exit (1);
    }
    archVentas  = fopen ("ventas.txt","r");
    if (archVentas == NULL ){
        printf ("error , el archivo ventas.txt no pudo abrirse\n") ; 
        exit (1);
    }
    archProductos  = fopen ("productos.txt","r");
    if (archProductos == NULL ){
        printf ("error , el archivo productos.txt no pudo abrirse\n") ; 
        exit (1);
    }
    reporte  = fopen ("reporte.txt","w");
    if (reporte == NULL ){
        printf ("error , el archivo reporte.txt no pudo abrirse\n") ; 
        exit (1);
    }
    printf ("                       MI TIENDA S.A\n");
    printf ("                      Relacion de clientes ganadores de premios\n");
    imprimirLinea('=',MAX_CAR);
    obtenerReporte(archClientes , archPremios , archVentas , archProductos,reporte);
    cerrarArchivos (archClientes , archPremios , archVentas , archProductos,reporte);
    printf ("EXITTTTTT: %d\n",EXIT_SUCCESS);
    return (EXIT_SUCCESS);
}

