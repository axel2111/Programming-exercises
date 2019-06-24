/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#define MAX_PERSONAS 100
void leerDatos (int *dni,int *dia,int *mes,int *anio,int *fecha,int *numPersonas){
    FILE *archCumpleanos;
    archCumpleanos = fopen ("Cumpleanos.txt","r");
    if (archCumpleanos==NULL){
        printf ("error el archivo cumpleanos no existe");
        exit (1);
    }
    int dniAC,mesAC,diaAC,anioAC;
    while (1){
        fscanf (archCumpleanos,"%d %d/%d/%d",&dniAC,&diaAC,&mesAC,&anioAC);
        if (feof (archCumpleanos))break;
        if (*numPersonas<MAX_PERSONAS){
            dni[*numPersonas] = dniAC;
            dia[*numPersonas] = diaAC;
            mes[*numPersonas] = mesAC;
            anio[*numPersonas] = anioAC;
            fecha[*numPersonas] = diaAC+mesAC*100+anioAC*10000;
            (*numPersonas)++;
        }
        else{
            printf ("Error: se sobrepaso el limite de los arreglos %d\n" , *numPersonas);
            exit (1);
        }
    }
}

void ordenarCumpleanos(int *dni,int *dia,int *mes,int *anio,int *fecha,int numPersonas){
    for (int i = 0 ; i < numPersonas-1 ; i++){
        for (int j= i+1 ; j < numPersonas ; j++){
            if (fecha[i] > fecha [j]){
                cambiar(dni,i,j);
                cambiar(mes,i,j);
                cambiar(dia,i,j);
                cambiar(anio,i,j);
                cambiar(fecha,i,j);
            }
        }
    }
}
void cambiar(int *fecha,int i,int j){
    int aux ; 
    aux = fecha[i];
    fecha[i] = fecha[j];
    fecha[j] = aux ; 
}
int validarFecha(int dd,int mm,int aa){
    int bisiesto = 0 ;
    int valida = 0 ;
    if (aa%4==0 && aa%100!=100 || aa%400==0){
        bisiesto = 1 ;
    }
    if (dd>0 && dd <32 && mm>0 && mm <13 && aa>0){
        if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12){
            valida = 1; 
        }
        else {
            if (mm==2 && dd<= 29 && bisiesto==1) valida =1 ;
            else if (mm==2 && dd<29 && bisiesto==0) valida = 1;
            else if (mm==1||mm==4||mm==6||mm==9||mm==11 && dd <31) valida=1;
            else valida =0 ;
        }
    }
    return valida;
}
void generarReporte(int *edad,int *diasCump,int *dni,int *dia,int *mes,int *anio,
                                            int dd,int mm,int aa,int numPersonas){
    for (int i = 0 ;i < numPersonas ;i++){
        edad[i] = calcularEdad(dia,mes,anio,dd,mm,aa,i);
        diasCump[i] = calcularDias(dia,mes,anio,dd,mm,aa,i);
        if (edad>=0){
            printf ("%d\n" , edad[i]);
        }
    }
}
int calcularDias(int *dia,int *mes,int *anio,int dd,int mm,int aa,int i){
    int diasAcum=0, bisiesto = 0 ;
    bisiesto = aniobisiesto(aa);
    int diasMes; 
    if (bisiesto == 1 ){
        
    }
    else {
        if (mm==mes && dd<dia[i]){//caso mas facil
            diasAcum = dia[i] -dd ;
        }
        else if (dd<dia[i] && mm<mes[i]){
            while (mm!=mes[i]){
                diasMes=diasPorMes(mm);
                diasAcum+=diasMes;
                mm++;
                if (mm==mes[i]){
                    diasAcum+=dia[i];
                    break;
                }
            }
            return diasAcum;
        }
    }
    return diasAcum ; 
}
int diasPorMes(int mm){
    int dias ; 
    if (mm == 1 || mm == 3 || mm == 5 || mm==7|| mm==8|| mm==10|| mm==12){
        dias = 31 ; 
    }
    else if (mm==2 )
        dias = 28 ;
    else{
        dias == 30;
    } 
    return dias;
}
int aniobisiesto(int aa){
    int bisiesto = 0 ;
    if (aa%4==0 && aa%100!=100 || aa%400==0){
        bisiesto = 1 ;
    }
    return bisiesto;
}
int calcularEdad(int *dia,int *mes,int *anio,int dd,int mm,int aa,int i ){
    int edad =0 ;
    edad = aa-anio[i];
    if ((mm<mes[i])||( mm==mes[i]&&dd<dia[i])){
        edad= edad-1;
    }
    return edad;
}
void imprimirDatos(int *dni,int *dia,int *mes,int *anio,int numPersonas){
    for (int i = 0 ;i < numPersonas ; i++){
        printf ("%d %d/%d/%d\n" , dni[i] , dia[i],mes[i],anio[i]);
    }
}