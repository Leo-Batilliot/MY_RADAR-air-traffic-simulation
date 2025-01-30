/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** simulation_main
*/
#include "../my.h"

void update_paused_time(sim_t *sim, int state)
{
    sim->paused = state;
    if (state == 0)
        sim->paused_time += sfTime_asMilliseconds(
            sfClock_getElapsedTime(sim->paused_clock));
    if (state == 1)
        sfClock_restart(sim->paused_clock);
}

void update_time(sim_t *sim)
{
    sim->time = sfTime_asMilliseconds(
        sfClock_getElapsedTime(sim->clock)) - sim->paused_time;
}

void events(sfRenderWindow *window, sfEvent event, sim_t *sim)
{
    static int l_key_previous = 0;
    static int s_key_previous = 0;
    static int space_previous = 0;

    if (sim->p_head == NULL || !sim->p_head)
        sfRenderWindow_close(window);
    while (sfRenderWindow_pollEvent(window, &event))
        if (sfKeyboard_isKeyPressed(sfKeyEscape) || event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyL) && !l_key_previous)
            sim->hitbox_enabled = !sim->hitbox_enabled;
        if (sfKeyboard_isKeyPressed(sfKeyS) && !s_key_previous)
            sim->sprite_enabled = !sim->sprite_enabled;
        if (sfKeyboard_isKeyPressed(sfKeySpace) && !space_previous)
            update_paused_time(sim, (sim->paused + 1) % 2);
    l_key_previous = sfKeyboard_isKeyPressed(sfKeyL);
    s_key_previous = sfKeyboard_isKeyPressed(sfKeyS);
    space_previous = sfKeyboard_isKeyPressed(sfKeySpace);
}

void main_loop(sfRenderWindow *window, sim_t *sim)
{
    sfEvent event;
    int fps_count = 0;

    while (sfRenderWindow_isOpen(window)) {
        events(window, event, sim);
        update_time(sim);
        if (sim->time > 1000.0 / 60.0 * fps_count && sim->paused == 0) {
            move_planes(sim);
            in_tower_range(sim);
            collide_main(sim);
            dead_planes(sim);
            print_window(window, sim);
            fps_count++;
        }
    }
    sfRenderWindow_destroy(window);
    free_sim(sim);
}
