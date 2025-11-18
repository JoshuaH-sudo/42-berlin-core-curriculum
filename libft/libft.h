/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:05 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/18 19:17:15 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

#ifndef LIBFT_H

#define LIBFT_H

int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
void *ft_memset(void *str, int c, size_t n);
int ft_strlen(char *str);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strnstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
int ft_atoi(char *str);
char *ft_tolower(char *str);
char *ft_toupper(char *str);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
  
#endif // LIBFT_H