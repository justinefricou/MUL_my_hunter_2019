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


void handle_events(sfRenderWindow *window, sfEvent event, sfIntRect rect_duck);
void game(sfRenderWindow *window);
void move_rect(sfIntRect *rect_duck, int offset, int max_value);

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
    sfClock *clock;
    sfTime time;
    float seconds;
    sfColor black = {0, 0, 0, 255};

    texture_duck = sfTexture_createFromFile("my_hunter_spritesheet.png", NULL);
    sprite_duck = sfSprite_create();
    sfSprite_setTexture(sprite_duck, texture_duck, sfTrue);
    sfSprite_setTextureRect(sprite_duck, rect_duck);
    clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 1.0) {
            move_rect(&rect_duck, 0, 330);
            sfClock_restart(clock);
        }
        sfRenderWindow_pollEvent(window, &event);
        handle_events(window, event, rect_duck);
        sfRenderWindow_clear(window, black);
        sfRenderWindow_drawSprite(window, sprite_duck, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture_duck);
    sfSprite_destroy(sprite_duck);
    sfClock_destroy(clock);
}

void move_rect(sfIntRect *rect_duck, int offset, int max_value)
{
    if (rect_duck->left == max_value)
        rect_duck->left = offset;
    else
        rect_duck->left += rect_duck->width;
}