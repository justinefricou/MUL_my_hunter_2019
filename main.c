/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** my_hunter : main function
*/

#include <unistd.h>
#include <SFML/System/Export.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Clock.h>
#include "include/duck.h"

void handle_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite_duck, sfClock clock1, sfClock clock2);
void game(sfRenderWindow *window);
void move_rect(sfIntRect *rect_duck, int max_value);
void move_duck(sfSprite *sprite_duck);

int main(int ac, char **av)
{
    sfRenderWindow *window = NULL;
    sfVideoMode vid_mode = {800, 600, 32};

    window = sfRenderWindow_create(vid_mode, "my_hunter", sfDefaultStyle, NULL);
    game(window);
    sfRenderWindow_destroy(window);
    return (0);
}

void game(sfRenderWindow *window)
{
    sfTexture *texture_duck = NULL;
    sfSprite *sprite_duck = NULL;
    sfEvent event;
    sfIntRect rect_duck = {0, 0, 110, 110};
    sfClock *clock_flapping;
    sfClock *clock_moving;
    sfTime time_flapping;
    float seconds_flapping;
    sfTime time_moving;
    float seconds_moving;
    sfColor black = {0, 0, 0, 255};

    texture_duck = sfTexture_createFromFile("my_hunter_spritesheet.png", NULL);
    sprite_duck = sfSprite_create();
    sfSprite_setTexture(sprite_duck, texture_duck, sfTrue);
    sfSprite_setTextureRect(sprite_duck, rect_duck);
    clock_flapping = sfClock_create();
    clock_moving = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        time_flapping = sfClock_getElapsedTime(clock_flapping);
        seconds_flapping = time_flapping.microseconds / 1000000.0;
        if (seconds_flapping > 0.2) {
            move_rect(&rect_duck, 220);
            sfClock_restart(clock_flapping);
        }
        time_moving = sfClock_getElapsedTime(clock_moving);
        seconds_moving = time_moving.microseconds / 1000000.0;
        if (seconds_moving > 0.1) {
            move_rect_duck(sprite_duck);
            sfClock_restart(clock_moving);
        }
        sfSprite_setTexture(sprite_duck, texture_duck, sfTrue);
        sfSprite_setTextureRect(sprite_duck, rect_duck);
        sfRenderWindow_pollEvent(window, &event);
        handle_events(window, event, sprite_duck, clock_flapping, clock_moving);
        sfRenderWindow_clear(window, black);
        sfRenderWindow_drawSprite(window, sprite_duck, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture_duck);
    sfSprite_destroy(sprite_duck);
}

void move_rect_duck(sfIntRect *rect_duck, int max_value)
{
    int going_foward = 1;

    if (rect_duck->left == max_value)
        going_foward = 0;
    else if (rect_duck->left == 0)
        going_foward = 1;
    if (going_foward)
        rect_duck->left += rect_duck->width;
    else
        rect_duck->left -= rect_duck->width;
}

void move_duck(sfSprite *sprite_duck)
{
    sfVector2f vect_duck;

    vect_duck = sfSprite_getPosition(sprite_duck);
    if (vect_duck.x == 800)
        vect_duck.x = 0;
    else
        vect_duck.x += 10;
    sfSprite_setPosition(sprite_duck, vect_duck);
}