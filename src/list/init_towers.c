/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** init_towers
*/
#include "../my.h"

void tower_hitbox(tower_t *tower)
{
    tower->hitbox = sfCircleShape_create();
    sfCircleShape_setRadius(tower->hitbox, tower->radius);
    sfCircleShape_setOutlineColor(tower->hitbox, sfGreen);
    sfCircleShape_setOutlineThickness(tower->hitbox, 2);
    sfCircleShape_setFillColor(tower->hitbox, sfTransparent);
    sfCircleShape_setOrigin(tower->hitbox,
        (sfVector2f){tower->radius, tower->radius});
    sfCircleShape_setPosition(tower->hitbox,
        (sfVector2f) {tower->position.x, tower->position.y});
}

void tower_sprite(tower_t *tower, sim_t *sim)
{
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, sim->t_texture, sfTrue);
    sfSprite_setOrigin(tower->sprite, (sfVector2f){15, 15});
    sfSprite_setPosition(tower->sprite, tower->position);
}

void init_tower(char **array, sim_t *sim)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (!tower || tower_error(array) == 84)
        return;
    tower->position.x = my_atof(array[1]);
    tower->position.y = my_atof(array[2]);
    tower->radius = my_atof(array[3]);
    tower_sprite(tower, sim);
    tower_hitbox(tower);
    tower->next = sim->t_head;
    sim->t_head = tower;
}
