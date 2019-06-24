/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define MAX_CARACTERES 60
#include <stdio.h>
#include <stdlib.h>

void fxPrueba(FILE* archCursos ,FILE* archAlumnos ,FILE* archNotas ,FILE* archEspecialidad,FILE* reporte){
    int codEspecialidadArchEspe;
    double creditosEgresar;
    while (1){
        fscanf (archEspecialidad , "%d %lf" , &codEspecialidadArchEspe ,&creditosEgresar);
        if (feof(archEspecialidad)) break;
        printf ("%d %lf \n",codEspecialidadArchEspe, creditosEgresar );
    }
    
}


void buscarNotaCurso(int codAlumno,int codCursoArchCurso,double *nota,int *llevoCurso,FILE* archNotas ){
    
    printf("\t\t\t\tbuscarNotaCurso\n");
    int codAlumnoArchNota,codCursoArchNota;
    rewind(archNotas);
    while (1){
        fscanf (archNotas, "%d %d %lf" ,&codAlumnoArchNota,&codCursoArchNota,nota );
        if (feof (archNotas))break;
        if ((codAlumnoArchNota == codAlumno)&&(codCursoArchNota==codCursoArchCurso)){
            *llevoCurso = 1 ;
        }
        else{
            *llevoCurso = 0 ;
        }
    }
}


void cursosLlevadosEnOtraEspecialidad(int codEspecialidadArchEspe,int codAlumno,
                                    int*cantCursos,double*credMatriculados,double*credAprobados,
                                        FILE* archCursos,FILE* archNotas){
    //tiene que devolver cantcursos, credmatriculaods , creditosAprobados
    int codCursoArchCurso,especialidadArchCurso;
    double nota , creditos ; 
    int llevoCurso;
    printf("\t\t\tcursosLlevadosEnOtraEspecialidad\n");
    buscarNotaCurso(codAlumno,codCursoArchCurso,&nota,&llevoCurso,archNotas);
    
    rewind (archCursos);
    while (1){
        fscanf (archCursos,"%d %lf %d",codCursoArchCurso,creditos,especialidadArchCurso);
        if (feof (archCursos))break;
        llevoCurso = 0 ;
        if (especialidadArchCurso==codEspecialidadArchEspe){
            buscarNotaCurso(codAlumno,codCursoArchCurso,&nota,&llevoCurso,archNotas);
            if (llevoCurso==1){
                (*cantCursos)++;
                (*credMatriculados)+=creditos;
            }
            if (nota>=10.5){
                (*credAprobados)+=creditos;
            }
        }
    }
     
}




void imprimeLinea(char car,int maxCar , FILE *reporte){
    printf("\t\timprimeLinea\n");
    
    for (int i = 0 ; i<maxCar ; i++){
        fprintf (reporte,"%c",car);
    }
    fprintf (reporte,"\n");
    
}


void mostrarReporte(int codAlumno,int codEspecialidadA,
                    FILE* archNotas,FILE* archCursos,FILE *archEspecialidad,FILE *reporte){
    int codEspecialidadArchEspe ;
    double creditosEgresar, credMatriculados  , credAprobados;
    int cantCursos    ;
    printf("\t\tmostrarReporte\n");
    cursosLlevadosEnOtraEspecialidad(codEspecialidadArchEspe,codAlumno,&cantCursos,
                    &credMatriculados,&credAprobados,archCursos,archNotas);
    while (1){
        fscanf (archEspecialidad , "%d %lf" , &codEspecialidadArchEspe ,&creditosEgresar);
        if (feof(archEspecialidad)) break;
        cantCursos = 0 , credMatriculados = 0 , credAprobados = 0 ;
        if (codEspecialidadArchEspe!=codEspecialidadA){
            
            cursosLlevadosEnOtraEspecialidad(codEspecialidadArchEspe,codAlumno,&cantCursos,
                    &credMatriculados,&credAprobados,archCursos,archNotas);
            
            if (cantCursos>0){
                fprintf (reporte,"%d       %d       %lf      %lf" ,
                        codEspecialidadArchEspe, cantCursos , credMatriculados,credAprobados);
                
            }
        }
    }
}


void obtenerReporte(FILE* archCursos ,
                    FILE* archAlumnos ,
                    FILE* archNotas ,
                    FILE* archEspecialidad,FILE* reporte){
    int codAlumno , codEspecialidadA;
    printf("\tobtenerReporte\n");
    imprimeLinea('-', MAX_CARACTERES , reporte);
    mostrarReporte(codAlumno,codEspecialidadA,archCursos, archNotas,archEspecialidad,reporte);
    fprintf (reporte, "                    INSTITUO DE EDUCACION SUPERIOR\n");
    fprintf (reporte, "              ALUMNOS DE LA INSTITUCION MATRICULADOS EN\n");
    fprintf (reporte, "             CURSOS DE ESPECIALIDADES DISTINTAS A LA SUYA\n");
    imprimeLinea('-', MAX_CARACTERES , reporte);
    while (1){
        fscanf (archAlumnos , "%d %d" ,&codAlumno , &codEspecialidadA);
        if (feof(archAlumnos))break;
        fprintf (reporte, "Alumno: %d          Especialidad: %d\n" , codAlumno , codEspecialidadA);
        imprimeLinea('-',MAX_CARACTERES , reporte);
        fprintf (reporte, "REPORTE DE CURSOS LLEVADOS EN OTRA ESPECIALIDAD\n"); 
        fprintf (reporte, "Especialidades(*) NUMERO DE CURSOS     CREDITOS MATRICULADOS     CREDITOS APROBADOS\n");
        mostrarReporte(codAlumno,codEspecialidadA,archCursos, archNotas,archEspecialidad,reporte);
        imprimeLinea('-',MAX_CARACTERES , reporte);
    }  
    
}


void cerrarArchivos(FILE* archCursos ,FILE* archAlumnos ,FILE* archNotas ,FILE* archEspecialidad,FILE* reporte){
    fclose(archCursos);
    fclose(archAlumnos);
    fclose(archNotas);
    fclose(archEspecialidad);
    fclose(reporte);
    
}



