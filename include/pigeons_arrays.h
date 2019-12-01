/*
** EPITECH PROJECT, 2019
** pigeons_arrays.h
** File description:
** my_hunter : functions to work with pigeons arrays (header)
*/

#ifndef DEF_PIGEONS_ARRAYS
#define DEF_PIGEONS_ARRAYS

#include "pigeon.h"

int create_pigeons_array(pigeon_t ***pigeons, int nbr);
void update_age_pigeons(pigeon_t **pigeons, sfTime time);
void update_pigeons_array(pigeon_t **pigeons);

#endif // DEF_PIGEONS_ARRAYS