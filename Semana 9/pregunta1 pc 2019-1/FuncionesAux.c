/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"


void leerUtilidades(int *anio,double *utilidades,double *porcentaje,int *numUtilidades){
    FILE *archUtilidades;
    archUtilidades = fopen ("utilidades.txt", "r");
    if (archUtilidades==NULL){
        printf ("error, el archivo utilidades.txt , no pudo abrirse ");
        exit (1);
    }
    int anioAU;
    double utilidadesAU , porcentajeAU ; 
    
    while (1){
        fscanf (archUtilidades,"%d %lf %lf",&anioAU,&utilidadesAU , &porcentajeAU);
        if (feof(archUtilidades))break;
        anio[*numUtilidades] = anioAU;
        utilidades[*numUtilidades]= utilidadesAU;
        porcentaje[*numUtilidades]=porcentajeAU;
        (*numUtilidades)++;
    }
    fclose (archUtilidades);
    ordenarUtilidades(anio,utilidades,porcentaje,*numUtilidades);
}
void ordenarUtilidades(int *anio,double *utilidades,double *porcentaje,int numUtilidades){
    for (int i = 0 ; i < numUtilidades-1 ; i ++)
        for (int j = i+1 ; j < numUtilidades;j++)
            if (anio[i] < anio[j]){
                cambiar (anio,i,j);
                cambiarD (utilidades,i,j);
                cambiarD(porcentaje,i,j);
            }
}
void cambiar(int *arr,int i,int j){
    int aux;
    aux = arr[i];
    arr[i]= arr [j];
    arr[j] = aux;
}
void cambiarD(double *arr,int i,int j){
    double aux;
    aux = arr[i];
    arr[i]= arr [j];
    arr[j] = aux;
}
void leerEmpleados (int *codigoEmpleado ,double  *sueldo , int *numEmpleados){
    FILE *archEmpleados;
    archEmpleados = fopen ("empleados.txt", "r");
    if (archEmpleados==NULL){
        printf ("error, el archivo empleados.txt , no pudo abrirse ");
        exit (1);
    }
    int codigo ;
    double suel ; 
    
    while (1){
        fscanf (archEmpleados,"%d %lf",&codigo , &suel);
        if (feof (archEmpleados))break;
        codigoEmpleado[*numEmpleados] = codigo;
          sueldo[*numEmpleados] = suel;
          (*numEmpleados)++;
    }
    fclose (archEmpleados);
}
void leerPlanilla(int *codigoEmpleado,int numEmpleados,double *sueldo,int *codigoEmpPlanilla
                        ,int *ano,int *mes,double *sueldoMes,
                    int *diasTrabajados,int *numDatos){
    FILE *archPlanilla; 
    archPlanilla = fopen ("planilla.txt", "r"); 
    if (archPlanilla==NULL){ 
        printf ("error, el archivo planilla.txt , no pudo abrirse "); 
        exit (1);
    }
    int codigo , anio ,mesP ,diaL , diaT;  
    while (1){
        fscanf (archPlanilla,"%d %d %d %d %d", &codigo , &anio ,&mesP ,&diaL , &diaT); 
        if (feof(archPlanilla))break;
        codigoEmpPlanilla[*numDatos]= codigo; 
        ano[*numDatos]=anio; 
        mes[*numDatos]=mesP;
        for (int i = 0 ;i < numEmpleados;i++){
            if (codigoEmpleado[i] == codigo){
                sueldoMes[*numDatos] = sueldo[i]*diaT/diaL;
            }
        }
        diasTrabajados[*numDatos] = diaT;
        (*numDatos)++;
    }
    ordenarPlantilla(codigoEmpPlanilla,ano,mes,sueldoMes,diasTrabajados,*numDatos);
    fclose(archPlanilla);
}
void ordenarPlantilla(int *codigoEmpPlanilla,int *ano,int *mes,double *sueldoMes,int *diasTrabajados,int numDatos){
        for (int i = 0 ; i < numDatos-1 ; i ++)
            for (int j = i+1 ; j < numDatos;j++)
                if (ano[i] > ano[j]
                        ||
                    ano[i] == ano[j] && codigoEmpPlanilla[i]>codigoEmpPlanilla[j] 
                        ||
                    ano[i] == ano[j] && codigoEmpPlanilla[i]==codigoEmpPlanilla[j] && mes[i]>mes[j]){
                    cambiar (codigoEmpPlanilla,i,j);
                    cambiar (ano,i,j);
                    cambiar(mes,i,j);
                    cambiarD(sueldoMes,i,j);
                    cambiar(diasTrabajados,i,j);
                }
}    
int buscarCodigo(int codigoB,int *codigoEmpleado,int numEmpleados){
    int valida = 0 ;
    for (int i = 0 ; i <numEmpleados; i++){
        if (codigoB==codigoEmpleado[i]){
            valida =i;
            return valida;
        }
    }
    return valida ;
}
int buscarTrabajo(int *codigoEmpPlanilla,int *ano,int numDatos,int anioB,int codigoB){
        int valida = 0 ;
        for (int i = 0 ; i <numDatos; i++){
        if (codigoB==codigoEmpPlanilla[i] && anioB==ano[i]){
            valida =1;
            return valida;
        }
    }
    return valida ;
}
void mostrarReporte(int *codigoEmpleado,int numEmpleados,int anioB,int pos,
                    int *ano,double *sueldoMes,int *codigoEmpPlanilla,int *diasTrabajados,int numDatos,
                                int *anio,double *utilidades,double *porcentaje,int numUtilidades){
    int diasEmpAnual[50]={0};
    double sueldoEmpAnual[50]={0};
    double sueldoTotal=0;
    int diasTotal = 0 ;
    int posUtilidades =-1;
    double repartir  ;
    double montoDias, montoSueldo,utilidad;
    for (int i = 0 ;i < numEmpleados;i++){
        for (int j = 0 ; j <numDatos ; j++){
            if (codigoEmpleado[i]==codigoEmpPlanilla[j] && ano[j] == anioB){
                sueldoEmpAnual [i] += sueldoMes[j]; 
                diasEmpAnual[i]+=diasTrabajados[j];
            }
        }
    }
    posUtilidades = buscarAnio(anio,numUtilidades,anioB);
    repartir = porcentaje[posUtilidades] * utilidades[posUtilidades]/200;
    sueldoTotal=calculaSueldoTotal(sueldoEmpAnual,numEmpleados);
    diasTotal=calculaDiasTotal(diasEmpAnual,numEmpleados);
    montoDias = repartir * diasEmpAnual[pos]/diasTotal;
    montoSueldo = repartir * sueldoEmpAnual[pos] / sueldoTotal;
    utilidad = montoDias+montoSueldo;
    printf ("DIAS TRABAJADOS REMUNERACION RECIBIDA UTILIDAD POR DIAS UTILIDAD POR SUELDO UTILIDAD TOTAL\n");
    printf ("%d %.2lf %.2lf %.2lf %.2lf\n",diasEmpAnual[pos],sueldoEmpAnual[pos],montoDias,montoSueldo,utilidad);
    
}
int buscarAnio(int *anio,int numUtilidades,int anioB){
    for (int i = 0 ;i < numUtilidades ;i++){
        if (anioB==anio[i]){
            return i;
        }
    }
    return -1;
}
double calculaSueldoTotal(double *sueldoEmpAnual,int numEmpleados){
    double suma = 0 ;
    for (int i =0 ; i < numEmpleados ; i++){
        suma += sueldoEmpAnual[i];
    }
    return suma;
}
int calculaDiasTotal(int *diasEmpAnual,int numEmpleados){
    int  suma = 0 ;
    for (int i =0 ; i < numEmpleados ; i++){
        suma += diasEmpAnual[i];
    }
    return suma;
}
void imprimir(int *codigoEmpPlanilla,int *ano,int *mes,double *sueldoMes,int *diasTrabajados,int numDatos){
    for (int i = 0 ;i <numDatos;i++){
        printf ("%d %d %d %d %lf \n",codigoEmpPlanilla[i] ,ano[i] , mes[i],diasTrabajados[i],sueldoMes[i]);
    }
}
