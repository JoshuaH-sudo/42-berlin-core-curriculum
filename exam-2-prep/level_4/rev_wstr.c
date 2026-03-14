/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:19:08 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/13 13:00:37 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *ft_strncpy(char *dest, char *src, int len)
{
    int i = 0;
    while(src[i] && i < len)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char **ft_split(char *str)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int wc = 0;

    printf("%s\n", str);
    
    while (str[i])
    {
        while(str[i] == ' ')
            i++;
        if (str[i])
            wc++;
        while(str[i] && str[i] != ' ')
            i++;
    }
    char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
    while (str[i])
    {
        while(str[i] == ' ')
            i++;
        j = i;
        while (str[i] && (str[i] != ' '))
			i++;
        if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
    }
    out[k] = NULL;
    return (out);
}


void rev_wstr(char *str)
{
    char **words = ft_split(str);
    int i = 0;
    while (words[i])
    {
        printf("%s\n", words[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    rev_wstr(argv[1]);
    return (0);
}