/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** my_strcmp.c
*/

int my_strlen(char *str);

int my_strcmp(char *s1, char *s2)
{
    int match = 0;

    while ((s1[match] == s2[match]) && (s1[match] && s2[match]))
        match++;
    return ((match == my_strlen(s1)) && (match == my_strlen(s2)));
}

int my_strncmp(char *s1, char *s2, int n)
{
    int match = 0;

    while ((s1[match] == s2[match]) && (s1[match] && s2[match]) && match < n)
        match++;
    return (match == n);
}

int str_contains(char *str, char c)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}
