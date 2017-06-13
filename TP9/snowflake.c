/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "snowflake.h"

#define LADOS 3 
#define GRADOS_A_RADIANES(x) (x * M_PI / 180.0)
#define CASO_BASE 1

void get_destination(int px, int py, double largo, double angulo, int* pfx, int* pfy );
//Funcion que recibe un punto inicial, un largo, un angulo y un puntero
//al punto final. La funcion devuelve las coordenadass del punto que se encuentra
//al angulo y a la distancia 'largo' del punto incial. ecibe el angulo en grados
//y lo interpreta en sentido antihorario.

void create_koch_snowflake(int n, double length, int px, int py)
{
    int i;
    int pfx,pfy;
    int pix=px;
    int piy=py;
    get_destination(px, py, length/3.0 , 60.0, &pfx, &pfy ); //roto la orientacion 60 grados antihorario.
    
    
        if(n==CASO_BASE) //dibujo el primer tercio del lado del fractal de orden 1
        {
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            pix= pfx;
            piy=pfy;
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0, px, py);
        }

        if(n==CASO_BASE) //roto 60 grados antihorario y dibujo el primer lado del triangulo
        {
            
            get_destination(pix, piy, length/3.0 , 60.0, &pfx, &pfy );
            al_draw_line((float)px, (float)py, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            pix=pfx;
            piy=pfy;
            
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0, pfx, pfy);
        }

        //roto 240 grados en sentido antihorario y dibujo el fractal en el siguiente lado
        
        if(n==CASO_BASE)
        {
            get_destination(pix, piy, length/3.0, 240.0, &pfx, &pfy );
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            pix=pfx;
            piy=pfy;
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0, pfx, pfy);
        }


        if(n==CASO_BASE)
        {
            get_destination(pix, piy, length/3.0, 60.0, &pfx, &pfy );
            al_draw_line((float)pix, (float)piy, (float) pfx,(float) pfy, al_map_rgb(255, 255, 255), 1);
            pix=pfx;
            piy=pfy;
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0,pfx, pfy);
        }

        get_destination(pix, piy, length/3.0 , 240.0, &pfx, &pfy ); //roto 240 grados
    
    
    
    
}

void get_destination(int px, int py, double largo, double angulo, int* pfx, int* pfy )
{
    double angulo_radianes = (GRADOS_A_RADIANES(angulo));
    *pfx= (int) (px+(largo*(cos(angulo_radianes)))); //calculo la cordeenada en x del destino
    *pfy= (int) (py+(largo*(sin(angulo_radianes)))); //calculo la coordenada en y del destino
}
