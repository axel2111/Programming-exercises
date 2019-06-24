/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAuxiliares.h"
#define CAR_MAX 80
void obtenerReporte (FILE *archDoctor, FILE *archEspecialidad, FILE *archPaciente ,FILE *archConsultas ,FILE *reporte, int fechaI,int fechaF){
    int codEspecialidad;
    double tarifa ; 
    while (1){
        fscanf (archEspecialidad, "%d %lf" , &codEspecialidad , &tarifa);
        if (feof (archEspecialidad))break;;
        imprimeLinea ('=',CAR_MAX);
        printf ("Especialidad:    %d" , codEspecialidad) ; 
        printf ("Costo de la consulta: %.2lf" , tarifa);
        imprimeLinea('=' , CAR_MAX); 
        mostrarDoctor(codEspecialidad,tarifa,archDoctor,archPaciente,archPaciente);
    }
}
void mostrarDoctor(int codEspecialidad, double tarifa,FILE *archDoctor,FILE *archPaciente,FILE *archConsultas){
    int codDoctor , codEspecialidadDoctor;
    int consultas = 0 ; 
    while (1){
        fscanf (archDoctor,"%d %d",&codDoctor, &codEspecialidadDoctor);
        if (feof (archDoctor))break;
        if (codEspecialidadDoctor ==codEspecialidad){
            consultasEspecialidad(&consultas , codDoctor , tarifa, archPaciente,archConsultas);
            if (consultas>0){
                printf ("Doctor: %d" , codDoctor);
                imprimeLinea('-',CAR_MAX);
            }
        }
    }
}

void consultasEspecialidad(int *consultas ,int  codDoctor ,double tarifa, FILE *archPaciente,FILE *archConsultas);

void imprimeLinea (char c , int maxCar){
    for (int i = 0 ; i < maxCar ; i++){
        printf ("%c" , c ); 
    }
    printf ("\n");
}
void cerrarArchivos (FILE *archDoctor, FILE *archEspecialidad, FILE *archPaciente ,FILE *archConsultas ,FILE *reporte){
    fclose (archDoctor);
    fclose (archEspecialidad);
    fclose (archPaciente);
    fclose (archConsultas);
    fclose (reporte);
}
*/

