/*
** EPITECH PROJECT, 2019
** background.c
** File description:
** my_hunter : functions handling backgrounds
*/

#include "background.h"

int create_background(background_t **background, char *filepath)
{
    *background = malloc(sizeof(background_t));
    if (*background == NULL)
        return (84);
    (*background)->texture = sfTexture_createFromFile(filepath, NULL);
    (*background)->sprite = sfSprite_create();
    sfSprite_setTexture((*background)->sprite, (*background)->texture, sfTrue);
    return (0);
}

void destroy_background(background_t *background)
{
    sfTexture_destroy(background->texture);
    sfSprite_destroy(background->sprite);
    free(background);
}