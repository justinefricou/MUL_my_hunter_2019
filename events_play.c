/*
** EPITECH PROJECT, 2019
** events_play.c
** File description:
** my_hunter : functions handling event during a game.
*/

#include "include/events_play.h"

void handle_events_play(sfRenderWindow *win, sfEvent event, pigeon_t **pigeons)
{
    switch (event.type) {
    case sfEvtClosed :
        sfRenderWindow_close(win);
        break;
    case sfEvtMouseButtonReleased :
        manage_mouse_click_play(event.mouseButton, pigeons);
        break;
    }
}

void manage_mouse_click_play(sfMouseButtonEvent evnt, pigeon_t **pigeons)
{
    for (int i = 0; i < 5; i++) {
        if (click_right_x(evnt, pigeons[i]) && click_right_y(evnt, pigeons[i]))
            (pigeons[i]->lives)--;
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