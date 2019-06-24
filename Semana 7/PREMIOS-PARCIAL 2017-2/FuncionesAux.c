/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAX_CAR 80

void obtenerReporte(FILE *archClientes , FILE *archPremios ,FILE *archVentas ,
                    FILE *archProductos,FILE *reporte){
    int codPremio;
    double montoMinimo,montoMaximo;
    while (1){//LEE PREMIOS
        fscanf (archPremios,"%d %lf %lf" , &codPremio,&montoMinimo,&montoMaximo);
        if (feof (archPremios))break;
        printf ("\n\nCodigo de premio: %06d\n" , codPremio);
        printf ("Monto minimo:%.2lf                          Monto maximo: %.2lf\n",montoMinimo,montoMaximo);
        imprimirLinea('=',MAX_CAR);
        printf (" N.   DNI        TELEFONO       MONTO DE COMPRA\n");
        mostrarReporte(archClientes,archProductos,archVentas,codPremio,montoMinimo,montoMaximo);
        
    }
}
void mostrarReporte(FILE *archClientes,FILE *archProductos,FILE *archVentas,
                    int codPremio,double montoMinimo,double montoMaximo){
    
    int dniCliente, dd,mm,aa,telefono ;
    double montoCliente=0 ; 
    int contadorCliente = 0 ;
    rewind (archClientes);
    while (1){
        fscanf (archClientes,"%d %d/%d/%d %d",&dniCliente,&dd,&mm,&aa,&telefono);
        if (feof (archClientes))break;
        comprasCliente(dniCliente,&montoCliente,archVentas,archProductos);
        if ((montoCliente>=montoMinimo) && (montoCliente <= montoMaximo)){
            contadorCliente++;
            printf ("%2d %8d       %9d      %10.2lf\n",contadorCliente,dniCliente,telefono,montoCliente);
        }
    }
}
void comprasCliente(int dniCliente,double *montoCliente, FILE *archVentas,FILE *archProductos){
    int dd,mm,aa,h,m,s,dni,cod,cant;
    char c ; 
    double montoParcial,montoTotal = 0 ;
    rewind (archVentas);
    while (1){
        fscanf (archVentas, "%d/%d/%d %d:%d:%d %d",&dd,&mm,&aa,&h,&m,&s,&dni);
        if (feof (archVentas))break;
        if (dni == dniCliente){
            while (1){
                fscanf (archVentas,"%d %d",&cod,&cant);
                c=getc (archVentas);
                montoParcial=obtenerMonto(cod,cant,archProductos);
                montoTotal +=montoParcial;
                if (c=='\n')break;
            }
        }
    }
    (*montoCliente)=montoTotal;
}
double obtenerMonto (int cod,int cant,FILE *archProductos){
    double monto = 0 ;
    int codProducto;
    double precioUnitario ; 
    rewind (archProductos);
    while (1){
        fscanf (archProductos,"%d %lf",&codProducto,&precioUnitario);
        if (feof(archProductos))break;
        if (codProducto == cod){
            monto = cant*precioUnitario;
            break;
        }
    }
    return monto ; 
}
void imprimirLinea(char c,int maxCar){
    for (int i=0; i<maxCar;i++){
        printf ("%c",c);
    }
    printf ("\n");
}
void cerrarArchivos(FILE *archClientes , FILE *archPremios ,FILE *archVentas ,
                    FILE *archProductos,FILE *reporte){
    fclose(archClientes);
    fclose(archPremios);
    fclose(archVentas);
    fclose(archProductos);
    fclose(reporte);
}