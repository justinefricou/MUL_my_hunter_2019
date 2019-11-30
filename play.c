/*
** EPITECH PROJECT, 2019
** play.c
** File description:
** my_hunter : game functions
*/

#include "include/play.h"

int play(sfRenderWindow *window)
{
    background_t *background = NULL;
    pigeon_t *pigeon = NULL;

    background = create_background("background.png");
    if (background == NULL)
        return (84);
    pigeon = create_pigeon("pigeon.png", 0, 0);
    if (pigeon == NULL) {
        destroy_background(background);
        return (84);
    }
    game_loop(window, background, pigeon);
    destroy_background(background);
    destroy_pigeon(pigeon);
    return (0);
}

void game_loop(sfRenderWindow *win, background_t *background, pigeon_t *pigeon)
{
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds = 0.0;

    clock = sfClock_create();
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_pollEvent(win, &event);
        handle_events_play(win, event);
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
        if (seconds > 0.025) {
            sfClock_restart(clock);
            make_pigeon_flap(pigeon);
            make_pigeon_move(pigeon);
            update_win_play(win, background->sprite, pigeon);
        }
    }
    sfClock_destroy(clock);
}

void update_win_play(sfRenderWindow *win, sfSprite *backgrnd, pigeon_t *pigeon)
{
    sfRenderWindow_drawSprite(win, backgrnd, NULL);
    sfRenderWindow_drawSprite(win, pigeon->sprite, NULL);
    sfRenderWindow_display(win);
}