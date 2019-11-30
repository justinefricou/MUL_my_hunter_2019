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
    weapon_t *weapon = NULL;

    if (create_background(&background, "background.png") == 84)
        return (84);
    if (create_weapon(&weapon, "magic_wand.png") == 84) {
        destroy_background(background);
    } else if (create_pigeons_array(&pigeons, 5) == 84) {
        destroy_background(background);
        destroy_weapon(weapon);
        return (84);
    }
    game_loop(window, background, weapon, pigeons);
    destroy_background(background);
    destroy_weapon(weapon);
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
        (*pigeons)[i] = create_pigeon("pigeon.png", -64 * i, i * 90);
        if ((*pigeons)[i] == NULL)
            failed_malloc = 1;
    }
    if (failed_malloc) {
        for (int j = 0; j < i; j++)
            free((*pigeons)[j]);
        free(*pigeons);
    }
}

void game_loop(sfRenderWindow *w, background_t *b, weapon_t *we, pigeon_t **p)
{
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds = 0.0;

    clock = sfClock_create();
    sfSprite_setPosition(we->sprite, we->position);
    while (sfRenderWindow_isOpen(w)) {
        sfRenderWindow_pollEvent(w, &event);
        handle_events_play(w, event, p);
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
        if (seconds > 0.025) {
            sfClock_restart(clock);
            update_w_play(w, b->sprite, we, p);
        }
    }
    sfClock_destroy(clock);
}

void update_w_play(sfRenderWindow *w, sfSprite *b, weapon_t *we, pigeon_t **p)
{
    sfRenderWindow_drawSprite(w, b, NULL);
    for (int i = 0; i < 5; i++) {
        if (p[i]->lives > 0) {
            make_pigeon_flap(p[i]);
            make_pigeon_move(p[i]);
        } else
            make_pigeon_fall(p[i]);
        sfRenderWindow_drawSprite(w, p[i]->sprite, NULL);
    }
    make_wand_shine(we);
    sfRenderWindow_drawSprite(w, we->sprite, NULL);
    sfRenderWindow_display(w);
}