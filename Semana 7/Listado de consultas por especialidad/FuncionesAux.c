/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define CAR_MAX 95
void obtenerReporte (FILE *archDoctor, FILE *archEspecialidad, FILE *archPaciente ,FILE *archConsultas ,FILE *reporte, int fechaI,int fechaF){
    int codEspecialidad;
    double tarifa;
    double montoTotalFac,montoTotalSeg;
    int tiempoEfectivoTotal;
    //Guarda los datos del mayor
    double montoMayor=0;
    int tiempoMayor , codMayor;
    //guarda los datos del menor
    double montoMenor=1000000;
    int tiempoMenor,codMenor;
    int h,m;
    while (1){//LEE LAS ESPECIALIDADES
         fscanf (archEspecialidad, "%d %lf" , &codEspecialidad , &tarifa);
         if (feof(archEspecialidad))break;
         montoTotalFac=0;
         montoTotalSeg=0;
         tiempoEfectivoTotal=0;
         imprimeLinea('=',CAR_MAX,reporte);
         fprintf (reporte,"\n\n  Especialidad: %d\n" , codEspecialidad);
         fprintf (reporte,"  Costo de la consulta: %.2lf\n",tarifa);
         mostrarReporte(codEspecialidad,tarifa,archDoctor,archConsultas,archPaciente,fechaI,fechaF,reporte,
                        &montoTotalFac,&montoTotalSeg ,&tiempoEfectivoTotal,&montoMayor,&montoMenor,&tiempoMayor,&tiempoMenor,
                        &codMayor,&codMenor);
         imprimeLinea('-',CAR_MAX,reporte); 
         fprintf (reporte,"  RESUMEN POR ESPECIALIDAD: \n");
         fprintf (reporte,"  Monto total facturado: s/. %5.2lf\n",montoTotalFac);
         fprintf (reporte,"  Monto total por cobrar al seguro s/. %5.2lf\n",montoTotalSeg);
         h=tiempoEfectivoTotal/60;
         m=tiempoEfectivoTotal%60;
         fprintf (reporte,"  Tiempo total efectivo: %dh%dm\n\n",h,m);
         
         fprintf (reporte,"  Doctor que mas facturo: %d\n" , codMayor);
         fprintf (reporte,"  Monto facturado: %5.2lf\n",montoMayor);
         h=tiempoMayor/60;
         m=tiempoMayor%60;
         fprintf (reporte, "  Tiempo efectivo de atencion: %dh%dm\n",h,m);
         
         fprintf (reporte,"  Doctor que menos facturo: %d\n" , codMenor);
         fprintf (reporte,"  Monto facturado: %5.2lf\n",montoMenor);
         h=tiempoMenor/60;
         m=tiempoMenor%60;
         fprintf (reporte, "  Tiempo efectivo de atencion: %dh%dm\n",h,m);
    }
}

