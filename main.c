/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** my_hunter : main function
*/

#include "include/main.h"

int main(int argc, char **argv)
{
    sfRenderWindow *window = NULL;
    sfVideoMode vid_mode = {800, 600, 32};

    if (argc > 1) {
        display_usage();
        return (0);
    }
    window = sfRenderWindow_create(vid_mode, "my_hunter", sfDefaultStyle, NULL);
    play(window);
    sfRenderWindow_destroy(window);
    return (0);
}