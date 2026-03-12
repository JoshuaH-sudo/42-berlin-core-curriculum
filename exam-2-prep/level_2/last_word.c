/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:14:54 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 17:39:01 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

void lastWord(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    i--;
    while (str[i] == ' ')
        i--;
    while (str[i - 1] != ' ' && i > 0)
        i--;
    while (str[i] && str[i] != ' ')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
        lastWord(argv[1]);
    return (0);
}