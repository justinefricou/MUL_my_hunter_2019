/*
** EPITECH PROJECT, 2019
** weapon.c
** File description:
** my_hunter : functions handling weapon
*/

#include "weapon.h"

int create_weapon(weapon_t **weapon, char *filepath)
{
    *weapon = malloc(sizeof(weapon_t));
    (*weapon)->position.x = (800 - 92) / 2;
    (*weapon)->position.y = 600 - 120;
    (*weapon)->texture = sfTexture_createFromFile(filepath, NULL);
    (*weapon)->sprite = sfSprite_create();
    (*weapon)->rect_sprite.top = 0;
    (*weapon)->rect_sprite.left = 0;
    (*weapon)->rect_sprite.width = 92;
    (*weapon)->rect_sprite.height = 160;
    (*weapon)->clock = sfClock_create();
    (*weapon)->sound_buff = sfSoundBuffer_createFromFile("spell_sound.ogg");
    (*weapon)->sound = sfSound_create();
    (*weapon)->font = sfFont_createFromFile("enchanted_land.otf");
    initialize_score(*weapon);
    sfSprite_setTexture((*weapon)->sprite, (*weapon)->texture, sfTrue);
    sfSound_setBuffer((*weapon)->sound, (*weapon)->sound_buff);
    return (0);
}

void initialize_score(weapon_t *weapon)
{
    sfVector2f position = {10, 540};

    weapon->score = 0;
    weapon->score_text = sfText_create();
    sfText_setPosition(weapon->score_text, position);
    sfText_setString(weapon->score_text, "0");
    sfText_setColor(weapon->score_text, sfWhite);
    sfText_setCharacterSize(weapon->score_text, 50);
    sfText_setFont(weapon->score_text, weapon->font);
    sfText_setStyle(weapon->score_text, sfTextBold);
}

void update_score(weapon_t *weapon)
{
    char str[9] = {0};
    int nbr = weapon->score;

    for (int i = 7; i >= 0; i--) {
        str[i] = nbr % 10 + 48;
        nbr /= 10;
    }
    sfText_setString(weapon->score_text, str);
}

void make_wand_sparkle(weapon_t *weapon)
{
    sfTime time;

    time = sfClock_getElapsedTime(weapon->clock);
    if (sfTime_asSeconds(time) > 0.1) {
        sfClock_restart(weapon->clock);
        if (weapon->rect_sprite.left >= weapon->rect_sprite.width)
            weapon->rect_sprite.left = 0;
        else
            weapon->rect_sprite.left += weapon->rect_sprite.width;
        sfSprite_setTextureRect(weapon->sprite, weapon->rect_sprite);
    }
}

void destroy_weapon(weapon_t *weapon)
{
    sfTexture_destroy(weapon->texture);
    sfSprite_destroy(weapon->sprite);
    sfClock_destroy(weapon->clock);
    sfSoundBuffer_destroy(weapon->sound_buff);
    sfSound_destroy(weapon->sound);
    sfText_destroy(weapon->score_text);
    sfFont_destroy(weapon->font);
    free(weapon);
}