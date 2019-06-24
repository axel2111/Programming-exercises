/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"

#define MAX 70
void obtenerReporte(FILE *archClientes ,FILE *archVentas, FILE *archPremios,FILE *archProductos,FILE *reporte){
    int codigoPremio, montoMax ,montoMin;
    while (1){
        fscanf (archPremios,"%d %d %d",&codigoPremio, &montoMin ,&montoMax);
        if (feof (archPremios))break;
        printf ("Codigo de premio: %d                \n", codigoPremio);
        printf ("Monto minimo de compra: %d            Monto maximo de compra: %d \n", montoMin,montoMax);
        imprimirLinea('-',MAX);
        mostrarGanadores(montoMax,montoMin,archClientes,archProductos,archVentas);
    }
}
void mostrarGanadores(int montoMax,int montoMin,FILE *archClientes,FILE *archProductos,FILE *archVentas){
    int dniCli,dd,mm,aa ,telefono ;
    double montoT = 0 ,y=0;
   
    while (1){
        fscanf (archClientes,"%d %d/%d/%d %d" ,&dniCli,&dd,&mm,&aa,&telefono);
        if (feof (archClientes))break;
        while (1){
            y=obtenerMontoT(dniCli,archProductos,archVentas);
            
            if (y>=5000 && y<=10000){
                printf ("%d          %d              %lf\n" , dniCli,telefono,y);
            }
            if (y>0)break;
        }
        
    }
}
double obtenerMontoT(int dniCli,FILE *archProductos,FILE *archVentas){
    int dd,mm,aa ,h,m,s ,dni;
    int codigo , cant ; 
    char c ;
    double montoP=0 , monto =0 ,montoT=0;

    while (1){
        fscanf (archVentas,"%d %d %d %d %d %d %d" ,&dd,&mm,&aa,&h,&m,&s,&dni);
        if (feof (archVentas))break;
        while (1){
            fscanf (archVentas,"%d %d" , &codigo , &cant );
            calcularMonto (codigo, cant , &monto , archProductos);
            montoP += monto;
            c=fgetc(archVentas);
            if (c =='\n')break;
        }
        (montoT) += montoP;
        if (dni==dniCli){
            return montoT;
        }
        else {
            return 0;
        }
    }
}
void calcularMonto (int codigo,int  cant , double *monto ,FILE *archProductos){
    int codProd;
    double pu ; 
    rewind (archProductos);
    while (1){
        fscanf (archProductos,"%d %lf" , &codProd , &pu);
        if (feof(archProductos))break;
        if (codProd == codigo){
            (*monto) = (cant*pu);
            break;
        }
    }
}
void imprimirLinea(char c,int carMax){
    for (int i = 0 ; i <carMax ; i++){
        printf ("%c" , c);
    }
    printf ("\n"); 
}
void cerrarArch(FILE *archClientes ,FILE *archVentas, FILE *archPremios,FILE *archProductos,FILE *reporte){
    fclose (archClientes);
    fclose (archVentas);
    fclose (archPremios);
    fclose (archProductos);
    fclose (reporte);
}
