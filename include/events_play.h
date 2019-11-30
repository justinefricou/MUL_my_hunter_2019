/*
** EPITECH PROJECT, 2019
** events_play.h
** File description:
** my_hunter : functions handling event during a game. (header)
*/

#ifndef DEF_EVENTS_PLAY
#define DEF_EVENTS_PLAY

#include <SFML/Graphics/RenderWindow.h>
#include "pigeon.h"

void handle_events_play(sfRenderWindow *win, sfEvent event, pigeon_t **pigeons);
void manage_mouse_click_play(sfMouseButtonEvent event, pigeon_t **pigeons);
int click_right_x(sfMouseButtonEvent event, pigeon_t *pigeon);
int click_right_y(sfMouseButtonEvent event, pigeon_t *pigeon);

#endif // DEF_EVENTS_PLAY