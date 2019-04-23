/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 18 de abril de 2019, 03:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int jug1 , jug2 , iniciaSet ,saquePartida,
            setsGanador1=0 , setsGanador2 = 0 ,// Para determinar quien es el ganador del partido 
            ptj1 , ptj2, // guarda el puntaje del juego actual ; 
            ptj1Ant,ptj2Ant,//guarda el puntaje del juego anterior
            set = 1,  // guarda la cantidad de sets;
            ptjSaque1 , ptjSaque2, // guarda el puntaje de cada jugador cuando saca
            numpartida, // guarda el numero de partida
            ganadorPartidaActual,//Guarda al ganador de la partida; 
            contSaque,
            ganador;
    printf ("Ingrese los jugadores del partido y el jugador que inicia el saque:\n");
    scanf ("%d %d %d" , &jug1 , &jug2 , &iniciaSet);
    
    while (!(setsGanador1==3 || setsGanador2== 3)){//SETS
        saquePartida = iniciaSet ; 
        numpartida= 0; 
        contSaque=0;
        ptjSaque1= 0 ; 
        ptjSaque2= 0;
        printf ("Ingrese el detalle del puntaje en el set %d\n" , set); 
        
        while (1){//PARTIDASS
            numpartida++ ;
            scanf ("%d %d" , &ptj1, &ptj2);
            
            //DETERMINAR QUIEN ES EL GANADOR DE LA PARTIDA
            if (numpartida == 1 ){
                if (ptj1 > ptj2){//Gana el jug1 en la primer partida
                    ganadorPartidaActual= jug1 ; 
                }
                else if (ptj2 > ptj1){ // Gana el jug2 en la primera partida
                    ganadorPartidaActual = jug2 ; 
                }
            }
            else {
                if (ptj1Ant < ptj1 ){
                    ganadorPartidaActual=  jug1 ;
                }
                else if (ptj2Ant < ptj2 ){
                    ganadorPartidaActual = jug2 ;
                }
            }
            //Acumula puntaje por partida y saque ganado; 
            if (saquePartida == jug1 && ganadorPartidaActual==jug1){
                ptjSaque1++; 
            }
            else if (saquePartida == jug2 && ganadorPartidaActual==jug2){
                ptjSaque2++;
            }
            //SAQUE PARTIDA Y DETERMINAR EL GANADOR DEL SET
            if (ptj1+ptj2 >= 20){
               
                if (contSaque == 1 ){
                    saquePartida = (saquePartida==jug1)?jug2:jug1;
                    contSaque = 0 ;
                }  
                if (fabs(ptj2-ptj1) == 2){
                    if (ptj2>ptj1){
                        setsGanador2++;
                        ganador = jug2 ; 
                    }
                    else {
                        setsGanador1++;
                        ganador=jug1; 
                    }
                    break;
                }
            
            }
            else{
                if (ptj1 == 11 || ptj2 == 11 ){
                    if (ptj2>ptj1){
                        setsGanador2++;
                        ganador = jug2 ; 
                    }
                    else {
                        setsGanador1++;
                        ganador=jug1; 
                    }
                    break;
                }
            }
            //Actualiza variable
            ptj1Ant = ptj1;
            ptj2Ant = ptj2;
            contSaque++;
            if (contSaque == 2 ){
                    saquePartida = (saquePartida==jug1)?jug2:jug1;
                    contSaque = 0 ;
                }
        }
        printf ("El ganador del set %d es el jugador %d \n" , set,ganador);
        printf ("El jugador %d hizo %d puntos \n" , jug1,ptj1);
        printf ("El jugador %d hizo %d puntos \n", jug2,ptj2);
        printf ("El jugador %d hizo %d puntos en las jugadas que tuvo el saque\n", jug1, ptjSaque1 ); 
        printf ("El jugador %d hizo %d puntos en las jugadas que tuvo el saque\n", jug2, ptjSaque2 ); 
        iniciaSet = (iniciaSet == jug1)?jug2:jug1;
        set++;
    }
    if (setsGanador2>setsGanador1){
        ganador = jug2;
    }
    else ganador = jug1; 
    printf ("RESUMEN DEL PARTIDO\n");
    printf ("El ganador del partido es el jugador %d\n" ,ganador);
    printf ("El jugador %d gano %d sets\n",jug1,setsGanador1);
    printf ("El jugador %d gano %d sets\n",jug2,setsGanador2);
    return (EXIT_SUCCESS);
}

