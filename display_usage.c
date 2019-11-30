/*
** EPITECH PROJECT, 2019
** display_usage.c
** File description:
** my_hunter : displays usage.
*/

#include "include/display_usage.h"

void display_usage()
{
    write(1, "\nUSAGE\n", 7);
    write(1, "    ./my_hunter\n\n", 17);
    write(1, "DESCRIPTION\n", 12);
    write(1, "    You are a hunter who shoots ducks.\n", 39);
    write(1, "    Ducks appear on the screen and move from one side to "
        "another.\n", 66);
    write(1, "    You can click on them to shoot them.\n\n", 42);
}