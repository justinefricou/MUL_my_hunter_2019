/*
** EPITECH PROJECT, 2019
** events_play.c
** File description:
** my_hunter : functions handling event during a game.
*/

#include "include/events_play.h"

void handle_events_play(sfRenderWindow *win, sfEvent event, pigeon_t *pigeon)
{
    switch (event.type) {
    case sfEvtClosed :
        sfRenderWindow_close(win);
        break;
    case sfEvtMouseButtonReleased :
        manage_mouse_click_play(event.mouseButton, pigeon);
        break;
    }
}

void manage_mouse_click_play(sfMouseButtonEvent event, pigeon_t *pigeon)
{
    if (click_at_right_x(event, pigeon) && click_at_right_y(event, pigeon))
        (pigeon->lives)--;
}

int click_at_right_x(sfMouseButtonEvent event, pigeon_t *pigeon)
{
    if ((pigeon->position).x <= (float)(event.x)) {
        if ((float)(event.x) <= (pigeon->position).x + 64)
            return (1);
    }
    return (0);
}

int click_at_right_y(sfMouseButtonEvent event, pigeon_t *pigeon)
{
    if ((pigeon->position).y <= (float)(event.y)) {
        if ((float)(event.y) <= (pigeon->position).y + 64)
            return (1);
    }
    return (0);
}