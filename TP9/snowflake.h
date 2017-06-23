/*
 * Modulo que se encarga de crear e imprimir en pantalla el fractal.
 */

/* 
 * File:   snowflake.h
 * Author: ezequiel
 *
 * Created on June 13, 2017, 7:13 PM
 */

#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#define LENGTH 400
#include <math.h>
#include <allegro5/allegro_color.h>
#include "allegro5/allegro5.h"
#include <allegro5/allegro_primitives.h>

void final_snowflake(int n, int tolerancia, char* color);
//Funcion que crea el snowflake entero, recibe el orden
//del snowflake a crear.




#endif /* SNOWFLAKE_H */

