/*
** EPITECH PROJECT, 2019
** events_play.c
** File description:
** my_hunter : functions handling event during a game.
*/

#include "include/events_play.h"

void handle_events_play(sfRenderWindow *window, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed :
        sfRenderWindow_close(window);
        break;
    }
}