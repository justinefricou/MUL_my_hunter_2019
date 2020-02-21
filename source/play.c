/*
** EPITECH PROJECT, 2019
** play.c
** File description:
** my_hunter : game functions
*/

#include "include/play.h"

void display_game_over(sfRenderWindow *window, sfText *score);

int play(sfRenderWindow *window)
{
    background_t *background = NULL;
    pigeon_t **pigeons = NULL;
    weapon_t *weapon = NULL;
    sfText *score = NULL;

    create_background(&background, "background.png");
    create_weapon(&weapon, "magic_wand.png");
    create_pigeons_array(&pigeons, 5);
    game_loop(window, background, weapon, pigeons);
    score = weapon->score_text;
    destroy_background(background);
    for (int i = 0; i < 5; i++)
        destroy_pigeon(pigeons[i]);
    free(pigeons);
    display_game_over(window, score);
    destroy_weapon(weapon);
    return (0);
}

void game_loop(sfRenderWindow *w, background_t *b, weapon_t *we, pigeon_t **p)
{
    sfEvent event;
    sfClock *clock;
    sfTime time;

    clock = sfClock_create();
    sfSprite_setPosition(we->sprite, we->position);
    while (sfRenderWindow_isOpen(w) && !pigeons_survived(p)) {
        sfRenderWindow_pollEvent(w, &event);
        handle_evts_play(w, event, we, p);
        time = sfClock_getElapsedTime(clock);
        update_age_pigeons(p, time);
        if (sfTime_asSeconds(time) > 0.020) {
            sfClock_restart(clock);
            update_w_play(w, b->sprite, we, p);
        }
    }
    if (pigeons_survived(p));
    sfClock_destroy(clock);
}

int pigeons_survived(pigeon_t **pigeons)
{
    for (int i = 0; i < 5; i++) {
        if ((pigeons[i])->survived)
            return (1);
    }
    return (0);
}

void update_w_play(sfRenderWindow *w, sfSprite *b, weapon_t *we, pigeon_t **p)
{
    sfRenderWindow_drawSprite(w, b, NULL);
    update_pigeons_array(p);
    for (int i = 0; i < 5; i++) {
        if ((p[i])->lives > 0) {
            make_pigeon_flap(p[i]);
            make_pigeon_move(p[i]);
        } else
            make_pigeon_fall(p[i], we);
        sfRenderWindow_drawSprite(w, p[i]->sprite, NULL);
    }
    make_wand_sparkle(we);
    sfRenderWindow_drawSprite(w, we->sprite, NULL);
    update_score(we);
    sfRenderWindow_drawText(w, we->score_text, NULL);
    sfRenderWindow_display(w);
}