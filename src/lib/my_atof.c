/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** my_atof
*/
#include "../my.h"

int get_dot(float nb)
{
    int nbint = (int) nb;
    int count = 0;

    while (nbint > 0) {
        nbint = nbint / 10;
        count++;
    }
    return count;
}

char *float_to_text(float nb)
{
    int dot = get_dot(nb);
    char *buffer = malloc(sizeof(char) * 64);
    char temp[64];
    int count = 0;
    int j = 0;

    nb = (int)(roundf(nb * 1000));
    for (;(int) nb != 0; j++) {
        temp[j] = ((int) nb % 10) + '0';
        nb /= 10;
    }
    for (int k = 0; k < j; k++) {
        if (k == dot) {
            buffer[k] = '.';
            count++;
        }
        buffer[k + count] = temp[j - k - 1];
    }
    buffer[j] = '\0';
    return buffer;
}

void atof_loop(char str, int *decimal_point, float *factor, float *result)
{
    if (str == '.')
        *decimal_point = 1;
    if (str >= '0' && str <= '9') {
        if (*decimal_point) {
            *factor /= 10.0f;
            *result += (str - '0') * *factor;
        }
        if (!*decimal_point)
            *result = *result * 10.0f + (str - '0');
    }
}

float my_atof(const char *str)
{
    float result = 0.0f;
    float factor = 1.0f;
    int decimal_point = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        atof_loop(str[i], &decimal_point, &factor, &result);
    }
    return result;
}
