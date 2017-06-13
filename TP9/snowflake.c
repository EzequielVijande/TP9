/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define CASO_BASE 0
void create_koch_snowflake(int order, double length);
//funcion que recibe el orden del fractal, en que coordenadas se lo desea crear.
//dibuja un fractal de dicho orden en pantalla con un delay apreciable entre
//cada iteracion.

void create_koch_snowflake(int n, double length)
{
    int i;
    for(i=0; i<3; i++)
    {
        if(n==CASO_BASE)
        {
            draw_line(length/3); 
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0);
        }

        rotate_anticlockwise(60);

        if(n==CASO_BASE)
        {
            draw_line(length/3);
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0);
        }

        rotate_clockwise(120);

        if(n==CASO_BASE)
        {
            draw_line(length/3);
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0);
        }

        rotate_anticlockwise(60);

        if(n==CASO_BASE)
        {
            draw_line(length/3);
        }
        else
        {
            create_koch_snowflake(n-1, length/3.0);
        }

        rotate_clockwise(120);
    }
    
    
    
    
    
    
    
}
