/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 20 de junio de 2019, 10:36 AM
 */
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "Estudiante.h"
#include "FuncionesEstudiantes.h"
/*
 * 
 */
int main(int argc, char** argv) {
    struct Estudiante estudiante[500] ;
    int numEstudiantes= 0 ; 
    
    leerEstudiantes (estudiante , &numEstudiantes) ; 
    ordenarEstudiantes(estudiante,numEstudiantes);
    imprimirEstudiantes (estudiante , numEstudiantes) ; 
    buscarAlumnosHorario (estudiante,numEstudiantes);
    return (EXIT_SUCCESS);
}

