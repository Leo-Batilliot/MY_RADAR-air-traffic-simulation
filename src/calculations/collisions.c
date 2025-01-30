/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** collisions
*/
#include "../my.h"

void planes_collide(plane_t *p1, plane_t *p2, sim_t *sim)
{
    float dx;
    float dy;
    float distance;

    if (p1 == p2 || p1->dead || p2->dead)
        return;
    dx = p1->c_pos.x - p2->c_pos.x;
    dy = p1->c_pos.y - p2->c_pos.y;
    distance = sqrt(dx * dx + dy * dy);
    if (distance < 20) {
        p1->dead = 1;
        p2->dead = 1;
        sim->dead += 2;
    }
    return;
}

void compare_two_cells(plane_t *grid[1080 / 40][1920 / 40],
    int i, int j, sim_t *sim)
{
    plane_t *p1;
    plane_t *p2;

    if (i < 0 || i >= 1080 / 40 || j < 0 || j >= 1920 / 40)
        return;
    p1 = grid[i][j];
    while (p1) {
        p2 = p1->next_collide;
        while (p2) {
            planes_collide(p1, p2, sim);
            p2 = p2->next_collide;
        }
        p1 = p1->next_collide;
    }
}

void surrounding_cells(plane_t *grid[1080 / 40][1920 / 40],
    int x, int y, sim_t *sim)
{
    for (int i = y - 1; i <= y + 1; i++)
        for (int j = x - 1; j <= x + 1; j++)
            compare_two_cells(grid, i, j, sim);
}

int is_cell_empty(plane_t *grid[1080 / 40][1920 / 40],
    int x, int y, sim_t *sim)
{
    if (!grid || !grid[y] || !grid[y][x])
        return 1;
    surrounding_cells(grid, x, y, sim);
    return 0;
}
