/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 19 de mayo de 2019, 08:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAX_EMPLEADOS 100
#define MAX_CAR   80 
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archGeneral,*archReporte , *archGrafica ; 
    archGeneral = fopen ("general.txt" , "r") ; 
    if (archGeneral == NULL){
        printf ("Error el archivo general.txt , no existe") ;
        exit (1);
    }
    archReporte = fopen ("reporte.txt" , "w");
    if (archReporte == NULL){
        printf ("Erro el archivo reporte.txt no existe");
        exit (1);
    }
    archGrafica = fopen ("grafica.txt" , "w");
    if (archReporte == NULL){
        printf ("Erro el archivo grafica.txt no existe");
        exit (1);
    }
    
    double utilidadAnual , porcentaje ;
    
    fscanf (archGeneral,"%lf %lf", &utilidadAnual , &porcentaje);
       
    //SE GUARDA LOS DATOS INICIALES
    int anio ; 
    printf ("Ingrese anio: "),scanf ("%d" , &anio);
    //GUARDA LOS DATOS DE CADA EMPLEADO DEL ARCHIVO EMPLEADOS.TXT
    int codEmpleado [MAX_EMPLEADOS];
    double sueldoEmpleado[MAX_EMPLEADOS];
    int numEmpleados ; 
    leerEmpleados(&numEmpleados,codEmpleado,sueldoEmpleado);
    //LEER LA PLANILLA 
    double sueldoPlanilla[MAX_EMPLEADOS] ={0};
    int diasPlanilla[MAX_EMPLEADOS] = {0};
    leerPlanilla(anio,numEmpleados,sueldoPlanilla,diasPlanilla,codEmpleado);
    //codEmpleado, sueldoEmpleado, sueldoPlanilla, diasPlanilla son arreglos para cada codigo de empleado ; 
    //Sacamos el total de dias y el total de sueldo por planilla de todos los trabajadores,
    //para que podamos calcular los sueldos por los dias trabajados y meses trabajados.
    double sueldoTotal;
    int diasTotal ; 
    sueldoTotal = calculaSueldoTotal(numEmpleados,sueldoPlanilla);
    diasTotal = calculaDiasTotal (numEmpleados , diasPlanilla);
    //CREAMOS UN ARREGLO QUE NOS DA EL MONTO POR DIAS, MONTO POR SUELDO Y EL MONTO POR DIAS 
    //DE CADA TRABAJADOR
    double montoDia[MAX_EMPLEADOS] = {0}, montoSueldo[MAX_EMPLEADOS] = {0} ;
    double utilidad[MAX_EMPLEADOS] = {0};
    double repartir ;
    repartir = utilidadAnual*porcentaje /100.0 ; 
    calculaMontos(utilidad,montoDia,montoSueldo,numEmpleados,sueldoTotal,
            diasTotal,repartir,diasPlanilla,sueldoPlanilla);
    //IMPRIME 
    fprintf (archReporte,"               EMPRESA DE TELECOMUNICACIONES S.A\n");    
    fprintf (archReporte,"                DETALLE DEL PAGO DE UTILIDADES\n");
    imprimeLinea('=', MAX_CAR,archReporte);
    fprintf (archReporte,"Anio: %d \n" , anio);
    fprintf (archReporte,"Monto de Utilidades totales de la empresa: s/.  %9.2lf\n" ,utilidadAnual );
    fprintf (archReporte,"Porcentaje a repartir entre los empleados: %.2lf\n" , porcentaje);
    fprintf (archReporte,"Total de utilidades a repartir entre los empleados: S/. %.2lf\n" , repartir);
    imprimeLinea('=',MAX_CAR, archReporte); 
    imprimirResultados (utilidad,repartir,archReporte,codEmpleado,sueldoEmpleado,montoDia,montoSueldo,numEmpleados);
    //IMPRIME LA GRAFICA
    fprintf (archGrafica,"               EMPRESA DE TELECOMUNICACIONES S.A\n");    
    fprintf (archGrafica,"                DETALLE DEL PAGO DE UTILIDADES\n");
    imprimeLinea('=', MAX_CAR,archGrafica);
    fprintf (archGrafica,"Anio: %d \n" , anio);
    fprintf (archGrafica,"Monto de Utilidades totales de la empresa: s/.  %9.2lf\n" ,utilidadAnual );
    fprintf (archGrafica,"Porcentaje a repartir entre los empleados: %.2lf\n" , porcentaje);
    fprintf (archGrafica,"Total de utilidades a repartir entre los empleados: S/. %.2lf\n" , repartir);
    imprimeGrafica(archGrafica,utilidad,numEmpleados);
    return (EXIT_SUCCESS);
}



