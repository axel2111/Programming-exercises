/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAXCAR 80
void obtenerReporte (FILE *archCursos , FILE *archAlumnos ,FILE *archNotas , FILE *archMatricula
                        ,FILE *archCorregido,FILE *archInfractores){
    
    int codAlumnoAM , codCursoAM ,especialidad; 
    int valido=0;
    char c ; 
    int contador = 0 ; 
    int contadorAl=0;
    double creditos ; 
    double creditosAcum = 0 ;
    int infraccionesMay = 0 , codMayor ;
    double credMay =0 ;
    int codCredMay;
    fprintf (archInfractores," REPORTE DE INFRACTORES DE MATRICULA\n");
    imprimeLinea('=',MAXCAR,archInfractores);
    fprintf (archInfractores," Codigo  Especialidad      Cursos en los que no podra matricularse\n");
    imprimeLinea('-',MAXCAR,archInfractores);
    while (1){
        fscanf (archMatricula,"%d" , &codAlumnoAM);
        if (feof(archMatricula))break;
        fprintf (archCorregido,"%d",codAlumnoAM);
        especialidad = buscarEspecialidad (codAlumnoAM,archAlumnos);
        contador= 0;
        creditosAcum = 0 ;
        while (1){
            fscanf (archMatricula,"%d",&codCursoAM);
            valido = verificarCurso(archCursos,archNotas,codCursoAM,codAlumnoAM);
            creditos=buscarCreditos(archCursos,codCursoAM);
            c = fgetc(archMatricula); 
            if (valido==1){
                fprintf (archCorregido," %d" , codCursoAM);
            }
            else {
                contador++;
                if (contador == 1){
                    contadorAl++;
                    fprintf (archInfractores, "%d) %d      %d       ",contadorAl,codAlumnoAM,especialidad);
                }
                fprintf (archInfractores,"%d) %d %.1lf\n",contador,codCursoAM,creditos);
                imprimeLinea('-',MAXCAR,archInfractores);
                creditosAcum += creditos; 
            }
            if(infraccionesMay<contador){
                infraccionesMay = contador ;
                codMayor=codAlumnoAM;
            }
            if(credMay<creditosAcum){
                credMay = creditosAcum ;
                codCredMay=codAlumnoAM;
            }
            if (c=='\n')break;
        }
        fprintf (archCorregido,"\n");
        
    }
    fprintf (archInfractores,"Total de alumnos infractores: %d\n",contadorAl);
    fprintf (archInfractores,"Alumnos con mas cursos con infracciones: %d con %d infracciones\n ",codMayor , infraccionesMay);
    fprintf (archInfractores,"Alumnos con mas creditos con infracciones: %d con %.2lf creditos\n",codCredMay,credMay);
}
double buscarCreditos(FILE *archCursos,int codCursoAM){
    int paso =0; 
    int codCursoAC;
    double creditos;
    int codPreReq;
    char c ; 
    rewind(archCursos);
    while (1){//cursos.txt LEO EL CURSO Y LOS CREDITOS
        fscanf (archCursos , "%d %lf" , &codCursoAC, &creditos);
        if (feof (archCursos))break;
        while (1){//cursos.txt LEO EL PREREQUISITO
            fscanf (archCursos,"%d",&codPreReq);
            c= fgetc(archCursos);
            if (c=='\n')break;
        }
        if(codCursoAC == codCursoAM){
            return creditos ;
        }
    }
    return -1 ; 
}
int verificarCurso(FILE *archCursos,FILE *archNotas,int codCursoAM,int codAlumnoAM){
    int paso =0; 
    int codCursoAC;
    double creditos;
    int codPreReq;
    char c ; 
    rewind(archCursos);
    while (1){//cursos.txt LEO EL CURSO Y LOS CREDITOS
        fscanf (archCursos , "%d %lf" , &codCursoAC, &creditos);
        if (feof (archCursos))break;
        while (1){//cursos.txt LEO EL PREREQUISITO
            fscanf (archCursos,"%d",&codPreReq);
            c= fgetc(archCursos);
            if (codCursoAM == codCursoAC){
                paso = buscarAlumnoLlevoCurso(codAlumnoAM,codPreReq,archNotas);
            }
            if (c=='\n')break;
        }
        
    }
    return paso ; 
}

int buscarAlumnoLlevoCurso(int codAlumnoAM,int codPreReq,FILE *archNotas){
    int codAlumnoAN,codCursoAN,nota ; 
    int aprobado = 0 ;
    rewind(archNotas);
    while (1){
        fscanf (archNotas,"%d %d %d", &codAlumnoAN,&codCursoAN,&nota);
        if (feof (archNotas))break;
        if (codAlumnoAN==codAlumnoAM && codPreReq == codCursoAN){
            if (nota>10) return 1;
            
            else return 0 ;
            
        }
        if (codPreReq == 0 ){
            return 1 ;
        }
    }
    return 0 ;
}
int buscarEspecialidad (int codAlumnoAM,FILE *archAlumnos){
    int especialidad;
    int cod ; 
    rewind(archAlumnos);
    while (1){
        fscanf (archAlumnos,"%d %d" , &cod , &especialidad);
        if (feof (archAlumnos))break;
        if (cod == codAlumnoAM){
            return especialidad;
        }
    }
    return -1;
}
void  imprimeLinea(char c,int maxcar,FILE *archInfractores){
    for (int i = 0 ; i < maxcar ; i++){
        fprintf (archInfractores,"%c",c);
    }
    fprintf (archInfractores,"\n");
}
void cerrarArchivos (FILE *archCursos , FILE *archAlumnos ,FILE *archNotas , 
        FILE *archMatricula, FILE*archCorregido,FILE *archInfractores){
    fclose(archCursos);
    fclose(archAlumnos);
    fclose(archNotas);
    fclose(archMatricula);
    fclose(archCorregido);
    fclose (archInfractores);
}