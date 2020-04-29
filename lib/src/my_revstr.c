/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_revstr.c
*/

char *my_revstr(char *str)
{
    int i = 0;
    int end = 0;
    int x = 0;

    while (str[end] != '\0')
        end += 1;
    end -= 1;
    while (i < end)
    {
        x = str[i];
        str[i] = str[end];
        str[end] = x;
        i += 1;
        end -= 1;
    }
    return (str);
}