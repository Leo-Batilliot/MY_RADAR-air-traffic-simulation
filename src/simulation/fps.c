/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** fps
*/
#include "../my.h"

char *int_to_str(int nb)
{
        int i = 0;
    char buffer[64];
    char *res;

    for (; nb > 0; i++) {
        buffer[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    buffer[i] = '\0';
    res = malloc(i + 1);
    for (int j = 0; j < i; j++)
        res[j] = buffer[i - j - 1];
    res[i] = '\0';
    return res;
}

void fps_count(sim_t *sim)
{
    static int c = 0;
    char *str;

    if (sim->time > 500.0 * c) {
        str = concat("FPS : ", int_to_str(sim->fps * 2));
        sfText_setString(sim->fps_text, str);
        sim->fps = 0;
        free(str);
        c++;
    } else if (sim->fps < 30)
        sim->fps++;
    if (sim->fps >= 15 && sim->fps < 30)
        sim->fps++;
}
