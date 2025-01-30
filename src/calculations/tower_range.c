/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** tower_range
*/
#include "../my.h"

int loop_in_tower_list(sim_t *sim, plane_t *p)
{
    tower_t *t = sim->t_head;
    int in_range = 0;

    while (t) {
        if (sqrtf(powf(p->c_pos.x - t->position.x, 2) +
            powf(p->c_pos.y - t->position.y, 2)) <= t->radius) {
            in_range = 1;
            break;
        }
        t = t->next;
    }
    if (in_range) {
        sfRectangleShape_setOutlineColor(p->hitbox, sfGreen);
        p->safe = 1;
    } else {
        sfRectangleShape_setOutlineColor(p->hitbox, sfRed);
        p->safe = 0;
    }
}

void in_tower_range(sim_t *sim)
{
    plane_t *p = sim->p_head;
    int in_range = 0;

    while (p && p->time < sim->time / 1000) {
        loop_in_tower_list(sim, p);
        p = p->next;
    }
}
