/*
** EPITECH PROJECT, 2019
** analyse_events.c
** File description:
** Functions handling events
*/

#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>

void move_rect(sfIntRect *rect_duck, int max_value);

void manage_mouse_click(sfMouseButtonEvent event, sfSprite *sprite_duck, sfClock clock1, sfClock clock2)
{
    sfVector2d vect_duck;

    vect_duck = sfSprite_getPosition(sprite_duck);
    if (vect_duck.x <= event.x <= vect_duck.x + 110) {
        sfClock_destroy(clock_moving);
        duck_fall()
    } else if (vect_duck.y <= event.y <= vect_duck.y + 110) {
        sfClock_destroy(clock_moving);
    }
}

void handle_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite_duck, sfClock clock1, sfClock clock2)
{
    switch (event.type) {
    case sfEvtMouseButtonReleased :
       manage_mouse_click(event.mouseButton, sprite_duck, clock1, clock2);
        break;
    case sfEvtClosed :
        sfRenderWindow_close(window);
        break;
    }
}