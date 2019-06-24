/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 23 de mayo de 2019, 07:52 PM
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
    int numDatos ; 
    leerDatos (dni , telefono , sueldo, &numDatos);
    ordenarDatos(dni,telefono,sueldo,numDatos);
    printf ("=======DATOS ORDENADOS======\n");
    imprimirDatos(dni,telefono,sueldo,numDatos) ; 
    return (EXIT_SUCCESS);
}

