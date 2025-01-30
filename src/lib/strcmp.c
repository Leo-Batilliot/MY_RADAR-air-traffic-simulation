/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** strcmp
*/
#include "../my.h"

int cmp(char *str1, char *str2)
{
    int len1 = 0;
    int len2 = 0;

    for (; str1[len1] != '\0'; len1++);
    for (; str2[len2] != '\0'; len2++);
    if (len1 != len2)
        return 84;
    for (int i = 0; i < len1; i++)
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    return 0;
}
