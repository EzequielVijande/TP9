/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   snowflake.h
 * Author: ezequiel
 *
 * Created on June 13, 2017, 7:13 PM
 */

#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <math.h>
#include <allegro5/allegro_color.h>
#include "allegro5/allegro5.h"
#include <allegro5/allegro_primitives.h>

void create_koch_snowflake(int order, double length, int px, int py, double angulo);
//funcion que recibe el orden del fractal, en que coordenadas se lo desea crear.
//dibuja un fractal de dicho orden en pantalla con un delay apreciable entre
//cada iteracion.

void get_destination(int px, int py, double largo, double angulo, int* pfx, int* pfy );
//Funcion que recibe un punto inicial, un largo, un angulo y un puntero
//al punto final. La funcion devuelve las coordenadass del punto que se encuentra
//al angulo y a la distancia 'largo' del punto incial. ecibe el angulo en grados
//y lo interpreta en sentido antihorario.




#endif /* SNOWFLAKE_H */

