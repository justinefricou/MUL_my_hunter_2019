/*
** EPITECH PROJECT, 2019
** play.c
** File description:
** my_hunter : game functions
*/

#include "include/play.h"

int play(sfRenderWindow *window)
{
    sfEvent event;
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
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_pollEvent(window, &event);
        handle_events_play(window, event);
        update_win_play(window, background->sprite, pigeon);
    }
    destroy_background(background);
    destroy_pigeon(pigeon);
    return (0);
}

void update_win_play(sfRenderWindow *win, sfSprite *backgrnd, pigeon_t *pigeon)
{
    sfTime t_flapping;
    float sec_flapping = 0.0;

    t_flapping = sfClock_getElapsedTime(pigeon->cl_flapping);
    sec_flapping = sfTime_asSeconds(t_flapping);
    if (sec_flapping > 0.05) {
        sfClock_restart(pigeon->cl_flapping);
        make_pigeon_flap(pigeon);
        make_pigeon_move(pigeon);
        sfRenderWindow_drawSprite(win, backgrnd, NULL);
        sfRenderWindow_drawSprite(win, pigeon->sprite, NULL);
        sfRenderWindow_display(win);
    }
}