/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** window
*/
#include "../my.h"

void print_text(sim_t *sim, sfRenderWindow *window)
{
    char *time = concat("TIME : ", (float_to_text(sim->time / 1000.0)));

    fps_count(sim);
    if (sim->hitbox_enabled)
        sfText_setString(sim->hitbox_text, "HITBOXES ON");
    else
        sfText_setString(sim->hitbox_text, "HITBOXES OFF");
    if (sim->sprite_enabled)
        sfText_setString(sim->sprite_text, "SPRITES ON");
    else
        sfText_setString(sim->sprite_text, "SPRITES OFF");
    sfText_setString(sim->time_string, time);
    sfRenderWindow_drawText(window, sim->time_string, NULL);
    sfRenderWindow_drawText(window, sim->hitbox_text, NULL);
    sfRenderWindow_drawText(window, sim->sprite_text, NULL);
    sfRenderWindow_drawText(window, sim->fps_text, NULL);
    free(time);
}

void print_towers(tower_t *tower, sim_t *sim, sfRenderWindow *window)
{
    if (sim->sprite_enabled == 1)
        sfRenderWindow_drawSprite(window, tower->sprite, NULL);
    if (sim->hitbox_enabled == 1)
        sfRenderWindow_drawCircleShape(window, tower->hitbox, NULL);
}

void print_planes(plane_t *plane, sim_t *sim, sfRenderWindow *window)
{
    if (sim->sprite_enabled == 1)
        sfRenderWindow_drawSprite(window, plane->sprite, NULL);
    if (sim->hitbox_enabled == 1)
        sfRenderWindow_drawRectangleShape(window, plane->hitbox, NULL);
}

void print_window(sfRenderWindow *window, sim_t *sim)
{
    plane_t *plane = sim->p_head;
    tower_t *tower = sim->t_head;

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sim->map_sprite, NULL);
    while (plane != NULL) {
        if (plane->time > sim->time / 1000.0)
            break;
        print_planes(plane, sim, window);
        plane = plane->next;
    }
    while (tower != NULL) {
        print_towers(tower, sim, window);
        tower = tower->next;
    }
    print_text(sim, window);
    sfRenderWindow_display(window);
}
