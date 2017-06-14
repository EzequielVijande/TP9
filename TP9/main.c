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

#define TERMINAR ALLEGRO_KEY_ESCAPE 

/*
 * 
 */
int main(int argc, char** argv) 
{
    ALLEGRO_EVENT_QUEUE * event_queue = NULL;
    ALLEGRO_DISPLAY *  display = NULL;
    
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
        
        create_koch_snowflake(4, 300, 400, 400, 60.0); //crea el fractal
        al_flip_display();
        
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
        
   

