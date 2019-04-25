/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 19 de abril de 2019, 12:11 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDatos , *archMovimientos,*archReporte ; 
    archDatos = fopen ("DatosIniciales.txt" ,"r");
    archMovimientos = fopen ("MovimientosEnCuenta.txt" ,"r");
    archReporte = fopen("Reporte.txt" , "w") ; 
    if (archDatos == NULL){
        printf ("Error, el archivo DatosIniciales.txt no se pudo abrir\n");
        exit(1);
    }
    if (archMovimientos == NULL){
        printf ("Error, el archivo MovimientosEnCuenta.txt no se pudo abrir\n");
        exit(1);
    }
    if (archReporte == NULL){
        printf ("Error, el archivo Reporte.txt no se pudo abrir\n");
        exit(1);
    }
    
    int   
        operacion, // PARA LA PRIMERA OPERACION 
        numCuenta ,  // guardan el numero de cuenta 
        dd ,mm ,aa, // guarda la Fecha
        h,m,s,//guarda la hora de cada operacion
        tipoMovimiento,// guarda el tipo de movimiento si es deposito o retiro ;      
        moneda,// guarda el tipo de moneda dolares o soles
        hAnt = 0 , hActual , tiempo; // Guarda el tiempo
    
    double   tipoDeCambio , montoMinimo, // Guarda los datos iniciales del banco;
                monto, // guarda el monto ingresado
             saldo,
        montoD; // guarda el monto de dolares
    fscanf (archDatos,"%lf %lf" , &tipoDeCambio,&montoMinimo);
    fscanf (archMovimientos, "%d %lf" , &numCuenta,&saldo);
    fprintf (archReporte,"BANCO ABC\n");
    fprintf (archReporte,"Estado de cuenta numero: %2d\n",numCuenta );
    fprintf (archReporte,"Tipo de cambio:   $== %6.2lf\n",tipoDeCambio);
    fprintf (archReporte,"Movimiento realizados: \n");
    fprintf (archReporte,"Saldo inicial: %6.2lf\n" ,saldo );
    while (1){ //FECHAS
        hAnt = 0 ;
        fscanf (archMovimientos,"%d/%d/%d",&dd,&mm,&aa); // LEE FECHAS
        if (feof(archMovimientos))break; 
        fprintf (archReporte,"FECHA: %d/%d/%d\n",dd,mm,aa);
        fprintf (archReporte,"  TIEMPO TRANSCURRIDO    MONTO DE OPERACION        SALDO S./     OBSERVACION\n");
        while (1){ // REGISTRA LAS HORAS Y LOS MOVIMIENTOS EN ESE DIA
            operacion ++ ; 
            fscanf (archMovimientos, "%d:%d:%d" , &h,&m,&s);
         
            if (h==-1)break;
            fscanf (archMovimientos, "%d %d %lf", &tipoMovimiento , &moneda , &monto);
            hActual = h*3600 + m*60 +s;
            tiempo = hActual-hAnt;
            hAnt = hActual;
            h=tiempo/3600 ; 
            tiempo = tiempo%3600;
            m = tiempo /60;
            s= tiempo % 60 ;
         
            if (moneda == 1){
                montoD=monto ; 
                monto = monto*tipoDeCambio;
            }
            if (tipoMovimiento == 1){
                saldo-=monto;
            }
            else{
                saldo+=monto; 
            }
           
            fprintf (archReporte,"     %02d:%02d:%02d" , h , m , s);
            if (moneda==1 && tipoMovimiento ==1){
                fprintf (archReporte,"            $     (%6.2lf)",montoD);
                }
            else if (moneda==1 && tipoMovimiento ==0){
                fprintf (archReporte,"            $     %6.2lf ",montoD);
                }
            else if (moneda==0 && tipoMovimiento ==0){
                fprintf (archReporte,"            S./   %6.2lf ",monto);
                }
            else if (moneda==0 && tipoMovimiento ==1){
                fprintf (archReporte,"            S./   (%6.2lf)",monto);
                } 
            
            if (saldo >= montoMinimo ){
                fprintf (archReporte,"          %.2lf\n" , saldo);
            }
            else{
                if (saldo <0){
                    fprintf (archReporte,"          (%.2lf)     SOBREGIRO\n" , -saldo)    ;
                }
                else{
                    fprintf (archReporte,"          %.2lf     MENOR AL MINIMO\n" , saldo);
                }
            }
        }
        
    }
    fclose(archReporte); 
    fclose(archDatos);
    fclose(archMovimientos);
    return (EXIT_SUCCESS);
}

