/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 24 de mayo de 2019, 02:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int dni[100] , telefono[100];
    double sueldo [100] ; 
    int numDatos  = 0 ;
    int dniBuscar , pos; 
    leerDatos (dni , telefono , sueldo,&numDatos) ; 
    ordenarDatos(dni,telefono,sueldo,numDatos);
    imprimirDatos(dni,telefono,sueldo , numDatos);
    printf ("Ingrese dni: "), scanf ("%d" , &dniBuscar);
    pos = busquedaSecuencial(dni,dniBuscar,numDatos);
    if (pos>=0)
        printf ("%2d)  %8d  %9d  %8.2lf\n" ,pos+1, dni[pos],telefono[pos],sueldo[pos]);
    else printf ("No se encontro el dato ingresado\n");
    return (EXIT_SUCCESS);
}

