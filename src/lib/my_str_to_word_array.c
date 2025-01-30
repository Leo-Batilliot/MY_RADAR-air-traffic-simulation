/*
** EPITECH PROJECT, 2024
** str to word array
** File description:
** task 04
*/
#include "../my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str != NULL && str[i] != '\0'; i++);
    return i;
}

int word_count(char *str)
{
    int count = 1;
    int start = 0;

    while (!(str[start] != ' ') && str[start] != '\0')
        start++;
    for (int i = start; str[i + 1] != '\0'; i++) {
        if (!(str[i] != ' ') && (str[i + 1] != ' '))
            count++;
    }
    return count + 1;
}

char *my_str_to_word(char *str)
{
    long len = 0;
    char *word;

    for (long i = 0; str[i] != '\0' && str[i] != ' '; i++)
        len++;
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    for (int i = 0; i < len && str[i] != '\0'; i++)
        word[i] = str[i];
    word[len] = '\0';
    return word;
}

int char_at_first_index(char **result, int y, char *str)
{
    char *word = my_str_to_word(str);

    result[y] = word;
    return 1;
}

char **my_str_to_word_array(char *str)
{
    char **result = malloc(sizeof(char *) * word_count(str));
    long i = 0;
    int y = 0;
    long int len = my_strlen(str);

    if (!result)
        return NULL;
    if ((str[i] != ' ')) {
        i += char_at_first_index(result, y, str);
        y++;
    }
    for (i; str[i + 1] != '\0'; i++) {
        if (!(str[i] != ' ') && (str[i + 1] != ' ')) {
            result[y] = my_str_to_word(&str[i + 1]);
            y++;
        }
    }
    result[y] = NULL;
    return result;
}
