/*
** EPITECH PROJECT, 2019
** display_usage.c
** File description:
** my_hunter : displays usage.
*/

#include "display_usage.h"

void display_usage(void)
{
    write(1, "\nUSAGE\n", 7);
    write(1, "    ./my_hunter\n\n", 17);
    write(1, "DESCRIPTION\n", 12);
    write(1, "    You are a wizard summoned by a Lord to help him", 51);
    write(1, " besiege a castle.\n", 19);
    write(1, "    Your mission is to prevent your ennemies from reaching "
        "out for help\n", 72);
    write(1, "    by killing the carrier pigeons they send.\n", 46);
    write(1, "    The pigeons appear on the screen and move from one side to "
        "another.\n", 72);
    write(1, "    You can click on them to cast spells and kill "
        "them.\n\n", 57);
}