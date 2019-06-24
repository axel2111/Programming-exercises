/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 22 de abril de 2019, 10:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDatos;
    archDatos = fopen("datos.txt", "r");
    if(archDatos == NULL){
        exit(1);
    }
    int dni , dd,mm,aa,dM,mM,aM,dMT,mMT,aMT,
            hI,mI,sI,hF,mF,sF,h,m,s,
            consultas = 0 ,//guarda las consultas
            tiempoEfectivo,//guarda el tiempo efectivo
            tiempoEfectivoDia,
            tiempoEfectivoTotal,
            consultasTotal,
            dias,
            mayor =0,
            mayorT = 0 ;
    double porcentajeMonto, tarifa,
            montoPaciente,//guarda el monto que paga un paciente
            montoConsulta,// Monto que deberia de pagar el paciente;
            montoConsultaDia, // Monto que el doctor deberia sacar por dia 
            montoConsultaTotal, // Monto que el doctor deberia recibir en todas las fechas
            montoRecaudado=0,
            montoRecaudadoTotal=0,
            deudaSeguro;//Monto que el seguro le debe al doctor
    char salto;
    while (1){//MEDICOS
        fscanf(archDatos,"%d %lf", &dni ,&tarifa);
        if (feof(archDatos))break;
        montoRecaudadoTotal = 0;
        tiempoEfectivoTotal=0;
        dias = 0 ; 
        while(1){//FECHAS
            fscanf(archDatos,"%d/%d/%d",&dd,&mm,&aa); //0
            consultas = 0 ;
            montoRecaudado=0;
            montoConsultaDia=0;
            tiempoEfectivoDia=0;
           
            if(dd==0) break;
            dias++; 
            printf ("fecha\t\tNumero de consultas\t\tTiempo efectivo\t\tMonto recaudado\n");
            while(1){//HORAS
                fscanf(archDatos,"%d %d %d %d %d %d %lf %c",&hI,&mI,&sI,&hF,&mF,
                        &sF,&porcentajeMonto,&salto);
                if (salto=='\n')break;
                consultas++;
                tiempoEfectivo = (hF*3600+mF*60+sF)-(hI*3600+mI*60+sI);
                tiempoEfectivoDia+=tiempoEfectivo;
                montoConsulta = tiempoEfectivo * tarifa/60;
                montoConsultaDia += montoConsulta;
                montoPaciente= montoConsulta * porcentajeMonto/100;
                montoRecaudado+=montoPaciente;
                //convertir tiempo
            }
            //CONSULTAS
            if (mayor<consultas){
                mayor = consultas ; 
                aM=aa;
                mM=mm;
                dM=dd;
            }
            //Tiempo
            if(mayorT<tiempoEfectivoDia){
                mayorT=tiempoEfectivoDia;
                aMT=aa;
                mMT=mm;
                dMT=dd;
            }
            
            tiempoEfectivoTotal+=tiempoEfectivoDia;
            montoRecaudadoTotal+=montoRecaudado;
            montoConsultaTotal+=montoConsultaDia;
            deudaSeguro = montoRecaudadoTotal-montoConsultaTotal;
            consultasTotal += consultas; 
            printf ("%d/%d/%d\t\t%d\t\t\t%dh%dm%ds\t\t%lf",dd,mm,aa , consultas , h,m,s , montoRecaudado);
        
        }
        
        //convertir tiempo efectivo
        printf ("Monto que debe pagarle el seguro: s/. %lf\n" , deudaSeguro);
        printf ("Promedio de consultas diario %lf \n" , deudaSeguro/dias);
        printf ("Promedio de tiempo efectivo %lf\n" , tiempoEfectivoTotal/dias);
        printf ("");
    }
    return (EXIT_SUCCESS);
}

