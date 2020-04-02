/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_str_to_wordtab.c
*/

#include <stdlib.h>

static int separator(char c, char g)
{
    if (c != g && c != '\t')
        return (1);
    return (0);
}

static int count_words(char *str, char g)
{
    int word = 0;
    int i = 0;
    int nb_words = 0;

    while (str[i])
    {
        if (word == 0 && separator(str[i], g) == 1)
        {
            word = 1;
            nb_words = nb_words + 1;
        }
        if (word == 1 && separator(str[i], g) == 0)
            word = 0;
        i = i + 1;
    }
    return (nb_words);
}

static void dup_n_car(char *new_str, char *str, int begin, int end)
{
    int i = 0;

    while (begin <= end)
    {
        new_str[i] = str[begin];
        begin = begin + 1;
        i = i + 1;
    }
    new_str[i] = '\0';
}

static void save_words(char **tab, char *str, int nb_words, char g)
{
    int i = 0;
    int begin = 0;
    int word_cur = 0;

    while (word_cur < nb_words)
    {
        while (str[i] && separator(str[i], g) == 0)
            i = i + 1;
        begin = i;
        while (str[i] && separator(str[i], g) == 1)
            i = i + 1;
        tab[word_cur] = (char *)malloc(sizeof(char) * ((i - 1) - begin + 2));
        dup_n_car(tab[word_cur], str, begin, i - 1);
        i = i + 1;
        word_cur = word_cur + 1;
    }
}

char **my_str_to_wordtab(char *str, char g)
{
    int nb_words = count_words(str, g);
    char **tab = malloc(sizeof(char *) * (nb_words + 1));

    nb_words = count_words(str, g);
    save_words(tab, str, nb_words, g);
    tab[nb_words] = NULL;
    return (tab);
}