/*
** EPITECH PROJECT, 2019
** events_play.c
** File description:
** my_hunter : functions handling event during a game.
*/

#include "include/events_play.h"

#include <stdio.h>

void handle_evts_play(sfRenderWindow *w, sfEvent e, weapon_t *we, pigeon_t **p)
{
    switch (e.type) {
    case sfEvtClosed :
        sfRenderWindow_close(w);
        break;
    case sfEvtMouseButtonReleased :
        mouse_click_play(w, e.mouseButton, we, p);
        break;
    default :
        break;
    }
}

/*void manage_window_resized_play(sfRenderWindow *window)
{
    sfVector2u size;

    size = sfRenderWindow_getSize(window);
    if (size.x < 800) {
        size.x = 800;
        sfRenderWindow_setSize(window, size);
    }
    if (size.y < 600) {
        size.y = 600;
        sfRenderWindow_setSize(window, size);
    }
}*/

void mouse_click_play(sfRenderWindow *w, sfMouseButtonEvent e, weapon_t *we,
                        pigeon_t **p)
{
    for (int i = 0; i < 5; i++) {
        if (click_right_x(e, p[i]) && click_right_y(e, p[i])) {
            (p[i]->lives)--;
            sfSound_play(we->sound);
            (p[i]->rect_sprite.top) = 35;
            (p[i]->rect_sprite.height) = 40;
        }
    }
}

int click_right_x(sfMouseButtonEvent event, pigeon_t *pigeon)
{
    if ((pigeon->position).x <= (float)(event.x)) {
        if ((float)(event.x) <= (pigeon->position).x + 64)
            return (1);
    }
    return (0);
}

int click_right_y(sfMouseButtonEvent event, pigeon_t *pigeon)
{
    if ((pigeon->position).y <= (float)(event.y)) {
        if ((float)(event.y) <= (pigeon->position).y + 64)
            return (1);
    }
    return (0);
}