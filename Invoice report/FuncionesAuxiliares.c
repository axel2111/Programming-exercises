/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define MAX_CAR_LINEA 60
#include <stdio.h>
#include <stdlib.h>
void cerrarArchivos(FILE *archProductos,FILE *archClientes,FILE *archFacturas,FILE *reporte){
    fclose (archProductos);
    fclose (archClientes);
    fclose (archFacturas);
    fclose (reporte);
}
void imprimirFacturas(FILE *archProductos,FILE *archClientes,FILE *archFacturas,FILE *reporte){
    int factura , dd,mm,aa , dni ;
    int ciudad , telefono;
    while (1){
        fscanf (archFacturas,"%d %d/%d/%d %d" , &factura ,&dd,&mm,&aa , &dni);
        if (feof (archFacturas))break;
        fprintf (reporte,"N.Factura: %7d                  Fecha:%02d/%02d/%02d\n",factura,dd,mm,aa);
        imprimirLineas('=' ,MAX_CAR_LINEA,reporte );
        buscarDni(archClientes,dni,&ciudad , &telefono);
        fprintf (reporte,"DNI: %8d             Ciudad: %3d            Telefono  %9d\n" , dni , ciudad , telefono);
        imprimirLineas('-', 60, reporte );
        fprintf (reporte,"Codigo          Precio Unitario          Cantidad          Subtotal\n");
        imprimirProductos(archFacturas,archProductos,reporte);
        imprimirLineas('=' ,MAX_CAR_LINEA,reporte );
    }
}
void imprimirLineas (char car,int numCar, FILE* reporte ){
    for (int i=0 ; i < numCar ;i++){
        fprintf (reporte,"%c" , car);
    }
    fprintf (reporte,"\n");
}
void buscarDni (FILE *archClientes,int dni, int *ciudad , int *telefono){
    int dniCli;
    rewind (archClientes);
    while (1){
        fscanf (archClientes,"%d %d %d" , &dniCli,ciudad,telefono);
        if (feof(archClientes)){
            ciudad =-1;
            telefono = -1;
            break;
            
        }
        if (dniCli==dni)break;
    }
}
double buscarPrecio(int codigo,FILE *archProductos){
    int codigoProd;
    double precioUnitario;
    rewind(archProductos);
    while (1){
        fscanf (archProductos,"%d %lf" , &codigoProd,&precioUnitario);
        if (feof (archProductos)){
            precioUnitario = -1.0;
            break;
        }
        if (codigoProd == codigo)break;
    }
    return precioUnitario;
}
void imprimirProductos(FILE *archFacturas,FILE *archProductos,FILE *reporte){
    
    int codigo , cant ;
    double subTotal , total = 0 ,precio;  
    while (1){
        fscanf (archFacturas,"%d %d" , &codigo,&cant);
        precio = buscarPrecio(codigo,archProductos);
        subTotal = precio * cant ; 
        total +=subTotal;
        fprintf (reporte," %2d               %.2lf                  %3d               %.2lf\n" , codigo , precio , cant , subTotal);
        if (fgetc(archFacturas) == '\n')break;
    }
    fprintf (reporte, "                                                         Total: %.2lf\n" , total);
}
