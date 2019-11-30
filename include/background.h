/*
** EPITECH PROJECT, 2019
** background.h
** File description:
** my_hunter : background (structure)
*/

#ifndef DEF_BACKGROUND
#define DEF_BACKGROUND

#include <stdlib.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

typedef struct background {
    sfTexture *texture;
    sfSprite *sprite;
} background_t;

background_t *create_background(char *filepath);
void destroy_background(background_t *background);

#endif // DEF_BACKGROUND