/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"calculos.h"


double perimetro_total(int orden_del_fractal, double largo_original)
{
    long double calc,calcf;
    calc=pow((3.0/4.0),(orden_del_fractal));
    calcf=(3.0*largo_original*calc);
    return calcf;
            
}
double area_total(int orden_del_fractal, double largo_original)
{
    double base,altura,area_inicial,area_final;
    base=largo_original;
    altura=largo_original*cos((M_PI)/6.0);
    area_inicial=base*altura;
    area_final=(area_inicial/5.0)*(8.0-3.0*pow((4.0/9.0),orden_del_fractal));
    return area_final;
}

double longuitud_del_lado(int orden_del_fractal, double largo_original)
{
    double calc;
    calc=pow(3,orden_del_fractal);
    return (largo_original/calc);
}
