/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:23:41 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 18:40:45 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

int hidenp(char *hidden, char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] && hidden[j])
    {
        if (str[i] == hidden[j])
            j++;
        i++;
    }
    printf("hidden: %s\n", hidden);
    printf("str: %s\n", str);
    return (hidden[j] == '\0');
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        if (hidenp(argv[1], argv[2]))
            write(1, "1\n", 2);
        else
            write(1, "0\n", 2);
    }
    return (0);
}