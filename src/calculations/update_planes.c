/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** update_planes
*/
#include "../my.h"

void dead_planes_removal(plane_t **prev, plane_t **current, sim_t *sim)
{
    plane_t *to_free;

    if (*current && (*current)->dead == 1) {
        to_free = *current;
        if (*prev == NULL)
            sim->p_head = (*current)->next;
        else
            (*prev)->next = (*current)->next;
        *current = (*current)->next;
        free_plane(to_free);
        sim->dead--;
    } else {
        *prev = *current;
        *current = (*current)->next;
    }
}

void dead_planes(sim_t *sim)
{
    plane_t *current = sim->p_head;
    plane_t *prev = NULL;

    while (current && sim->dead >= 1)
        dead_planes_removal(&prev, &current, sim);
}

void plane_reached_destination(plane_t *current, sim_t *sim)
{
    float dx_start = current->e_pos.x - current->s_pos.x +
        current->e_pos.y - current->s_pos.y;
    float dx_current = current->e_pos.x - current->c_pos.x +
        current->e_pos.y - current->c_pos.y;

    if ((dx_start * dx_current < 0)) {
        current->dead = 1;
        sim->dead++;
    }
}

void move_planes(sim_t *sim)
{
    plane_t *current = sim->p_head;

    while (current != NULL) {
        if (current->time > sim->time / 1000.0)
            break;
        current->c_pos.x += current->vector.x;
        current->c_pos.y += current->vector.y;
        sfSprite_setPosition(current->sprite, current->c_pos);
        plane_reached_destination(current, sim);
        sfRectangleShape_setPosition(current->hitbox, current->c_pos);
        current = current->next;
    }
}
