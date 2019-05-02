/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 1 de mayo de 2019, 05:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //ABRIR ARCHIVOS
    FILE *archProductos,*archClientes,*archFacturas,*reporte;
    archProductos = fopen ("productos.txt","r") ;
    if (archProductos==NULL){
        printf ("Error, no se pudo abrir el archivo productos.txt ");
        exit (1);
    }
    archClientes = fopen ("clientes.txt","r") ;
    if (archClientes==NULL){
        printf ("Error, no se pudo abrir el archivo clientes.txt ");
        exit (1);
    }
    archFacturas = fopen ("facturas.txt","r") ;
    if (archFacturas==NULL){
        printf ("Error, no se pudo abrir el archivo facturas.txt ");
        exit (1);
    }
    reporte = fopen ("reporte.txt","w") ;
    if (reporte==NULL){
        printf ("Error, no se pudo abrir el archivo reporte.txt ");
        exit (1);
    }
    //IMPRIMIRFACTURAS
    imprimirFacturas(archProductos,archClientes,archFacturas,reporte);
    //CERRAR ARCHIVOS
    cerrarArchivos(archProductos,archClientes,archFacturas,reporte);

    return (EXIT_SUCCESS);
}

