/*
** EPITECH PROJECT, 2019
** duck.h
** File description:
** Structure : duck
*/

#ifndef DEF_DUCK
#define DEF_DUCK

#include <SFML/Graphics/Sprite.h>

typedef struct duck {
    sfSprite sprite;
    sfIntRect rect;
    sfVector2f position;
    sfClock cl_moving;
    sfClock cl_flapping;
} duck_t;

#endif //DEF_DUCK