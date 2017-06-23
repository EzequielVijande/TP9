/*
 *Modulo que se encarga de hacer todos los calculos sobre propiedades del fractal
 */

#include"calculos.h"


double perimetro_total(int orden_del_fractal, double largo_original)
{
    long double calc,calcf;
    calc=pow((4.0/3.0),(orden_del_fractal));
    calcf=(3.0*largo_original*calc);
    return calcf;
            
}
double area_total(int orden_del_fractal, double largo_original)
{
    double area_inicial,area_final;
    area_inicial=cos((M_PI)/3.0)*largo_original*largo_original;
    area_final=(area_inicial/5.0)*(8.0-3.0*pow((4.0/9.0),orden_del_fractal));
    return area_final;
}

double longuitud_del_lado(int orden_del_fractal, double largo_original)
{
    double calc;
    calc=pow(3,orden_del_fractal);
    return (largo_original/calc);
}

int calcular_orden_maximo(int tolerancia, double length)
{
    
    int i=0;
    while(length>tolerancia)
    {
        length /= 3.0;
        i++;
        
    }
    return i;
}
