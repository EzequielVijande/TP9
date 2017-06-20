/*
 Modulo que se encarga de validar e interpretar el input recibido
 */

/* 
 * File:   input.h
 * Author: ezequiel
 *
 * Created on June 17, 2017, 7:54 PM
 */

#ifndef INPUT_H
#define INPUT_H

//COLORES
#define ROJO 'r'
#define AZUL 'b'
#define VERDE 'g'
#define ROSA 'p'
#define BLANCO 'w'

int convert_char (char * string);
//recibe un numero en forma de string y devuelve su valor

bool validate_input(char * input);
//se fija si el string que recibe esta compuesto unicamente por
//numeros. Si es asi, devuelve true, en caso contrario devuelve false.

bool a_color(char * string);
//devuelve si el string cumple el formato de un color

#endif /* INPUT_H */

