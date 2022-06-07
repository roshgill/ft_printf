/*                                                        :::      ::::::::   */
/*      libft.h                                      	 :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:43:57 by rosgill           #+#    #+#             */
/*   Updated: 2021/11/10 15:59:51 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A header file is a file with extension .h which contains C function declarations 
and macro definitions to be shared between several source files. There are two types 
of header files: The files that the programmer writes and the files that comes with your compiler. */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int	ft_atoi(char *str);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
void *ft_lstadd(void *head, void *data);
void *ft_lstlast(void *head);
void *ft_lstnew(void *data);
int ft_lstsize(void *head);
void *ft_memcpy(void *dest, const void *src, int len);
void ft_memdel(void **memory);
void *ft_memset(void *a, int c, int len);
void ft_putchar(int c);
void ft_putstr(char *str);
void ft_split(char *str1, char c);
char *ft_strchr(char *str, int c);
int  ft_strcmp(char *s1, char *s2);
char *ft_strcpy(char *s1, char *s2);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);
char *ft_strnstr(char *str, char *needle, int c);
void ft_swap(int *a, int *b);
int ft_tolower(int c);
int ft_toupper(int c);

#endif