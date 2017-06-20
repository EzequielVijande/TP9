
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ezequiel
 *
 * Created on June 11, 2017, 5:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "allegro5/allegro5.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "snowflake.h"
#include "input.h"
#include <time.h>






#define ARGUMENTOS 5
#define ORDEN 1
#define TOLERANCIA 2
#define COLOR 3

#define TERMINAR ALLEGRO_KEY_ESCAPE 

char * look_up_color(char);
//Funcion que interpreta el color que se ingreso como parametro.

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
    if(!al_init_acodec_addon())
    {
    fprintf(stderr, "failed to initialize audio!\n");
    return -1;
    }
        
    if(!al_install_audio())
    {
    fprintf(stderr, "failed to initialize audio!\n");
    return -1;
    } 
    if (!al_reserve_samples(1))
    {
        fprintf(stderr, "failed to reserve samples!\n");
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
        int i;
        int max= calcular_orden_maximo(tolerancia); //calcula hasta que orden se puede llegar
                                                        //con la tolerancia dada
        
        for(i=0; (i<= order)&&(i<=max); i++)
        {
            final_snowflake(i, tolerancia, color); //crea el fractal
             al_flip_display();
             sleep(1);
        }
        
        
        
        
        
        
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
                }
        }
        
        
        al_destroy_display(display); //cierra el display y libera la memoria del mismo.
        al_uninstall_audio();
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
