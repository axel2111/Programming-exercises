/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 5 de mayo de 2019, 10:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archCursos ,*archAlumnos , *archNotas , *archEspecialidad,*reporte;
    archCursos = fopen ("Cursos.txt", "r");
    if (archCursos == NULL){
        printf ("Error el archivo cursos.txt no se pudo abrir");
        exit (1);
    }
    archAlumnos = fopen ("Alumnos.txt", "r");
    if (archAlumnos == NULL){
        printf ("Error el archivo alumnos.txt no se pudo abrir");
        exit (1);
    }
    archNotas = fopen ("Notas.txt", "r");
    if (archNotas == NULL){
        printf ("Error el archivo notas.txt no se pudo abrir");
        exit (1);
    }
    archEspecialidad = fopen ("Especialidades.txt", "r");
    if (archEspecialidad == NULL){
        printf ("Error el archivo especialidad.txt no se pudo abrir");
        exit (1);
    }
    reporte = fopen ("reporte.txt", "w");
    if (archEspecialidad == NULL){
        printf ("Error el archivo reporte.txt no se pudo abrir");
        exit (1);
    }
    obtenerReporte(archCursos ,archAlumnos , archNotas , archEspecialidad,reporte);

    cerrarArchivos(archCursos ,archAlumnos , archNotas , archEspecialidad,reporte);
    return (EXIT_SUCCESS);
}

