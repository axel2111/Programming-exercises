/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 22 de mayo de 2019, 01:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archCursos , *archAlumnos ,*archNotas , *archMatricula ,*archCorregido
            ,*archInfractores;
    archCursos = fopen ("cursos2.txt","r");
    if (archCursos == NULL ){
        printf ("error , el archivo cursos.txt no existe") ; 
        exit (1);
    }
    archAlumnos = fopen ("alumnos2.txt","r");
    if (archAlumnos == NULL ){
        printf ("error , el archivo alumnos.txt no existe") ; 
        exit (1);
    }
    archNotas = fopen ("notas2.txt","r");
    if (archNotas == NULL ){
        printf ("error , el archivo notas.txt no existe") ; 
        exit (1);
    }
    archMatricula = fopen ("matricula2.txt","r");
    if (archMatricula == NULL ){
        printf ("error , el archivo matricula.txt no existe") ; 
        exit (1);
    }
    archCorregido = fopen ("corregido.txt" , "w");
    if (archCorregido == NULL ){
        printf ("error , el archivo corregido.txt no existe") ; 
        exit (1);
    }
    archInfractores = fopen ("infractores.txt" , "w");
    if (archCorregido == NULL ){
        printf ("error , el archivo infractores.txt no existe") ; 
        exit (1);
    }
    obtenerReporte (archCursos , archAlumnos ,archNotas , archMatricula,archCorregido,archInfractores);
    cerrarArchivos (archCursos , archAlumnos ,archNotas , archMatricula,archCorregido,archInfractores);
                
    return (EXIT_SUCCESS);
}

