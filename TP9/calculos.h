/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   calculos.h
 * Author: ezequiel
 *
 * Created on June 20, 2017, 11:04 PM
 */

#ifndef FILENAME_H
#define FILENAME_H

#include<math.h>
double perimetro_total(int orden_del_fractal, double largo_original);
//funcion que calcula el perimetro total del fractal


double area_total(int orden_del_fractal, double largo_original);
//funcion que calcula el area total del fractal


double longuitud_del_lado(int orden_del_fractal, double largo_original);
//funcion que calcula la longitud de cada arista del nuevo triangulo a
//formar recibiendo como dato del orden y el largo original del primer triangulo

int calcular_orden_maximo(int tolerancia, double length);
//Calcula cual es el el orden maximo al que se puede llegar
//respetando la tolerancia.



#endif /* FILENAME_H */
