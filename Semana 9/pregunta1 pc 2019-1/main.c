
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"


int main(int argc, char** argv) {
    //utilidades.txt
    int anio[20];
    double utilidades[20] , porcentaje[20];
    int numUtilidades = 0 ; 
    //empleados .txt
    int codigoEmpleado[50];
    double sueldo [50];
    int numEmpleados = 0 ;
    //planilla.txt
    int codigoEmpPlanilla[500], ano[500] , mes[500], diasTrabajados[500];
    double sueldoMes[500];
    int numDatos = 0;
    
    leerUtilidades(anio,utilidades,porcentaje,&numUtilidades);
    leerEmpleados (codigoEmpleado , sueldo , &numEmpleados); 
    leerPlanilla(codigoEmpleado,numEmpleados,sueldo,codigoEmpPlanilla,ano,mes,
                            sueldoMes,diasTrabajados,&numDatos);
    printf ("Empleados:\n");
    printf ("N.    CODIGO     SUELDO\n");
    for (int i= 0 ; i < numEmpleados ; i++){
        printf ("%2d)   %6d  %8.2lf\n",i+1 , codigoEmpleado[i], sueldo[i]);
    }
    int anioB, codigoB=1;//datos buscar;
    int pos = -1 , trabajo =0;
    while (codigoB!=0){
        printf ("Ingrese el codigo del empleado: "),scanf ("%d", &codigoB);
        pos = buscarCodigo(codigoB,codigoEmpleado,numEmpleados);
        if (pos == 0) exit(0);
        if (pos >=0 ){
            printf ("Ingrese el anio: "), scanf ("%d",&anioB);
            trabajo = buscarTrabajo(codigoEmpPlanilla,ano,numDatos,anioB,codigoB);
            if (trabajo==1){

                mostrarReporte(codigoEmpleado,numEmpleados,anioB,pos,
                                ano,sueldoMes,codigoEmpPlanilla,diasTrabajados,numDatos,
                                anio,utilidades,porcentaje,numUtilidades);

            }
            else {
                printf ("ERROR: el empleado no trabajo ese anio\n");
            }
        }
        else {
            printf ("ERROR: NO SE UBICO EL EMPLEADO\n");
        }
        
    }
    imprimir(codigoEmpPlanilla,ano,mes,sueldoMes,diasTrabajados,numDatos);
    return (EXIT_SUCCESS);
}

