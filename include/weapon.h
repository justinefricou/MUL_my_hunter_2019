/*
** EPITECH PROJECT, 2019
** weapon.h
** File description:
** my_hunter : weapon (structure)
*/

#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <stdlib.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>

typedef struct weapon {
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect_sprite;
    sfClock *clock;
} weapon_t;

int create_weapon(weapon_t **weapon, char *filepath);
void make_wand_shine(weapon_t *weapon);
void destroy_weapon(weapon_t *weapon);

#endif // DEF_WEAPON