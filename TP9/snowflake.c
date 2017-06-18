/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "snowflake.h"

#define LADOS 3 
#define GRADOS_A_RADIANES(x) (x * M_PI / 180.0)
#define CASO_BASE 1
#define LENGTH 400
#define START_POINTX 400
#define START_POINTY 400


void create_koch_snowflake(int order, double length, double px, double py, double angulo, int tolerancia);
//funcion que recibe el orden del fractal, en que coordenadas se lo desea crear.
//dibuja un fractal de dicho orden en pantalla con un delay apreciable entre
//cada iteracion.

void get_destination(double px, double py, double largo, double angulo, double* pfx, double* pfy );
//Funcion que recibe un punto inicial, un largo, un angulo y un puntero
//al punto final. La funcion devuelve las coordenadass del punto que se encuentra
//al angulo y a la distancia 'largo' del punto incial. ecibe el angulo en grados
//y lo interpreta en sentido antihorario.




void create_koch_snowflake(int n, double length, double px, double py, double angulo, int tolerancia)
{
    int i;
    double pfx= px+(length/3.0);
    double pfy= py;
    double pix=px;
    double piy=py;
    int order= n;
    get_destination(pix, piy, length/3.0 , angulo, &pfx, &pfy );
    
    if((3*length)<= tolerancia)
    {
        order=1;
    }
        if(order==CASO_BASE) //dibujo el primer tercio del lado del fractal de orden 1
        {
            
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0, px, py, 0+angulo, tolerancia);
        }
    
        pix= pfx;
        piy=pfy;
        get_destination(pix, piy, length/3.0 , 60.0+angulo, &pfx, &pfy );

        if(order==CASO_BASE) //roto 60 grados antihorario y dibujo el primer lado del triangulo
        {
            
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            
            
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0, pix, piy, 60+angulo, tolerancia);
        }

        //roto 240 grados en sentido antihorario y dibujo el fractal en el siguiente lado
        pix=pfx;
        piy=pfy;
        get_destination(pix, piy, length/3.0, 300+angulo, &pfx, &pfy );
        if(order==CASO_BASE)
        {
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0, pix, piy, 300+angulo, tolerancia);
        }
        pix=pfx;
        piy=pfy;
        get_destination(pix, piy, length/3.0, 0+angulo, &pfx, &pfy );
        if(order==CASO_BASE)
        {
            
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            pix=pfx;
            piy=pfy;
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0,pix, piy, 0+angulo, tolerancia);
        }

    
    
    
}

void final_snowflake(int n, int tolerancia) 
{
    double next_startx, next_starty;
        
         create_koch_snowflake(n, LENGTH, START_POINTX, START_POINTY, 60.0, tolerancia); //crea un lado del fractal
        
        get_destination(START_POINTX, START_POINTY, 400 , 60.0, &next_startx, &next_starty );
        
        create_koch_snowflake(n, LENGTH, next_startx, next_starty, 300, tolerancia); //crea un lado del fractal
        
        get_destination(next_startx, next_starty, 400 , 300, &next_startx, &next_starty );
        
        create_koch_snowflake(n, LENGTH, next_startx, next_starty, 180, tolerancia); //crea un lado del fractal
        
}

void get_destination(double px, double py, double largo, double angulo, double* pfx, double* pfy )
{
    double angulo_radianes = (GRADOS_A_RADIANES(angulo));
    *pfx=  px+(largo*(cos(angulo_radianes))); //calculo la cordeenada en x del destino
    *pfy= py-(largo*(sin(angulo_radianes))); //calculo la coordenada en y del destino
}

int calcular_orden_maximo(int tolerancia)
{
    double length= LENGTH;
    int i=0;
    while(length>tolerancia)
    {
        length /= 3.0;
        i++;
        
    }
    return i;
}
