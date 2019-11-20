/*
** EPITECH PROJECT, 2019
** analyse_events.c
** File description:
** Functions handling events
*/

#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>

void manage_mouse_click(sfMouseButtonEvent event, sfIntRect rect_duck)
{
   /* if ()
    event.x;
    event.y;
*/
}

void handle_events(sfRenderWindow *window, sfEvent event, sfIntRect rect_duck)
{
    switch (event.type) {
    /*case sfEvtMouseButtonReleased :
        manage_mouse_click(event.mouseButton, rect_duck);
        break;*/
    case sfEvtClosed :
        sfRenderWindow_close(window);
        break;
    }
}