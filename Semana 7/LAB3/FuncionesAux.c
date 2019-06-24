/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define CAR_MAX 80
void obtenerReporte (FILE *archDoctor, FILE *archEspecialidad, FILE *archPaciente ,FILE *archConsultas ,FILE *reporte, int fechaI,int fechaF){
    int h, m ;
    int dni  , codDoctorC , dd ,mm ,aa ,hI,mI, hF,mF  , fecha ; // Consultas .txt
    int codigoEspecialidad; //especialidad.txt 
    double tarifa ; //especialidad.txt
    int codDoctor, codigoEspecialidadD; // doctor.txt
    int dniP , distrito , telefono ; // paciente.txt
    double porcentaje ; // paciente.txt
    int duracion;
    double monto = 0 ; 
    //POR CADA DOCTOR (VARIABLES)
    int consultas, tiempoEfectivo;
    double montoD  , montoSeguro ; 
    //POR CADA ESPECIALIDAD (VARIABLES)
    double montoTotalEspecialidad  , montoSeguroEspecialidad;  
    int tiempoEfectivoEspecialidad;
    //Guarda el doctor que gano mas , y el doctor que facturo menos.Con sus respectivos tiempos de efectividad
    double mayorD=0 ;
    int codMayor , codMenor,tiempoMayor , tiempoMenor;
    double menorD=1000000  ;
    int consultasD=0;
    
    imprimeLinea('=' , CAR_MAX) ; 
    while (1){//ESPECIALIDAD
        fscanf (archEspecialidad, "%d %lf" ,&codigoEspecialidad , &tarifa ) ;
        if (feof (archEspecialidad))break; 
        printf ("Especialidad: %d \n" , codigoEspecialidad) ; 
        printf ("Costo de la consulta: %.2lf \n"  ,tarifa ); 
        imprimeLinea ('=' , CAR_MAX) ; 
        rewind(archDoctor);
        montoTotalEspecialidad = 0;
        tiempoEfectivoEspecialidad=0;
        montoSeguroEspecialidad = 0 ; 
        while (1){//DOCTOR
            fscanf (archDoctor,"%d %d", &codDoctor,&codigoEspecialidadD);
            if (feof(archDoctor))break;
            montoD=0;
            tiempoEfectivo=0;
            montoSeguro = 0;
            consultas = 0 ;
            consultasD=obtenerConsultas(codDoctor  , archPaciente, archConsultas);
            rewind (archConsultas);
            if (consultasD>0){
                if (codigoEspecialidadD == codigoEspecialidad){
                  printf ("DOCTOR: %d\n" ,codDoctor);
                  imprimeLinea ('-', CAR_MAX);
                  printf ("   FECHA        Paciente      Duracion(min)  Monto Pagado(s/.)  Distrito Telefono\n");

                  while (1){//CONSULTAS
                      fscanf (archConsultas,"%d %d %d/%d/%d %d:%d %d:%d",&dni  , &codDoctorC , &dd ,&mm ,&aa ,&hI,&mI, &hF,&mF);
                      if (feof (archConsultas))break;
                      duracion = (hF*60+mF)-(hI*60+mI);
                      fecha = aa*10000+mm*100+dd;
                      if ((fecha<=fechaF) && (fecha >= fechaI)){
                          rewind (archPaciente); 

                          while (1){//LEE CADA PACIENTE
                              fscanf (archPaciente, "%d %d %d %lf" , &dniP ,&distrito ,&telefono , &porcentaje );
                              if (feof (archPaciente))break;
                              if ((dniP == dni) && (codDoctorC==codDoctor)){

                                  monto = tarifa*porcentaje/100.0;
                                  printf ("%02d/%02d/%d      %08d       %3d               %.2lf             %3d     %9d\n" , dd,mm,aa,dni,duracion,monto,distrito,telefono);
                                  consultas++;
                                  montoD+=monto;
                                  tiempoEfectivo+=duracion;
                              }
                          }  
                      }    
                  }
                imprimeLinea('-',CAR_MAX);
                h=tiempoEfectivo/60;
                m=tiempoEfectivo%60;
                printf ("  Cantidad de consltas: %3d                    Tiempo efectivo de atencion: %dh%dm\n" ,consultas,h,m );
                printf ("  Monto facturado:  s/. %6.2lf\n",montoD);
                imprimeLinea('-',CAR_MAX);
                montoTotalEspecialidad += montoD;
                tiempoEfectivoEspecialidad+=tiempoEfectivo;
                if (mayorD<montoD){
                    codMayor = codDoctor; 
                    mayorD=montoD;
                    tiempoMayor=tiempoEfectivo;
                }
                if (menorD>montoD){
                    codMenor = codDoctor; 
                    menorD=montoD;
                    tiempoMenor = tiempoEfectivo;
                }
              }  
            }

            
        }
        h=tiempoEfectivoEspecialidad/60;
        m=tiempoEfectivoEspecialidad%60;
        printf (" Resumen por especialidad:\n");
        printf ("Monto total facturado: s/. %.2lf\n" , montoTotalEspecialidad) ; 
        printf ("Tiempo total efectivo de atencion: %dh%dm\n\n",h,m);
        printf ("Doctor que mas facturo: %d\n" , codMayor);
        printf ("Monto total facturado: s/. %5.2lf\n" , mayorD);
        h=tiempoMayor/60;
        m=tiempoMayor%60;
        printf ("Tiempo total efectivo de atencion: %dh%dm\n\n ",h,m);
        
        printf ("Doctor que menos facturo: %d\n" , codMenor);
        printf ("Monto total facturado: s/. %5.2lf\n" , menorD);
        h=tiempoMenor/60;
        m=tiempoMenor%60;
        printf ("Tiempo total efectivo de atencion: %dh%dm \n",h,m);
        imprimeLinea('=',CAR_MAX);
    }
   
}
void imprimeLinea (char c , int maxCar){
    for (int i = 0 ; i < maxCar ; i++){
        printf ("%c" , c ); 
    }
    printf ("\n");
}
int obtenerConsultas(int codDoctor  ,FILE *archPaciente, FILE *archConsultas){
    int dniP ,codigoDoctorConsultas , dd,mm,aa, hI,mI,hF,mF;
    int consultasDoctor=0;
    rewind (archConsultas);
    while (1){
        fscanf (archConsultas,"%d %d %d/%d/%d %d:%d %d:%d",&dniP ,&codigoDoctorConsultas , &dd,&mm,&aa, &hI,&mI,&hF,&mF);
        if (feof (archConsultas))break;
        if (codigoDoctorConsultas == codDoctor) {
            consultasDoctor++;
        }
    }
    return consultasDoctor;
}
void cerrarArchivos (FILE *archDoctor, FILE *archEspecialidad, FILE *archPaciente ,FILE *archConsultas ,FILE *reporte){
    fclose (archDoctor);
    fclose (archEspecialidad);
    fclose (archPaciente);
    fclose (archConsultas);
    fclose (reporte);
}

