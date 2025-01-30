/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** init_spacial_cells
*/
#include "../my.h"

int get_cell_index(int pos, int grid_size)
{
    int index = pos / 40;

    if (index < 0)
        return 0;
    if (index >= grid_size)
        return grid_size - 1;
    return index;
}

int collide_main(sim_t *sim)
{
    plane_t *grid[1080 / 40][1920 / 40] = {NULL};
    plane_t *current = sim->p_head;
    int grid_x;
    int grid_y;

    while (current && current->time < sim->time * 1000.0) {
        if (current->safe == 0 && current->dead == 0) {
            grid_x = get_cell_index(current->c_pos.x, 1920 / 40);
            grid_y = get_cell_index(current->c_pos.y, 1080 / 40);
            current->next_collide = grid[grid_y][grid_x];
            grid[grid_y][grid_x] = current;
        }
        current = current->next;
    }
    for (int y = 0; y < 1080 / 40; y++)
        for (int x = 0; x < 1920 / 40; x++)
            is_cell_empty(grid, x, y, sim);
    return 0;
}
