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
#include "pigeons_arrays.h"
#include "background.h"
#include "weapon.h"

int play(sfRenderWindow *window);
void game_loop(sfRenderWindow *w, background_t *b, weapon_t *we, pigeon_t **p);
void update_w_play(sfRenderWindow *w, sfSprite *b, weapon_t *we, pigeon_t **p);

#endif // DEF_PLAY