/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 6 de mayo de 2019, 06:31 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archClientes ,*archVentas, *archPremios,*archProductos,*reporte;
    archClientes = fopen ("clientes.txt","r");
    if (archClientes == NULL){
        printf ("Error, no se pudo abrir el archivo clientes.txt");
        exit (1);
    }
    archVentas = fopen ("ventas.txt","r");
    if (archVentas == NULL){
        printf ("Error, no se pudo abrir el archivo ventas.txt");
        exit (1);
    }
    archPremios = fopen ("premios.txt","r");
    if (archPremios == NULL){
        printf ("Error, no se pudo abrir el archivo premios.txt");
        exit (1);
    }
    archProductos = fopen ("productos.txt","r");
    if (archProductos == NULL){
        printf ("Error, no se pudo abrir el archivo clientes.txt");
        exit (1);
    }
    reporte = fopen ("reporte.txt","w");
    if (reporte == NULL){
        printf ("Error, no se pudo abrir el archivo reporte.txt");
        exit (1);
    }
    obtenerReporte(archClientes ,archVentas, archPremios,archProductos,reporte);
    cerrarArch(archClientes ,archVentas, archPremios,archProductos,reporte);
    return (EXIT_SUCCESS);
}

