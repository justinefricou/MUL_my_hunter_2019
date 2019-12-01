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
#include "weapon.h"

void handle_evts_play(sfRenderWindow *w, sfEvent e, weapon_t *we, pigeon_t **p);
void manage_window_resized_play(sfRenderWindow *window);
void mouse_click_play(sfRenderWindow *w, sfMouseButtonEvent e, weapon_t *we,
                        pigeon_t **p);
int click_right_x(sfMouseButtonEvent event, pigeon_t *pigeon);
int click_right_y(sfMouseButtonEvent event, pigeon_t *pigeon);

#endif // DEF_EVENTS_PLAY