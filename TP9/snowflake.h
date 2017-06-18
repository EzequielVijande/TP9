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

void final_snowflake(int n, int tolerancia, char* color);
//Funcion que crea el snowflake entero, recibe el orden
//del snowflake a crear.

int calcular_orden_maximo(int tolerancia);
//Calcula cual es el el orden maximo al que se puede llegar
//respetando la tolerancia.



#endif /* SNOWFLAKE_H */

