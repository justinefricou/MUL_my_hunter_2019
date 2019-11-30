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
void game_loop(sfRenderWindow *win, background_t *background, pigeon_t *pigeon);
void update_win_play(sfRenderWindow *win, sfSprite *backgrnd, pigeon_t *pigeon);

#endif // DEF_PLAY