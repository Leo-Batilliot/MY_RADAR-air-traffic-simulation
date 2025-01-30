/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** error_handling
*/
#include "../my.h"

int is_float(char *str)
{
    int len = 0;
    int coma = 0;

    for (; str[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        if ((str[i] > '9' || str[i] < '0') && str[i] != '.' &&
            str[i] != '\n') {
            return 84;
        }
        if (str[i] == '.')
            coma++;
        if (coma > 1)
            return 84;
    }
    return 0;
}

int tower_error(char **array)
{
    if (!array)
        return 84;
    for (int i = 1; i < 4; i++) {
        if (!array[i])
            return 84;
        if (is_float(array[i]) == 84)
            return 84;
    }
    if (array[4])
        return 84;
    return 0;
}

int plane_error(char **array)
{
    if (!array)
        return 84;
    for (int i = 1; i < 7; i++) {
        if (!array[i])
            return 84;
        if (is_float(array[i]) == 84)
            return 84;
    }
    if (array[7])
        return 84;
    return 0;
}
