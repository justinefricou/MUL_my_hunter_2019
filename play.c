/*
** EPITECH PROJECT, 2019
** play.c
** File description:
** my_hunter : game functions
*/

#include "include/play.h"

int play(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *texture_duck;
    sfSprite *sprite_duck;
    sfIntRect rect_duck = {0, 0, 110, 110};
    sfClock *cl_flapping;
    sfTime t_flapping;
    sfColor black = {0, 0, 0, 255};

    texture_duck = sfTexture_createFromFile("my_hunter_spritesheet.png", NULL);
    sprite_duck = sfSprite_create();
    cl_flapping = sfClock_create();
    sfSprite_setTexture(sprite_duck, texture_duck, sfTrue);
    sfSprite_setTextureRect(sprite_duck, rect_duck);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_pollEvent(window, &event);
        handle_events_play(window, event);
        //make_duck_flap(duck);
        sfSprite_setTexture(sprite_duck, texture_duck, sfTrue);
        sfSprite_setTextureRect(sprite_duck, rect_duck);
        sfRenderWindow_clear(window, black);
        sfRenderWindow_drawSprite(window, sprite_duck, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture_duck);
    sfSprite_destroy(sprite_duck);
    sfClock_destroy(cl_flapping);
    return (0);
}