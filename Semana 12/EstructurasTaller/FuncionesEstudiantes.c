/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesEstudiantes.h"
#include "Estudiante.h"
void leerCadena (char *cadAux , int numCar , FILE *arch){
    int i  ; 
    fgets (cadAux,numCar,arch);
    i  = strlen (cadAux);
    cadAux [i-1] = 0 ; 
}
char *leerCadenaExacta (FILE *arch){
    char cadAux[500], *cad;
    leerCadena(cadAux,500,arch);
    if (feof (arch))return NULL ; 
    cad = (char*)malloc (sizeof(char)*(strlen(cadAux)+1));
    strcpy(cad,cadAux);
    return cad ;
}
void sacarPalabras(char *frase , char **palabra , int *numPal ,char separador ){
    int i = 0 , j;  
    char cadAux[500] , *cad ;
    (*numPal) = 0 ;
    while (1){
        while (frase[i] == separador ) i++;
        if (frase[i] == 0 )break;
        j= 0 ; 
        while (frase[i] != separador && frase[i] != 0){
            cadAux[j] = frase[i];
            j++;
            i++;
        }
        cadAux[j] = 0 ; 
        cad = (char*)malloc (sizeof(char) *(strlen(cadAux)+1));
        strcpy(cad,cadAux);
        palabra[*numPal] = cad; 
        (*numPal)++;
    }
}
void leerEstudiantes (struct Estudiante *estudiante ,int *numEstudiantes){
    FILE *arch = fopen ("datos.txt", "r"); 
    char *frase ; 
    char *palabra[100] ; int numPal = 0; 
    while (1){
        frase = leerCadenaExacta(arch);
        if (frase == NULL) break; 
        sacarPalabras(frase,palabra,&numPal, ',');
        estudiante[*numEstudiantes].codigo = atoi (palabra[0]);
        strcpy(estudiante[*numEstudiantes].persona.nombre,palabra[1]);
        estudiante[*numEstudiantes].numCursos = (numPal-2)/4;
        estudiante[*numEstudiantes].curso = (struct Cursos*)malloc (sizeof (struct Cursos)*((numPal-2)/4)+1);
        estudiante[*numEstudiantes].creditosTotales = 0 ;
        int m = 0 ;
        for (int i = 0 ; i < estudiante[*numEstudiantes].numCursos ; i++){
            strcpy(estudiante[*numEstudiantes].curso[i].clave,palabra[2+m]);
            strcpy(estudiante[*numEstudiantes].curso[i].nombre,palabra[3+m]);
            estudiante[*numEstudiantes].curso[i].creditos = atof (palabra[4+m]);
            estudiante[*numEstudiantes].curso[i].horario = atoi(palabra[5+m]);
            estudiante[*numEstudiantes].creditosTotales += estudiante[*numEstudiantes].curso[i].creditos; 
            m=m+4;
        }
        (*numEstudiantes)++;
    }
}
void imprimirEstudiantes (struct Estudiante *estudiante , int numEstudiantes) {
    
    for (int i = 0 ; i < numEstudiantes ;i++){
        printf ("\tN. Codigo  Nombre\n");
        printf ("\t%2d) %8d %-20s\n" , i+1 , estudiante[i].codigo , estudiante[i].persona.nombre);
        printf ("\n");
        
        printf ("\tCLAVE   NOMBRE DEL CURSO             CREDITOS            HORARIO\n");
        for (int j = 0 ; j<estudiante[i].numCursos;j++){
            printf ("      %d) %-6s %-30s %5.2lf            %3d\n",j+1 , estudiante[i].curso[j].clave,
                                    estudiante[i].curso[j].nombre,
                                    estudiante[i].curso[j].creditos,
                                    estudiante[i].curso[j].horario);
        }
        linea ('=',70);
    }
} 
void ordenarEstudiantes(struct Estudiante *estudiante,int numEstudiantes){
    for (int i = 0 ;i < numEstudiantes-1 ; i++){
        for (int j= i+1 ; j < numEstudiantes ; j++){
            if (strcmp(estudiante[i].persona.nombre,estudiante[j].persona.nombre)>0){
                cambiarS(estudiante,i,j);
            }
        }
    }
}
void cambiarS(struct Estudiante *estudiante , int i,int j){
    struct Estudiante aux  ; 
    aux = estudiante[i];
    estudiante [i] = estudiante[j];
    estudiante[j] = aux;
}
void linea (char c , int numCar){
    for (int i = 0 ; i < numCar ; i++){
        printf ("%c", c);
    }
    printf ("\n");
}
void buscarAlumnosHorario (struct Estudiante *estudiante,int numEstudiantes){
    char clave[8];int horario ;  
    int comp ,comparaClave , cont =  0 ; 
    while (1){
        printf ("Ingrese la clave del curso: ") ,leerCadena(clave,8,stdin);
        comp = strcmp (clave , "salir");
        if (comp==0) break;
        printf ("Ingrese el horario: ") , scanf ("%d",&horario);
        cont = 0 ;
        getchar();
        for (int i = 0 ;i < numEstudiantes ; i++){
            for (int j=0 ; j < estudiante[i].numCursos ; j++){
                comparaClave = strcmp (estudiante[i].curso[j].clave,clave);
                if (comparaClave == 0 && estudiante[i].curso[j].horario==horario ){
                    cont ++ ;
                    printf ("%d) %d %s\n" ,cont , estudiante[i].codigo , estudiante[i].persona.nombre );
                }
            }
        }
        if (cont == 0 ) {
            printf ("No se encontraron alumnos en el horario seleccionado\n");
        }
    }
}