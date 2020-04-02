/*
** EPITECH PROJECT, 2019
** My_StrStr
** File description:
** File mystr.
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int length = my_strlen(to_find);
    int i = 0;
    int k = 0;
    int tmp = 0;
    int compute = 0;

    while (str[i] != '\0') {
        tmp = i;
        while ((str[i] == to_find[k]) && (to_find[k] != '\0')) {
            i += 1;
            k += 1;
        }
        compute = (i - k);
        if (length == k)
            return (str + compute);
        i = tmp + 1;
        k = 0;
    }
    return (NULL);
}