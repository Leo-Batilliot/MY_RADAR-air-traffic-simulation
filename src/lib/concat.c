/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** strcat
*/
#include "../my.h"

char *concat(char *str1, char *str2)
{
    int len1 = 0;
    int len2 = 0;
    char *res;
    int i = 0;

    for (; str1[len1] != '\0'; len1++);
    for (; str2[len2] != '\0'; len2++);
    res = malloc(sizeof(char) * (len1 + len2 + 1));
    res[len1 + len2] = '\0';
    for (; i < len1; i++)
        res[i] = str1[i];
    for (int y = 0; y < len2; y++)
        res[i + y] = str2[y];
    free(str2);
    return res;
}
