/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAX_MARACTERES 90

void obtenerReporte(FILE *archCursos ,FILE *archAlumnos , FILE *archNotas ,
                                             FILE *archEspecialidad,FILE *reporte){
    int codAlumno , codEspecialidad ;
    int numAlumnos = 0 ;
    fprintf (reporte,"              INSTITUTO DE EDUCACION SUPERIOR\n");
    fprintf (reporte,"          ALUMNOS DE LA INSTITUCION MATRICULADOS EN\n");
    fprintf (reporte,"        CURSOS DE ESPECIALIDADES DISTINTAS A LA SUYA\n");
    imprimeLinea('=',MAX_MARACTERES,reporte);
    while (1){
        fscanf (archAlumnos,"%d %d" ,&codAlumno,&codEspecialidad);
        numAlumnos++;
        if (feof (archAlumnos))break;
        fprintf (reporte,"%d) Alumno: %d                  Especialidad: %d\n" ,numAlumnos, codAlumno,codEspecialidad);
        imprimeLinea('-',MAX_MARACTERES,reporte);
        fprintf (reporte,"REPORTE DE CURSOS LLEVADOS EN OTRA ESPECIALIDAD\n");
        fprintf (reporte,"    ESPECIALIDADES(*)   NUMERO DE CURSOS    CREDITOS MATRICULAOS    CREDITOS APROBADOS\n");
        mostrarReporte(codAlumno,codEspecialidad,archEspecialidad,archNotas,archCursos,reporte);
        imprimeLinea('=',MAX_MARACTERES,reporte);
    }  
}

void mostrarReporte(int codAlumno,int codEspecialidad,FILE *archEspecialidad,FILE *archNotas,FILE *archCursos
                                                                       ,FILE *reporte){
    int codEspecialidadArchEspecialidad;
    int contEsp = 0 ;
    double n;
    int numCursos, especialidadesDif = 0;
    double credMatriculados,credAprobados;
    double credMatriculadosT=0,credAprobadosT=0,cursosT=0;
    rewind(archEspecialidad);
    while (1){
        fscanf (archEspecialidad,"%d %lf" ,&codEspecialidadArchEspecialidad,&n);
        if(feof(archEspecialidad))break;
        numCursos = 0;
        credMatriculados = 0;
        credAprobados = 0 ;
        if (codEspecialidadArchEspecialidad != codEspecialidad){
              
            cursosEnOtraEspecialidad(codAlumno,codEspecialidadArchEspecialidad,&numCursos,&credMatriculados,&credAprobados,archCursos,archNotas);
            if (numCursos>0){
                  especialidadesDif++;
                fprintf (reporte,"      %d)  %d                 %d                   %.2lf                  %.2lf\n" ,especialidadesDif,codEspecialidadArchEspecialidad , numCursos , credMatriculados, credAprobados);
                cursosT+=numCursos;
                credAprobadosT +=credAprobados; 
                credMatriculadosT += credMatriculados ;

            }
        }
    }
    imprimeLinea('-',MAX_MARACTERES,reporte);
    fprintf (reporte,"               TOTAL\n");
    fprintf (reporte,"                 %d ESPECIALIDADES DISTINTAS A LA SUYA\n",especialidadesDif);
    fprintf (reporte,"                 %.2lf CURSOS\n",cursosT);
    fprintf (reporte,"                 %.2lf CREDITOS APROBADOS\n",credAprobadosT);
    fprintf (reporte,"                 %.2lf CREDITOS MATRICULADOS\n",credMatriculadosT);
}

void cursosEnOtraEspecialidad(int codAlumno,int codEspecialidadArchEspecialidad,int *numCursos,
        double *credMatriculados,double *credAprobados,FILE *archCursos,FILE *archNotas){
    
    int codCurso ,codEspecialidadCurso;
    double creditos ;
    double nota ; 
    int llevoCurso = 0 ; 
    rewind(archCursos);
    while (1){
        fscanf (archCursos,"%d %lf %d" ,&codCurso,&creditos,&codEspecialidadCurso);
        if (feof (archCursos))break;
        if (codEspecialidadCurso==codEspecialidadArchEspecialidad){
            buscarNotaCurso(&nota,&llevoCurso,codAlumno,codCurso,archNotas);
            if (llevoCurso==1){
                (*numCursos)++;
                (*credMatriculados)+=creditos;
            }
            if(nota>=10.5){
                (*credAprobados)+=creditos;
            }
       
        }
    }

}
void buscarNotaCurso(double *nota,int *llevoCurso,int codAlumno, int codCurso,FILE *archNotas){
    int codAlumnoArchNota,codCursoArchNota;
    rewind(archNotas);
    while (1){
         fscanf (archNotas,"%d %d %lf" ,&codAlumnoArchNota,&codCursoArchNota,nota);
         if (feof(archNotas))break;
         if ((codAlumnoArchNota == codAlumno)&&(codCursoArchNota==codCurso)){
                (*llevoCurso)=1;
                break;
        }
    }
    
}
void imprimeLinea(char car,int carMax,FILE *reporte){
    for (int i = 0 ; i<carMax ; i++){
        fprintf (reporte,"%c", car) ; 
    }
    fprintf (reporte,"\n");
}













void cerrarArchivos(FILE *archCursos ,FILE *archAlumnos , FILE *archNotas ,
                                             FILE *archEspecialidad,FILE *reporte){
    fclose (archCursos); 
    fclose (archAlumnos);
    fclose (archNotas);
    fclose (archEspecialidad);
    fclose (reporte);
}