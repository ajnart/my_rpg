/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_hash_str.c
*/

unsigned long my_hash_str(const char *str)
{
    unsigned long hash = 5381;
    int c = 0;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}