/*
** EPITECH PROJECT, 2019
** pigeon.h
** File description:
** my_hunter : pigeon (structure)
*/

#ifndef DEF_PIGEON
#define DEF_PIGEON

#include <stdlib.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>

typedef struct pigeon {
    int lives;
    float age;
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect_sprite;
    sfClock *cl_flapping;
    sfClock *cl_moving;
} pigeon_t;

pigeon_t *create_pigeon(char *filepath, int x, int y);
void make_pigeon_flap(pigeon_t *pigeon);
void make_pigeon_move(pigeon_t *pigeon);
void make_pigeon_fall(pigeon_t *pigeon);
void destroy_pigeon(pigeon_t *pigeon);

#endif // DEF_PIGEON