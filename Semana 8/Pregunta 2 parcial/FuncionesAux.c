/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAXCAR 80
void leerEmpleados(int *numEmpleados,int *codEmpleado,double *sueldoEmpleado){
    FILE *archEmpleados;
    archEmpleados = fopen ("empleados.txt","r");
    if (archEmpleados == NULL){
        printf ("Error el archivo empleados.txt , no existe\n");
        exit (1);
    }
    int codigo;
    double sueldo;
    *numEmpleados = 0 ;
    while (1){
        fscanf (archEmpleados, "%d %lf" , &codigo , &sueldo);
        if (feof (archEmpleados))break;
        codEmpleado[*numEmpleados] = codigo; 
        sueldoEmpleado[*numEmpleados] = sueldo ; 
        (*numEmpleados)++;
    }
}
void leerPlanilla(int anio ,int numEmpleados,double *sueldoPlanilla,int *diasPlanilla,int *codEmpleado){
    FILE *archPlanilla;
    archPlanilla = fopen ("planilla.txt","r");
    if (archPlanilla == NULL){
        printf ("Error el archivo planilla.txt , no existe\n");
        exit (1);
    }
    int codigo,anioPlanilla,mes,dia;
    double sueldo ; 
    while (1){//LEE PLANILLA
        fscanf (archPlanilla,"%d %d %d %d %lf",&codigo,&anioPlanilla,&mes,&dia,&sueldo);
        if (feof (archPlanilla))break;
        if (anio==anioPlanilla){
            for (int i = 0 ; i <numEmpleados ; i++){
                if (codigo == codEmpleado[i]){
                    sueldoPlanilla[i]+=sueldo;
                    diasPlanilla[i]+=dia;
                    break;
                }
            }
        }
    }
}
double calculaSueldoTotal(int numEmpleados,double *sueldoPlanilla){
    double suma = 0 ; 
    for (int i = 0 ; i < numEmpleados ; i++){
        suma += sueldoPlanilla[i] ;
    }
    return suma ; 
}
int calculaDiasTotal (int numEmpleados , int *diasPlanilla){
    int suma = 0;
    for (int i = 0 ; i <numEmpleados;  i++ ){
        suma += diasPlanilla[i];
    }
    return suma ;
}
void calculaMontos(double *utilidad,double *montoDia,double *montoSueldo,int numEmpleados,double sueldoTotal,int diasTotal
                    ,double repartir , int *diasPlanilla , double *sueldoPlanilla){
    
    for (int i = 0 ; i < numEmpleados ; i++){
        montoDia[i] = (repartir * diasPlanilla[i])/diasTotal;
        montoSueldo[i]= (repartir * sueldoPlanilla[i])/sueldoTotal;
        utilidad[i]=montoDia[i]+montoSueldo[i];
    }
}
void imprimirResultados (double *utilidad,double repartir , FILE *archReporte,int *codEmpleado,double *sueldoEmpleado,
                         double *montoDia, double *montoSueldo, int numEmpleados){
    

    fprintf (archReporte,"      Empleado Sueldo mensual (s/.) Monto por dias(s/.) Monto por sueldo Utilidad(s/.)\n");
    imprimeLinea('=',MAXCAR,archReporte);
    for (int i =0 ; i <numEmpleados ; i++){
        fprintf (archReporte,"%2d)    %6d       %6.2lf             %9.2lf        %9.2lf   %15.2lf \n" , i+1 , codEmpleado[i],sueldoEmpleado[i] , montoDia[i], montoSueldo[i] ,
                        utilidad[i]);
    }
    fprintf (archReporte,"RESUMEN: \n");
    fprintf (archReporte,"Total de empleados: %4d\n" , numEmpleados);
    fprintf (archReporte,"Monto por dias laborados: s/. %.2lf\n " ,repartir/2 );
    fprintf (archReporte,"Monto por remuneraciones s/. %.2lf \n" ,repartir/2 );
    
}

void imprimeGrafica(FILE *archGrafica,double *utilidad, int numEmpleados){
    int mayor ,aux ;
    int maxCar ; 
    int utilidadNiveles[500] = {0};
    for (int i =0 ; i < numEmpleados ; i++){
        aux = utilidad[i];
        utilidadNiveles[aux/10000]++;
        
    }
    mayor = calculaElMayor(utilidadNiveles, numEmpleados);
    
    for (int j = 0 ; j < 8 ; j++){
        maxCar = utilidadNiveles[j]*80/mayor ;
        fprintf (archGrafica,"%5d |" , j*10000);
        for (int p = 0 ; p < maxCar; p++){
            fprintf (archGrafica,"-");
        }
        fprintf (archGrafica,"| %d\n" , utilidadNiveles[j]);
    }
    
}
int calculaElMayor(int*utilidadNiveles, int numEmpleados){
    int mayor = 0 ; 
    for (int i = 0 ;i < numEmpleados ; i++){
        if (mayor < utilidadNiveles[i]){
            mayor = utilidadNiveles[i];
        }
    }
    return mayor ;
}
void imprimeLinea(char c , int maxCaracteres,FILE *archReporte){
    for (int i = 0 ; i< maxCaracteres ;i++){
        fprintf (archReporte,"%c" , c ); 
    }
    fprintf (archReporte,"\n");
}