/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Returns a number sent to the function as a string
*/

int add_nb(int act_nb, int new_nb, int *h_ovf)
{
    if (act_nb * 10 + new_nb < act_nb) {
        *h_ovf = 2;
        return (0);
    }
    act_nb = act_nb * 10 + new_nb;
    return (act_nb);
}

int my_atoi(char const *str)
{
    int final_nb = 0;
    int has_nb = 0;
    int is_neg = 1;
    int i = 0;
    int *has_ovf = &is_neg;

    while (str[i] != '\0' || has_nb != 1) {
        while (str[i] >= '0' && str[i] <= '9' && is_neg != 2) {
            final_nb = add_nb(final_nb, str[i] - '0', has_ovf);
            i++;
            has_nb = 1;
        }
        if (has_nb == 1)
            return (final_nb * is_neg);
        is_neg = 1;
        if (str[i] == '-')
            is_neg = -1;
        i++;
    }
    return (0);
}