void mostrarReporte(int codEspecialidad,double tarifa,FILE *archDoctor,FILE *archConsultas,FILE *archPaciente,int fechaI,int fechaF,FILE *reporte,
                        double *montoTotalFac,double *montoTotalSeg ,int *tiempoEfectivoTotal,
                        double *montoMayor,double *montoMenor
                                    ,int *tiempoMayor,int *tiempoMenor,int *codMayor,int *codMenor){
    int codDoctor , codEspecialidadDoctor; 
    int consultas = 0 ;
    double montoDoc , montoSegT ;
    int tiempoEfectivoDoc , h,m;
    
    
    rewind (archDoctor);
    while (1){// LEE DOCTORES
        fscanf (archDoctor,"%d %d" , &codDoctor, &codEspecialidadDoctor );
        if (feof (archDoctor))break;
        consultas = 0 ;
        montoDoc=0;
        montoSegT=0;
        tiempoEfectivoDoc = 0 ;
        if (codEspecialidadDoctor == codEspecialidad){//PROCESA LAS CONSULTAS
            consultas = obtenerConsultas(codDoctor  , archPaciente, archConsultas,fechaI,fechaF,reporte);
            if (consultas > 0 ){ // SI LAS CONSULTAS SON MAYORES A CERO, RECIEN IMPRIME EL NOMBRE DEL DOC; 
                imprimeLinea('=',CAR_MAX,reporte);
                fprintf (reporte,"  Doctor: %d\n" , codDoctor);
                imprimeLinea('-',CAR_MAX,reporte) ;
                fprintf (reporte,"    FECHA        Paciente      Duracion(min)  Monto Pagado(s/.)  Distrito        Telefono\n");
                mostrarConsultas(&montoDoc,&montoSegT,&tiempoEfectivoDoc,archConsultas,archPaciente,codDoctor,tarifa,fechaI,fechaF,reporte);//PROCESA LOS DATOS
                                                        //DE LAS CONSULTAS
                h=tiempoEfectivoDoc/60;
                m=tiempoEfectivoDoc%60;
                imprimeLinea('-',CAR_MAX,reporte) ;
                fprintf (reporte,"  Cantidad de consultas: %02d                 Tiempo efectivo de atencion: %dh%dm\n",consultas,h,m);
                fprintf (reporte,"  Monto Facturado: %.2lf                    Monto por cobrar al seguro: %.2lf\n" , montoDoc,(montoSegT-montoDoc));
                if ((*montoMayor)<montoDoc){
                    (*montoMayor) = montoDoc;
                    (*tiempoMayor) = tiempoEfectivoDoc;
                    (*codMayor) = codDoctor;
                }
                 if ((*montoMenor)>montoDoc){
                    (*montoMenor) = montoDoc;
                    (*tiempoMenor) = tiempoEfectivoDoc;
                    (*codMenor) = codDoctor;
                }
               
                (*montoTotalFac)+=montoDoc;
                (*montoTotalSeg)+=(montoSegT-montoDoc);
                (*tiempoEfectivoTotal)+= tiempoEfectivoDoc; 
            }
        }
    }
}
int obtenerConsultas(int codDoctor  ,FILE *archPaciente, FILE *archConsultas,int fechaI,int fechaF,FILE *reporte){
    int dniP ,codigoDoctorConsultas , dd,mm,aa, hI,mI,hF,mF;
    int consultasDoctor=0;
    int fecha;
    rewind (archConsultas);
    while (1){
        fscanf (archConsultas,"%d %d %d/%d/%d %d:%d %d:%d",&dniP ,&codigoDoctorConsultas , &dd,&mm,&aa, &hI,&mI,&hF,&mF);
        if (feof (archConsultas))break;
        fecha = aa*10000+mm*100+dd;
        if ((fecha <= fechaF) && (fecha >= fechaI)){
            if (codigoDoctorConsultas == codDoctor) {
            consultasDoctor++;
            } 
        }
    }
    return consultasDoctor;
}

void mostrarConsultas(double *montoDoc , double *montoSegT,int *tiempoEfectivoDoc,FILE *archConsultas,FILE *archPaciente, int codDoctor,double tarifa,int fechaI,int fechaF,FILE *reporte){
   int dniP ,codigoDoctorConsultas , dd,mm,aa, hI,mI,hF,mF;
   int consultasDoctor=0;
   double monto, montoSeg; 
   int distrito , telefono;
   int duracion ; 
   int fecha ; 
   rewind (archConsultas);
    while (1){
        fscanf (archConsultas,"%d %d %d/%d/%d %d:%d %d:%d",&dniP ,&codigoDoctorConsultas , &dd,&mm,&aa, &hI,&mI,&hF,&mF);
        if (feof (archConsultas))break;
        fecha = aa*10000+mm*100+dd;
        if ((fecha <= fechaF) && (fecha >= fechaI)){
            if (codigoDoctorConsultas == codDoctor) {
                buscarPaciente(dniP,&distrito,&telefono,&monto,archPaciente,tarifa,reporte);
                duracion = (hF*60+mF)-(hI*60+mI);
                fprintf (reporte,"  %02d/%02d/%4d      %08d        %3d             %6.2lf            %3d          %9d\n" ,dd,mm,aa,dniP,duracion,monto,distrito,telefono);
                (*tiempoEfectivoDoc) += duracion;
                (*montoDoc) += monto ; 
                (*montoSegT) += tarifa;
            }
        }

    }
    
}
void buscarPaciente(int dniP,int *distrito,int *telefono,double *monto,FILE *archPaciente,double tarifa,FILE *reporte){
    int dni;
    double porcentaje ; 
    rewind (archPaciente);
    while (1){
        fscanf (archPaciente,"%d %d %d %lf" , &dni , distrito,telefono , &porcentaje);
        if (feof (archPaciente))break;
        if (dni==dniP){
            (*monto)= porcentaje * tarifa/100 ; 
            break;
        }
    }
  
}

void imprimeLinea (char c , int maxCar,FILE *reporte){
    for (int i = 0 ; i < maxCar ; i++){
        fprintf (reporte,"%c" , c ); 
    }
    fprintf (reporte,"\n");
}
void cerrarArchivos (FILE *archDoctor, FILE *archEspecialidad, FILE *archPaciente ,FILE *archConsultas ,FILE *reporte){
    fclose (archDoctor);
    fclose (archEspecialidad);
    fclose (archPaciente);
    fclose (archConsultas);
    fclose (reporte);
}
