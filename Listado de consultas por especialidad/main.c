/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 9 de mayo de 2019, 12:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDoctor, *archEspecialidad, *archPaciente , *archConsultas , *reporte ;
    
    archDoctor  = fopen ("doctor.txt" , "r"); 
    if (archDoctor == NULL) {
        printf ("Error el archivo doctor.txt , no existe\n");
        exit (1);
    }
    archEspecialidad  = fopen ("especialidad.txt" , "r"); 
    if (archEspecialidad == NULL) {
        printf ("Error el archivo especialidad.txt , no existe\n");
        exit (1);
    }
    archPaciente  = fopen ("paciente.txt" , "r"); 
    if (archPaciente == NULL) {
        printf ("Error el archivo pacientes.txt , no existe\n");
        exit (1);
    }
    archConsultas  = fopen ("consulta.txt" , "r"); 
    if (archConsultas == NULL) {
        printf ("Error el archivo consulta.txt , no existe\n");
        exit (1);
    }
    reporte  = fopen ("reporte.txt" , "w"); 
    if (reporte == NULL) {
        printf ("Error el archivo doctor.txt , no existe\n");
        exit (1);
    }
    
    int dI,mI,aI,dF,mF,aF;
    int fechaI , fechaF;
    fprintf (reporte,"                   CLINICA SU SALUD S.A\n");
    fprintf (reporte,"                   LISTADO DE CONSULTAS\n");
    printf ("  Desde: "), scanf ("%d/%d/%d" ,&dI,&mI,&aI );
    printf ("  Hasta: "), scanf ("%d/%d/%d" ,&dF,&mF,&aF );
    fechaF = (aF*10000+mF*100+dF);
    fechaI = (aI*10000+mI*100+dI);
    fprintf (reporte,"  Desde: %02d/%02d/%d               Hasta: %02d/%02d/%d\n",dI,mI,aI,dF,mF,aF);
    obtenerReporte (archDoctor, archEspecialidad, archPaciente , archConsultas , reporte ,fechaI,fechaF);
    cerrarArchivos (archDoctor, archEspecialidad, archPaciente , archConsultas , reporte);
    return (EXIT_SUCCESS);
}

