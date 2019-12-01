/*
** EPITECH PROJECT, 2019
** game_over_message.c
** File description:
** my_hunter : game over message functions
*/

#include "include/weapon.h"
#include "include/play.h"

void set_1st_line(sfRenderWindow *window, sfText *first_line, sfText *score);
void handle_events_game_over(sfRenderWindow *window, sfEvent event);

void display_game_over(sfRenderWindow *window, sfText *score)
{
    sfEvent event;
    sfText *first_line;
    sfVector2f position1 = {250, 200};
    sfVector2f position2 = {350, 300};

    first_line = sfText_create();
    sfText_setPosition(first_line, position1);
    sfText_setPosition(score, position2);
    set_1st_line(window, first_line, score);
    sfRenderWindow_drawText(window, first_line, NULL);
    sfRenderWindow_drawText(window, score, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_waitEvent(window, &event);
        handle_events_game_over(window, event);
    }
}

void set_1st_line(sfRenderWindow *window, sfText *first_line, sfText *score)
{
    sfFont *font = NULL;

    font = sfText_getFont(score);
    sfRenderWindow_clear(window, sfWhite);
    sfText_setString(first_line, "Game over !  Your score :");
    sfText_setColor(first_line, sfBlack);
    sfText_setColor(score, sfBlack);
    sfText_setCharacterSize(first_line, 50);
    sfText_setFont(first_line, font);
    sfText_setStyle(first_line, sfTextBold);
}

void handle_events_game_over(sfRenderWindow *window, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed :
        sfRenderWindow_close(window);
        break;
    default :
        break;
    }
}

/*void set_3rd_line(sfRenderWindow *window, sfText *3rd_line, sfText score)
{

    sfText_setString(3rd_line, "Play again ?");
    sfText_setColor(3rd_line, sfBlack);
    sfText_setCharacterSize(3rd_line, 50);
    sfText_setFont(3rd_line, weapon->font);
}*/