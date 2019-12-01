/*
** EPITECH PROJECT, 2019
** pigeon.c
** File description:
** my_hunter : functions handling pigeons
*/

#include "include/pigeon.h"

#include <stdio.h>

pigeon_t *create_pigeon(char *filepath, int x, int y)
{
    pigeon_t *pigeon = NULL;

    pigeon = malloc(sizeof(pigeon_t));
    if (pigeon != NULL) {
        pigeon->lives = 1;
        pigeon->age = 0.0;
        (pigeon->position).x = x;
        (pigeon->position).y = y;
        pigeon->texture = sfTexture_createFromFile(filepath, NULL);
        pigeon->sprite = sfSprite_create();
        (pigeon->rect_sprite).top = 0;
        (pigeon->rect_sprite).left = 0;
        (pigeon->rect_sprite).width = 64;
        (pigeon->rect_sprite).height = 30;
        pigeon->cl_flapping = sfClock_create();
        pigeon->cl_moving = sfClock_create();
        sfSprite_setTexture(pigeon->sprite, pigeon->texture, sfTrue);
        sfSprite_setTextureRect(pigeon->sprite, pigeon->rect_sprite);
    }
    return (pigeon);
}

void make_pigeon_flap(pigeon_t *pigeon)
{
    sfTime time;

    time = sfClock_getElapsedTime(pigeon->cl_flapping);
    if (sfTime_asSeconds(time) > 0.1) {
        sfClock_restart(pigeon->cl_flapping);
        if (pigeon->rect_sprite.left == pigeon->rect_sprite.width * 3)
            pigeon->rect_sprite.left = 0;
        else
            pigeon->rect_sprite.left += pigeon->rect_sprite.width;
        sfSprite_setTextureRect(pigeon->sprite, pigeon->rect_sprite);
    }
}

void make_pigeon_move(pigeon_t *pigeon)
{
    sfTime time;

    time = sfClock_getElapsedTime(pigeon->cl_moving);
    if (sfTime_asSeconds(time) > 0.025) {
        sfClock_restart(pigeon->cl_moving);
        if ((pigeon->position).x < 800)
            (pigeon->position).x += 5;
        sfSprite_setPosition(pigeon->sprite, pigeon->position);
    }
}

void make_pigeon_fall(pigeon_t *pigeon)
{
    sfTime time;

    time = sfClock_getElapsedTime(pigeon->cl_moving);
    if (sfTime_asSeconds(time) > 0.025) {
        sfClock_restart(pigeon->cl_moving);
        if ((pigeon->position).y < 550) {
            (pigeon->position).y += (int)(5 + (pigeon->position).y / 35);
            (pigeon->position).x += 5;
            pigeon->rect_sprite.left = 128;
        } else
            pigeon->rect_sprite.left = 0;
        sfSprite_setTextureRect(pigeon->sprite, pigeon->rect_sprite);
        sfSprite_setPosition(pigeon->sprite, pigeon->position);
        if (pigeon->rect_sprite.top > 32)
            (pigeon->rect_sprite.top)--;
        else if (pigeon->rect_sprite.top != 0)
            (pigeon->rect_sprite.top) = 0;
    }
}

void destroy_pigeon(pigeon_t *pigeon)
{
    sfTexture_destroy(pigeon->texture);
    sfSprite_destroy(pigeon->sprite);
    sfClock_destroy(pigeon->cl_flapping);
    sfClock_destroy(pigeon->cl_moving);
    free(pigeon);
}