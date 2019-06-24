/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 23 de mayo de 2019, 09:35 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int datos[100] ; 
    int numDatos ; 
    leerDatos (datos , &numDatos); 
    ordenar(datos,numDatos);
    imprimirDatos(datos,numDatos);
    return (EXIT_SUCCESS);
}

