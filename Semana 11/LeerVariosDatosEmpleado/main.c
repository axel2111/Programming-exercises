/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 12 de junio de 2019, 08:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *arch = abrirArchivo ("personal.csv","r");
    int codigo[50];
    double sueldo [50];
    char *nombre[50];
    int numEmpleados= 0 ;
    
    leerDatosEmpleado(arch ,codigo,sueldo,nombre,&numEmpleados);
    for (int i = 0 ;i < numEmpleados ;i++){
        printf ("%6d %-40s %10.2lf \n" ,codigo[i],nombre[i],sueldo[i]);
    }
 
    ordenarDatosEmpleado(codigo,sueldo,nombre,numEmpleados);
    printf ("DATOS ORDENADOS \n\n");
    for (int i = 0 ;i < numEmpleados ;i++){
        printf ("%6d %-40s %10.2lf \n" ,codigo[i],nombre[i],sueldo[i]);
    }

    return (EXIT_SUCCESS);
}

