/*
** EPITECH PROJECT, 2019
** background.c
** File description:
** my_hunter : functions handling backgrounds
*/

#include "include/background.h"

background_t *create_background(char *filepath)
{
    background_t *background = NULL;

    background = malloc(sizeof(background_t));
    if (background != NULL) {
        background->texture = sfTexture_createFromFile(filepath, NULL);
        background->sprite = sfSprite_create();
        sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    }
    return (background);
}

void destroy_background(background_t *background)
{
    sfTexture_destroy(background->texture);
    sfSprite_destroy(background->sprite);
    free(background);
}