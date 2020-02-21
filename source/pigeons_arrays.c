/*
** EPITECH PROJECT, 2019
** pigeons_arrays.c
** File description:
** my_hunter : functions to work with pigeons arrays
*/

#include "pigeons_arrays.h"

int create_pigeons_array(pigeon_t ***pigeons, int nbr)
{
    int failed_malloc = 0;
    int i = 0;

    *pigeons = malloc(sizeof(pigeon_t) * nbr);
    if (*pigeons == NULL)
        return (84);
    for ( ; i < nbr && !failed_malloc; i++) {
        (*pigeons)[i] = create_pigeon("pigeon.png", -64 * i, i * 90);
        if ((*pigeons)[i] == NULL)
            failed_malloc = 1;
    }
    if (failed_malloc) {
        for (int j = 0; j < i; j++)
            free((*pigeons)[j]);
        free(*pigeons);
    }
}

void update_age_pigeons(pigeon_t **pigeons, sfTime time)
{
    for (int i = 0; i < 5; i++)
        ((pigeons[i])->age) += sfTime_asSeconds(time);
}

void update_pigeons_array(pigeon_t **pigeons)
{
    for (int i = 0; i < 5; i++) {
        if (((pigeons[i])->age) > 10000.0 + 1000.0 * i) {
            pigeons[i]->survived = 0;
            pigeons[i]->lives = 1;
            pigeons[i]->age = 0.0;
            (pigeons[i]->position).x = -64;
            (pigeons[i]->position).y = i * 90;
            (pigeons[i]->rect_sprite).top = 0;
            (pigeons[i]->rect_sprite).left = 0;
        }
    }
}