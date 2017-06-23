/*
 Modulo que se encarga de interpretar y validar el input
 */
#include <stdbool.h>
#include "input.h"
#define TERMINADOR 0

int convert_char (char * string)
{
	int counter;
	int num = 0;

	for ( counter = 0; (string[counter] != 0 ) ; ++counter)
	{
		num = num * 10 + (string[counter] - '0');
	}
	return num;
}

bool validate_input(char * input)
{
    int counter;
    bool valid = true;
    
    if ( input[0] == 0)
    {
        valid = false;
    }
    else
    {
        for (counter = 0 ; input[counter] != 0 ; ++input)
        {
            if( (input[counter] > '9') || (input[counter] < '0') )
            {
                valid = false;
            }
        }
    }
    
    return valid;
}

bool a_color(char * string)
{
    char color = string[0];
    bool valid= true;
    
    
    if ((color!=ROJO) && (color!=VERDE) && (color!=AZUL)&&(color!=ROSA)&&(color!=BLANCO))
    {
        valid= false;
    }
    
    if(string[1]!= TERMINADOR)
    {
        valid= false;
    }
    
    return valid;
}
