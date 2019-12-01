/*
** EPITECH PROJECT, 2019
** game_over_message.c
** File description:
** my_hunter : game over message functions
*/

#include "include/weapon.h"
#include "include/play.h"

void set_text(sfRenderWindow *w, sfText *line1, sfText *score, sfText *line3);
void handle_events_game_over(sfRenderWindow *window, sfEvent event);
void mouse_click_game_over(sfRenderWindow *window, sfMouseButtonEvent event);

void display_game_over(sfRenderWindow *window, sfText *score)
{
    sfEvent event;
    sfText *first_line, *third_line;
    sfVector2f position1 = {250, 150}, position2 = {350, 220};
    sfVector2f position3 = {250, 350};

    first_line = sfText_create();
    third_line = sfText_create();
    sfText_setPosition(first_line, position1);
    sfText_setPosition(score, position2);
    sfText_setPosition(third_line, position3);
    set_text(window, first_line, score, third_line);
    sfRenderWindow_drawText(window, first_line, NULL);
    sfRenderWindow_drawText(window, score, NULL);
    sfRenderWindow_drawText(window, third_line, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_waitEvent(window, &event);
        handle_events_game_over(window, event);
    }
}

void set_text(sfRenderWindow *w, sfText *line1, sfText *score, sfText *line3)
{
    sfFont *font = NULL;

    font = sfText_getFont(score);
    sfRenderWindow_clear(w, sfWhite);
    sfText_setString(line1, "Game over !  Your score :");
    sfText_setString(line3, "Play again                Quit");
    sfText_setColor(line1, sfBlack);
    sfText_setColor(score, sfBlack);
    sfText_setColor(line3, sfBlack);
    sfText_setCharacterSize(line1, 50);
    sfText_setCharacterSize(line3, 50);
    sfText_setFont(line1, font);
    sfText_setFont(line3, font);
    sfText_setStyle(line1, sfTextBold);
    sfText_setStyle(line3, sfTextBold);
}

void handle_events_game_over(sfRenderWindow *window, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed :
        sfRenderWindow_close(window);
        break;
    case sfEvtMouseButtonReleased :
        mouse_click_game_over(window, event.mouseButton);
    default :
        break;
    }
}

void mouse_click_game_over(sfRenderWindow *window, sfMouseButtonEvent event)
{
    if (250 <= event.x && event.x <= 400 && 350 <= event.y && event.y <= 400)
        play(window);
    if (500 <= event.x && event.x <= 600 && 350 <= event.y && event.y <= 400)
        sfRenderWindow_close(window);
}

/*void set_3rd_line(sfRenderWindow *window, sfText *3rd_line, sfText score)
{

    sfText_setString(3rd_line, "Play again ?");
    sfText_setColor(3rd_line, sfBlack);
    sfText_setCharacterSize(3rd_line, 50);
    sfText_setFont(3rd_line, weapon->font);
}*/