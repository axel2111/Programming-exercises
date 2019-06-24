/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 12 de junio de 2019, 05:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char nombre[100] ;
    int codigo ;
    double sueldo ; 
    
    leerDatosEmpleado(stdin,nombre,&codigo,&sueldo);
    printf ("\n\n%-25s %8d %8.2lf\n" , nombre , codigo , sueldo);
    return (EXIT_SUCCESS);
}

