/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** init_planes
*/
#include "../my.h"

void plane_vector(plane_t *plane)
{
    plane->vector = (sfVector2f)
        {plane->e_pos.x - plane->s_pos.x,
        plane->e_pos.y - plane->s_pos.y};
    plane->vector = (sfVector2f)
        {plane->vector.x * plane->speed /
        sqrt(powf(plane->vector.x, 2) + powf(plane->vector.y, 2)) / 60.0,
        plane->vector.y * plane->speed /
        sqrt(powf(plane->vector.x, 2) + powf(plane->vector.y, 2)) / 60.0};
}

void plane_sprite(plane_t *plane, sim_t *sim)
{
    plane->sprite = sfSprite_create();
    sfSprite_setTexture(plane->sprite, sim->p_texture, sfTrue);
    sfSprite_setOrigin(plane->sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(plane->sprite, plane->s_pos);
    sfSprite_setRotation(plane->sprite, atan2f(plane->vector.y,
        plane->vector.x) * (180.0f / 3.1415));
}

void plane_hitbox(plane_t *plane)
{
    plane->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(plane->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(plane->hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setOutlineColor(plane->hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(plane->hitbox, 1);
    sfRectangleShape_setFillColor(plane->hitbox, sfTransparent);
    sfRectangleShape_setPosition(plane->hitbox, plane->c_pos);
    sfRectangleShape_setRotation(plane->hitbox,
        atan2f(plane->vector.y, plane->vector.x) * (180.0f / 3.1415));
}

void init_plane(char **array, sim_t *sim)
{
    plane_t *plane = malloc(sizeof(plane_t));

    if (!plane || plane_error(array) == 84)
        return;
    plane->s_pos.x = my_atof(array[1]);
    plane->s_pos.y = my_atof(array[2]);
    plane->c_pos.x = my_atof(array[1]);
    plane->c_pos.y = my_atof(array[2]);
    plane->e_pos.x = my_atof(array[3]);
    plane->e_pos.y = my_atof(array[4]);
    plane->speed = my_atof(array[5]);
    plane->time = my_atof(array[6]);
    plane->dead = 0;
    plane->safe = 1;
    plane_vector(plane);
    plane_sprite(plane, sim);
    plane_hitbox(plane);
    plane->next = sim->p_head;
    sim->p_head = plane;
    plane->next_collide = NULL;
}
