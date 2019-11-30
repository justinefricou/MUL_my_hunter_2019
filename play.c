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
    pigeon_t **pigeons = NULL;

    background = create_background("background.png");
    if (background == NULL)
        return (84);
    if (create_pigeons_array(&pigeons, 5) == 84) {
        destroy_background(background);
        return (84);
    }
    game_loop(window, background, pigeons);
    destroy_background(background);
    for (int i = 0; i < 5; i++)
        destroy_pigeon(pigeons[i]);
    free(pigeons);
    return (0);
}

int create_pigeons_array(pigeon_t ***pigeons, int nbr)
{
    int failed_malloc = 0;
    int i = 0;

    *pigeons = malloc(sizeof(pigeon_t) * nbr);
    if (*pigeons == NULL)
        return (84);
    for ( ; i < nbr && !failed_malloc; i++) {
        (*pigeons)[i] = create_pigeon("pigeon.png", -64, i * 90);
        if ((*pigeons)[i] == NULL)
            failed_malloc = 1;
    }
    if (failed_malloc) {
        for (int j = 0; j < i; j++)
            free((*pigeons)[j]);
        free(*pigeons);
    }
}

void game_loop(sfRenderWindow *win, background_t *backgrnd, pigeon_t **pigeons)
{
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds = 0.0;

    clock = sfClock_create();
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_pollEvent(win, &event);
        handle_events_play(win, event, pigeons);
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
        if (seconds > 0.025) {
            sfClock_restart(clock);
            update_win_play(win, backgrnd->sprite, pigeons);
        }
    }
    sfClock_destroy(clock);
}

void update_win_play(sfRenderWindow *w, sfSprite *backgrnd, pigeon_t **pigeons)
{
    sfRenderWindow_drawSprite(w, backgrnd, NULL);
    for (int i = 0; i < 5; i++) {
        if (pigeons[i]->lives > 0) {
            make_pigeon_flap(pigeons[i]);
            make_pigeon_move(pigeons[i]);
        } else
            make_pigeon_fall(pigeons[i]);
        sfRenderWindow_drawSprite(w, pigeons[i]->sprite, NULL);
    }
        sfRenderWindow_display(w);
}