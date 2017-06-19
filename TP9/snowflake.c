/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "snowflake.h"

#define OFFSET 40
#define LADOS 3 
#define GRADOS_A_RADIANES(x) (x * M_PI / 180.0)
#define CASO_BASE 1
#define LENGTH 70
#define START_POINTX 550
#define START_POINTY 300


void create_koch_snowflake(int order, double length, double px, double py, double angulo, int tolerancia, char* color);
//funcion que recibe el orden del fractal, en que coordenadas se lo desea crear.
//dibuja un fractal de dicho orden en pantalla con un delay apreciable entre
//cada iteracion.

void get_destination(double px, double py, double largo, double angulo, double* pfx, double* pfy );
//Funcion que recibe un punto inicial, un largo, un angulo y un puntero
//al punto final. La funcion devuelve las coordenadass del punto que se encuentra
//al angulo y a la distancia 'largo' del punto incial. ecibe el angulo en grados
//y lo interpreta en sentido antihorario.




void create_koch_snowflake(int n, double length, double px, double py, double angulo, int tolerancia, char* color)
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
            
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy,al_color_name(color), 1);
            
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0, px, py, 0+angulo, tolerancia, color);
        }
    
        pix= pfx;
        piy=pfy;
        get_destination(pix, piy, length/3.0 , 60.0+angulo, &pfx, &pfy );

        if(order==CASO_BASE) //roto 60 grados antihorario y dibujo el primer lado del triangulo
        {
            
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy,al_color_name(color), 1);
            
            
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0, pix, piy, 60+angulo, tolerancia, color);
        }

        //roto 240 grados en sentido antihorario y dibujo el fractal en el siguiente lado
        pix=pfx;
        piy=pfy;
        get_destination(pix, piy, length/3.0, 300+angulo, &pfx, &pfy );
        if(order==CASO_BASE)
        {
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_color_name(color), 1);
            
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0, pix, piy, 300+angulo, tolerancia, color);
        }
        pix=pfx;
        piy=pfy;
        get_destination(pix, piy, length/3.0, 0+angulo, &pfx, &pfy );
        if(order==CASO_BASE)
        {
            
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_color_name(color), 1);
            pix=pfx;
            piy=pfy;
        }
        else
        {
            create_koch_snowflake(order-1, length/3.0,pix, piy, 0+angulo, tolerancia, color);
        }

    
    
    
}

void final_snowflake(int n, int tolerancia, char* color) 
{
    double next_startx, next_starty;
    double trianglev2x, trianglev2y, trianglev3x, trianglev3y; //vertices del fractal de orden 0
    
    if(n==0) //trata el orden 0 como caso aparte
    {
        get_destination(START_POINTX-OFFSET, START_POINTY+OFFSET/2.0, LENGTH, 60.0, &trianglev2x, &trianglev2y ); //calculo ambos
        get_destination(START_POINTX-OFFSET, START_POINTY+OFFSET/2.0, LENGTH, 0.0, &trianglev3x, &trianglev3y ); //vertices
        
        al_draw_triangle(START_POINTX-OFFSET, START_POINTY+OFFSET/2.0, (float) trianglev2x, (float) trianglev2y, (float) trianglev3x, (float) trianglev3y, al_color_name(color), 1);
    }
    
    else
    {
        
         create_koch_snowflake(n, LENGTH*2*n, START_POINTX-(2*n*OFFSET), START_POINTY+((n)*OFFSET), 60.0, tolerancia, color); //crea un lado del fractal
        
        get_destination(START_POINTX-(2*n*OFFSET), START_POINTY+((n)*OFFSET), LENGTH*2*n , 60.0, &next_startx, &next_starty );
        
        create_koch_snowflake(n, LENGTH*2*n, next_startx, next_starty, 300, tolerancia, color); //crea un lado del fractal
        
        get_destination(next_startx, next_starty, LENGTH*2*n , 300, &next_startx, &next_starty );
        
        create_koch_snowflake(n, LENGTH*2*n, next_startx, next_starty, 180, tolerancia, color); //crea un lado del fractal
    }
        
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
