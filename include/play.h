/*
** EPITECH PROJECT, 2019
** play.h
** File description:
** my_hunter : game functions (header)
*/

#ifndef DEF_PLAY
#define DEF_PLAY

#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include "events_play.h"
#include "pigeon.h"
#include "background.h"

int play(sfRenderWindow *window);
int create_pigeons_array(pigeon_t ***pigeons, int nbr);
void game_loop(sfRenderWindow *win, background_t *backgrnd, pigeon_t **pigeons);
void update_win_play(sfRenderWindow *w, sfSprite *backgrnd, pigeon_t **pigeons);

#endif // DEF_PLAY