/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAux.h"
FILE *abrirArchivo(char *nomb,char*modo ){
    FILE *arch;
    arch = fopen (nomb,modo);
    if (arch==NULL){
        printf ("Error el archivo %s no existe" , nomb);
        exit (1);
    }
    return arch;
}
void leerDatos(char *arr,FILE *arch){
    char aux[500];
    leerCadena(aux,500,arch);
    strcpy(arr,aux);
}
void leerCadena(char *aux,int numCar,FILE *arch){
    int i ;
    fgets (aux,numCar,arch);
    i = strlen(aux);
    aux[i-1] =0;
}
void leerPalabrasSinonimos(char **palabras,char **sinonimos,int *numPalabras){
    FILE *archPalabras=abrirArchivo ("palabras.txt","r");
    FILE *archSinonimos = abrirArchivo("sinonimos.txt","r");
    (*numPalabras) = 0 ;
    while (1){
        palabras[*numPalabras] = leeCadenaExacta(archPalabras);
        sinonimos[*numPalabras] = leeCadenaExacta(archSinonimos);
        if (palabras[*numPalabras]==NULL) break;
        (*numPalabras)++;
    }
}
char *leeCadenaExacta(FILE *arch){
    char aux[50] ,*cad;
    leerCadena(aux,50,arch);
    if (feof(arch))return NULL;
    cad = (char*)malloc (sizeof (char) * (strlen(aux)+1));
    strcpy(cad,aux);
    return cad;
}
void contarPalabrasUsadas(char *linea,char **palabras,int *palabrasUsadas,int numPalabras){
    char *palabrasLinea[500] ;
    int posPalabrasLinea[500]={0};
    int cantPalabrasLinea=0;
    int compara = 0 ;
    sacarPalabras(linea,palabrasLinea,&cantPalabrasLinea);
    for (int i = 0 ; i < cantPalabrasLinea ; i++){
        for (int j=0; j < numPalabras ; j++){
            compara= strcmp(palabrasLinea[i], palabras[j]);
            if (compara ==0 ){
                palabrasUsadas[j]++;
            }
        }    
    }
}
void sacarPalabras(char *frase,char **arr,int *cant){
    int i = 0 , j ;
    char cadAux[500] , *ptPal ; 
    while (1){
        while (frase[i] == ' ' || frase[i] ==','||frase[i] =='.') i++;
        if (frase[i]==0)break;
        j=0;
        while ( frase[i] !=',' && frase[i]!=' '&& frase[i] !=0){
            cadAux[j] = frase[i];
            i++;
            j++;
        }
        cadAux[j] = 0 ;
        ptPal = (char*) malloc (sizeof(char) * (strlen(cadAux)+1));
        strcpy(ptPal,cadAux);
        arr[*cant] = ptPal ; 
        (*cant)++;
    }
}
void reemplazarSinonimos(char *linea,char **palabras,char **sinonimos,int numPalabras,FILE *archReporte){
    char *palabrasLinea[500] ;
    int cantPalabrasLinea=0;
    int compara = 0 ;
    sacarPalabras(linea,palabrasLinea,&cantPalabrasLinea);
    for (int i = 0 ;i <cantPalabrasLinea;i++){
        for(int j = 0 ; j < numPalabras;j++){
            compara =strcmp(palabrasLinea[i],palabras[j]) ;
            if (compara == 0 ){
                strcpy(palabrasLinea[i],sinonimos[j]);
            }
        }
        fprintf (archReporte,"%s",palabrasLinea[i]);
        fprintf (archReporte," " );
    }
    fprintf (archReporte,"\n");
}
void obtenerPalindromas(char *palindromas,char *linea,int *palabra){
    char *palabras[500];
    int numPal=0 , i=0;
    int pal=0;
    char cadAux [500];
    sacarPalabras(linea,palabras,&numPal);
    for (i; i <numPal ; i++){
        strcpy(cadAux,palabras[i]);
        pal = palin(cadAux);
        
        if (pal==1){
            if ((*palabra)==1){
                strcpy(palindromas,cadAux);
                (*palabra)++;
            }
            else{
                strcat(palindromas, " ");
                strcat(palindromas,cadAux);
            }
        }
    }

}
int palin(char *cadAux){
    int i = strlen(cadAux),iAux;
    int cont = 0;
    for (int k = 0 ; k < i ; k++){
        cadAux[k] = (cadAux[k]>='a' && cadAux[k]<='z')?cadAux[k]-32:cadAux[k];
    }
    iAux= i ;
    if (i>=3){
        for (int j= 0 ; j < i ; j++){
            if (cadAux[j] == cadAux[iAux-1])cont++;
            iAux--;
        }
        if (i == cont) return 1 ;
    }
    return 0 ;  

}
  
    