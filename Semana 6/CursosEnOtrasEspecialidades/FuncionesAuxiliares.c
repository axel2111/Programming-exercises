/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_CARAC   60
void  cerrarArchivos(FILE *archEspecialidades,FILE *archCursos,FILE *archAlumnos,FILE *archNotas,FILE *archReporte){
    fclose (archEspecialidades);
    fclose (archCursos);
    fclose (archAlumnos);
    fclose (archNotas);
    fclose (archReporte);
}
void  obtenerReporte(FILE *archEspecialidades,FILE *archCursos,FILE *archAlumnos,FILE *archNotas,FILE *archReporte){
    int codAlumno , codEspecialidadA; 
    fscanf (archAlumnos , "%d %d" ,&codAlumno , &codEspecialidadA );
    fprintf (archReporte, "                    INSTITUO DE EDUCACION SUPERIOR\n");
    fprintf (archReporte, "                    ALUMNOS DE LA INSTITUCION MATRICULADOS EN\n");
    fprintf (archReporte, "                    CURSOS DE ESPECIALIDADES DISTINTAS A LA SUYA\n");
    imprimirLinea ('=' , MAX_CARAC, archReporte);
    fprintf (archReporte,"Alumno: %d                    Especialidad:%d\n", codAlumno,codEspecialidadA);
    imprimirLinea ('-' ,MAX_CARAC,archReporte);
    fprintf (archReporte, "REPORTE DE CURSOS LLEVADOS EN OTRA ESPECIALIDAD\n");
    fprintf (archReporte, "ESPECIALIDADES  NUMERO DE CURSOS  CREDITOS MATRICULADOS CREDITOS APROBADOS\n");
    mostrarCursosLlevados();
    imprimirLinea ('=' ,MAX_CARAC,archReporte);
    
}
void imprimirLinea (char car , int MAX_CARAC ,FILE *archReporte){
    
}
