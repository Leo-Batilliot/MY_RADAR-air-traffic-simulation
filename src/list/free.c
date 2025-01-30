/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** free
*/
#include "../my.h"

void free_plane(plane_t *plane)
{
    sfSprite_destroy(plane->sprite);
    sfRectangleShape_destroy(plane->hitbox);
    free(plane);
}

void free_tower(tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    sfCircleShape_destroy(tower->hitbox);
    free(tower);
}

void free_linked_lists(sim_t *sim)
{
    plane_t *current_p;
    tower_t *current_t;

    while (sim->p_head) {
        current_p = sim->p_head;
        sim->p_head = current_p->next;
        free_plane(current_p);
    }
    while (sim->t_head) {
        current_t = sim->t_head;
        sim->t_head = current_t->next;
        free_tower(current_t);
    }
}

void free_sim(sim_t *sim)
{
    free_linked_lists(sim);
    sfTexture_destroy(sim->p_texture);
    sfTexture_destroy(sim->t_texture);
    sfText_destroy(sim->hitbox_text);
    sfText_destroy(sim->sprite_text);
    sfText_destroy(sim->fps_text);
    sfText_destroy(sim->time_string);
    sfFont_destroy(sim->font);
    sfTexture_destroy(sim->map_texture);
    sfSprite_destroy(sim->map_sprite);
    sfClock_destroy(sim->clock);
    sfClock_destroy(sim->paused_clock);
    free(sim);
}
