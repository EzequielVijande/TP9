
/*
 * Programa que imprime en pantalla un koch snowflake de orden n en el display de Allegro.
 * Tambien crea un reporte con los datos del fractal del orden ingresado(area)
 * Recibe por linea de comandos el orden, la tolerancia, el color ('r','g','b','p',o 'w')
 * y el nombre con el que se desea que se llame el reporte a crear con los datos del fractal.
 * El programa se puede finalizar tanto con la tecla "Esc" como con el boton de cierre del display
 */

/* 
 * File:   main.c
 * Autores: Ariel Martorell, Lucas Dellisola, Ezequiel Vijande, Francisco Tolaba
 *
 * Created on June 11, 2017, 5:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "allegro5/allegro5.h"
#include <allegro5/allegro_image.h>
#include "snowflake.h"
#include "input.h"
#include "calculos.h"
#include <time.h>





#define ARGUMENTOS 5
#define ORDEN 1
#define TOLERANCIA 2
#define COLOR 3
#define REPORTE 4
#define MIN(a,b) ( a<=b? a:b )


#define TERMINAR ALLEGRO_KEY_ESCAPE 

char * look_up_color(char);
//Funcion que interpreta el color que se ingreso como parametro.

int  write_report(char *,double perimetro,int orden1,int orden2,int tolerancia,double area);
//funcion que escribe el reporte con los datos del fractal.

/*
 * 
 */
int main(int argc, char** argv) 
{
    ALLEGRO_EVENT_QUEUE * event_queue = NULL;
    ALLEGRO_DISPLAY *  display = NULL;
    
    
    if(argc<ARGUMENTOS)
    {
        fprintf(stderr,"Argumentos insuficientes, por favor introducir en el siguiente orden:\n");
        fprintf(stderr,"1) Orden\n2) Tolerancia\n3) Color ('r','g','b','p','w')\n");
        fprintf(stderr,"4) Report (nombre del archivo a hacer el informe)\n");
        return -1;
    }
    
    
    
    
    if(!validate_input(argv[ORDEN])) //valida si se ingreso correctamente el orden
    {
        fprintf(stderr,"Orden invalido, por favor introducir un numero natural o el 0\n");
        return -1;
        
    }
    if((!validate_input(argv[TOLERANCIA]))||(!convert_char(argv[TOLERANCIA]))) //valida si se ingeso correctamente la tolerancia
    {
        fprintf(stderr,"Tolerancia invalida, por favor introducir un numero natural\n");
        return -1;
    }
    
    if(!a_color(argv[COLOR]))
    {
        fprintf(stderr,"Color invalido, por favor introducir 'r','g','b','w','p'\n");
        return -1;
    }
    
    
    if(!al_init())
        {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
    if(!al_init_primitives_addon())
    {
        fprintf(stderr, "failed to initialize primitives addon\n");
    }
        
    if(!al_init_image_addon())
    {
        fprintf(stderr, "failed to initialize image addon !\n");
	return -1;
    }
    
           
            
        if(!al_install_keyboard()) 
        {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
	
        
        event_queue = al_create_event_queue();
	if(!event_queue) 
        {
		fprintf(stderr, "failed to create event_queue!\n");
		return -1;
        }
        
	display = al_create_display(1080, 1080); // Intenta crear display de 800x600 de fallar devuelve NULL
	if(!display)
        {
		fprintf(stderr, "no se logro crear el display\n");
		return -1;
	}
 
	al_clear_to_color(al_map_rgb(0,0,0)); //Hace clear del backbuffer del diplay al color negro
 
	al_flip_display(); //Flip del backbuffer, pasa a verse a la pantalla
        
        al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source()); 
        
        bool salir = false;
        
        int order= convert_char (argv[ORDEN]);
        char * color= look_up_color(*(argv[COLOR]));
        int tolerancia = convert_char(argv[TOLERANCIA]);
        int max= calcular_orden_maximo(tolerancia, (double)LENGTH); //calcula hasta que orden se puede llegar
                                                        //con la tolerancia dada
        
        
        double perimetro = perimetro_total(order, (double)LENGTH);
        double area = area_total(order, (double)LENGTH);
        
        final_snowflake(MIN(order,max), tolerancia, color); //crea el fractal
        
        
        
        
        
        
        
        
        while(!salir)
	{
                ALLEGRO_EVENT ev;
                if( al_get_next_event(event_queue, &ev) )
                {
                    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
                    {
                        if(ev.keyboard.keycode== TERMINAR)
                                        salir= true;
                    }
                    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    {
                        salir=true;
                    }
                }
        }
        
        char * nombre_reporte = argv[REPORTE];
        
        write_report(nombre_reporte, perimetro, order, max, tolerancia, area);
        
        
        
        al_destroy_display(display); //cierra el display y libera la memoria del mismo.
	return 0;
}
        
   

char * look_up_color(char color)
{
    char * a_color=NULL;
    switch(color)
    {
        case ROJO:
            a_color = "red";
            break;
        
        case AZUL:
            a_color = "blue";
            break;
            
        case VERDE:
            a_color = "green";
            break;
            
        case ROSA:
            a_color = "hotpink";
            break;
            
        case BLANCO:
            a_color = "white";
            break;
    }
    
    return a_color;
}


int write_report(char * nombre_report,double perimetro,int orden1,int orden2,int tolerancia,double area)
{
    
    FILE * report = fopen (nombre_report , "w");
        if (report == NULL)
        {
            fprintf (stderr,"Error, no se pudo abrir el reporte, por favor intentar nuevamente.\n");
            return -1;
        }
        
        
        
    fprintf( report, "El orden ingresado fue %d.\n", orden1 );
    fprintf(report, "La tolerancia ingresada fue %d y el orden en el que se excede\n", tolerancia);
    fprintf(report,"dicha tolerancia es %d.\n", orden2);
    fprintf(report,"El perimetro del fractal de orden ingresado es %f.\n", (float)perimetro);
    fprintf(report,"y su area es %f.", (float)area);
        
    fclose(report);
    return 0;
    
    
    
    
    
}