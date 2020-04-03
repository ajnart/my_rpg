/*
** EPITECH PROJECT, 2019
** lib.h
** File description:
** lib.h
*/

#include <stdarg.h>

#ifndef _MY_DEF_
#define _MY_DEF_

/* src/functs_1.c */
void funct_int(va_list arg);
void funct_cha(va_list arg);
void funct_str(va_list arg);
void funct_octa(va_list arg);
void funct_str_maj(va_list arg);
/* src/functs_2.c */
void funct_per(va_list arg);
void funct_bin(va_list arg);
void funct_hexa(va_list arg);
void funct_hexa_maj(va_list arg);
void funct_ptr(va_list arg);
/* src/functs_3.c */
void funct_unsign_int(va_list arg);
void disp_nbr_unsigned(unsigned int nb);
int my_put_nbr_unsigned(unsigned int nb);
char *my_strcat(char *str1, char *str2);
int my_strlen(char *str);
/* src/get_next_line.c */
char compute(int fd);
char *my_strdup_alloc(char *str, int lenght);
char *get_next_line(int fd);
/* src/get_next_word.c */
char *get_next_word(int fd);
/* src/my_getnbr.c */
int add_nb(int act_nb, int new_nb, int *h_ovf);
int my_getnbr(char const *str);
/* src/my_printf.c */
int check_flag(char c);
void fct_pointers_create(va_list fp, const char *str, int i);
int my_printf(const char *str, ...);
/* src/my_putchar.c */
void my_putchar(char c);
int my_putstr(char const *str);
void disp_nbr(int nb);
int my_put_nbr(int nb);
/* src/my_putnbr_base.c */
int shownbr_base(int nbr, int length, char const *base);
int my_putnbr_base(int nbr, char const *base);
int shownbr_base_unsigned(unsigned long nbr, int length, char const *base);
int my_putnbr_base_unsigned(unsigned long nbr, char const *base);
/* lib/src/str_str.c */
void str_append(char **src, char const *add);
int my_str_isalpha(char *str);
/* src/my_str_to_wordtab.c */
char **my_str_to_wordtab(char *str, char g);
/* src/str_str.c */
int my_str_isalpha(char *str);

char *my_strncpy(char *dest, char *src, int n);
char *my_strcpy(char *dest, char *src);
char *my_strndup(char *str, int n);
char *my_strdup(char *str);
/* lib/src/my_strcmp.c */
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *sub);
int str_contains(char const *str, char c);

typedef void (*print_compute_t)(va_list arg);

#endif