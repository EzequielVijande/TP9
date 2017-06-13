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

void create_koch_snowflake(int order, double length, int px, int py);
//funcion que recibe el orden del fractal, en que coordenadas se lo desea crear.
//dibuja un fractal de dicho orden en pantalla con un delay apreciable entre
//cada iteracion.




#endif /* SNOWFLAKE_H */

