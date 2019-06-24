/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 23 de abril de 2019, 09:10 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDatos, *reporte;
    archDatos= fopen("ConsultasMedicas.txt" , "r");
    reporte= fopen("reporte.txt" , "w");
    
    if (archDatos==NULL){
        printf ("Error el archivo ConsultasMedicas.txt no existe");
        exit(1);
    } 
    if (reporte==NULL){
        printf ("Error el archivo reporte.txt no existe");
        exit(1);
    }
    
    int dni ;
    int dd,mm,aa ,h , m, s;
    int dM,mM,aM,dMT,mMT,aMT;
    int mayorC=0, mayorT=0;
    int hi, mi,si,hf, mf,sf ;
    int tiempoEfectivo,tiempoEfectivoDia,tiempoEfectivoTotal;
    int consultasDia,consultasTotal, dia,promedioT;
    double tarifa , porcentaje  ;
    double montoRecaudadoDia, montoRecaudado,montoSeguro,montoRecaudadoTotal;
    double montoPaciente,montoPacienteDia,montoPacienteTotal;
    double deudaSeguro;
    char c ;
    fprintf (reporte,"Reporte de consultas:\n");
    
    while (1){//LEE EL DNI Y LA TARIFA DE CADA MEDICO
        fscanf (archDatos,"%d %lf" , &dni, &tarifa);
        fprintf (reporte," DNI del Medico: %d\n", dni);
        fprintf (reporte," Costo por consulta por minuto:%lf\n" ,tarifa);
        fprintf (reporte," =========================================\n");
        fprintf (reporte," Fecha\t\tNumero de consultas\t\tTiempo efectivo\t\tMonto recaudado\n");
        montoRecaudadoTotal=0;
        montoPacienteTotal = 0 ;
        consultasTotal= 0 ;
        tiempoEfectivoTotal=0;
        dia = 0 ;
        if (feof(archDatos))break;
        while(1){ // LEE LA FECHA
            fscanf (archDatos,"%d/%d/%d" , &dd, &mm,&aa);
            if (dd==0)break;
            dia++;
            consultasDia=0;
            tiempoEfectivoDia = 0 ;
            montoRecaudadoDia=0;
            montoPacienteDia=0;
            while(1){//LEE LAS CONSULTAS
                fscanf (archDatos,"%d:%d:%d %d:%d:%d %lf%c" , &hi, &mi,&si,&hf, &mf,&sf , &porcentaje,&c);
                consultasDia++;
                tiempoEfectivo=(hf*3600+mf*60+sf)-(hi*3600+mi*60+si);
                tiempoEfectivoDia += tiempoEfectivo;
                montoRecaudado = tarifa*tiempoEfectivo/60*porcentaje/100;//con seguro
                montoPaciente = tarifa*tiempoEfectivo/60;
                montoPacienteDia+=montoPaciente;
                montoRecaudadoDia+=montoRecaudado;
                
                if (c=='\n')break;
                

            }
            //OPERACIONES TOTALES PARA CADA MEDICO
            consultasTotal+=consultasDia;
            montoRecaudadoTotal +=montoRecaudadoDia; 
            montoPacienteTotal += montoPacienteDia;
            deudaSeguro = montoPacienteTotal-montoRecaudadoTotal;
            tiempoEfectivoTotal += tiempoEfectivoDia;
            promedioT = tiempoEfectivoTotal / dia;
            //MAXIMOS OBTENIDOS
            if (mayorC<consultasDia){
                mayorC = consultasDia;
                dM=dd;
                mM=mm;
                aM=aa;
            }
            if (mayorT<tiempoEfectivoDia){
                mayorT = tiempoEfectivoDia;
                dMT=dd;
                mMT=mm;
                aMT=aa;
            }
            fprintf (reporte," %02d/%02d/%02d",dd, mm,aa);
            fprintf (reporte,"          %d" , consultasDia);
            //Convierte el tiempo efectivo dia a h,, m ,s ;
            h = tiempoEfectivoDia/3600;
            tiempoEfectivoDia=tiempoEfectivoDia%3600;
            m=tiempoEfectivoDia/60;
            s=tiempoEfectivoDia%60;
            fprintf (reporte,"                          %2dh %2dm %2ds" , h,m,s);
            fprintf (reporte,"                    %6.2lf\n" ,montoRecaudadoDia);
        }
        fprintf (reporte," =========================================\n");
        fprintf(reporte," Monto que debe pagarle el seguro: s/. %.2lf\n",deudaSeguro);
        fprintf (reporte," Promedio de consultas diario:        %.2lf\n" ,(double)consultasTotal/dia);
            //convierte el tiempo promedio a h,m,s;
        h = promedioT/3600;
        promedioT=promedioT%3600;
        m=promedioT/60;
        s=promedioT%60;
        fprintf (reporte," Promedio de tiempo efectivo: %dh %dm %ds\n",h,m,s);
        fprintf (reporte," =========================================\n");
        fprintf (reporte," Maximos obtenidos:\n");
        fprintf (reporte,"Consultas:\n");
        fprintf (reporte,"Fecha:%d/%d/%d \t\tTotal:%d\n" , dM,mM,aM,mayorC);
        fprintf (reporte,"Tiempo:\n");
        h = mayorT/3600;
        mayorT=mayorT%3600;
        m=mayorT/60;
        s=mayorT%60;
        fprintf (reporte,"Fecha:%d/%d/%d\t\tTotal: %dh %dm %ds\n",dMT,mMT,aMT,h,m,s);
    }
    
    
    
    
    fclose(archDatos);
    fclose(reporte);
    
    return (EXIT_SUCCESS);
}

