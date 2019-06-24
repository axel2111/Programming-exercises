/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 2 de mayo de 2019, 08:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //ABRIR ARCHIVOS
    FILE *archEspecialidades,*archCursos,*archAlumnos,*archNotas,*archReporte;
    archEspecialidades = ("especialidades.txt" , "r");
    if (archEspecialidades==NULL){
        printf ("Error , el archivo de texto especialidades.txt no se encuentra ");
        exit (1);
    }
    archCursos = ("especialidades.txt" , "r");
    if (archCursos==NULL){
        printf ("Error , el archivo de texto cursos.txt no se encuentra ");
        exit (1);
    }
    archAlumnos = ("alumnos.txt" , "r");
    if (archAlumnos==NULL){
        printf ("Error , el archivo de texto alumnos.txt no se encuentra ");
        exit (1);
    }
    archNotas = ("notas.txt" , "r");
    if (archNotas==NULL){
        printf ("Error , el archivo de texto notas.txt no se encuentra ");
        exit (1);
    }
    archReporte = ("reporte.txt" , "w");
    if (archReporte==NULL){
        printf ("Error , el archivo de texto reporte.txt no se encuentra ");
        exit (1);
    }
    //MOSTRAR NOTAS
    obtenerReporte(archEspecialidades,archCursos,archAlumnos,archNotas,archReporte);
    //CERRAR LOS ARCHIVOS
    cerrarArchivos(archEspecialidades,archCursos,archAlumnos,archNotas,archReporte);
    return (EXIT_SUCCESS);
}

