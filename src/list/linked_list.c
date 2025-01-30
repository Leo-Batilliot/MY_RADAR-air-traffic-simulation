/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** init
*/
#include "../my.h"

plane_t *reverse_sim(plane_t *head)
{
    plane_t *prev = NULL;
    plane_t *current = head;
    plane_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int sim_sprites(sim_t *sim)
{
    sim->t_texture = sfTexture_createFromFile("src/assets/tower.png", NULL);
    sim->p_texture = sfTexture_createFromFile("src/assets/plane.png", NULL);
    sim->map_texture = sfTexture_createFromFile("src/assets/map.jpg", NULL);
    if (!sim->map_texture || !sim->p_texture || !sim->t_texture)
        return 84;
    sim->map_sprite = sfSprite_create();
    sfSprite_setTexture(sim->map_sprite, sim->map_texture, sfFalse);
    return 0;
}

int sim_text(sim_t *sim)
{
    sim->font = sfFont_createFromFile("src/assets/font.ttf");
    if (!sim->font)
        return 84;
    sim->hitbox_text = sfText_create();
    sim->sprite_text = sfText_create();
    sim->fps_text = sfText_create();
    sim->time_string = sfText_create();
    sfText_setFont(sim->hitbox_text, sim->font);
    sfText_setFont(sim->sprite_text, sim->font);
    sfText_setFont(sim->time_string, sim->font);
    sfText_setPosition(sim->hitbox_text, (sfVector2f) {1700, 0});
    sfText_setPosition(sim->sprite_text, (sfVector2f) {1718, 30});
    sfText_setPosition(sim->time_string, (sfVector2f) {0, 0});
    sfText_setFont(sim->fps_text, sim->font);
    sfText_setPosition(sim->fps_text, (sfVector2f) {0, 30});
    sfText_setString(sim->fps_text, "FPS :");
    return 0;
}

sim_t *init_sim(void)
{
    sim_t *sim = malloc(sizeof(sim_t));

    if (!sim)
        return NULL;
    if (sim_text(sim) == 84 || sim_sprites(sim) == 84)
        return NULL;
    sim->clock = sfClock_create();
    sim->paused_clock = sfClock_create();
    sim->fps = 0;
    sim->time = 0;
    sim->paused_time = 0;
    sim->hitbox_enabled = 1;
    sim->sprite_enabled = 1;
    sim->p_head = NULL;
    sim->t_head = NULL;
    sim->paused = 0;
    sim->dead = 0;
    return sim;
}
