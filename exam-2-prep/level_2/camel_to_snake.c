/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:42:40 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 16:50:38 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void camelToSnake(char *str)
{
    while(*str)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            write(1, "_", 1);
            char letter = *str + 32;
            write(1, &letter, 1);
        }
        else
            write(1, str, 1);
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
        camelToSnake(argv[1]);
    return (0);
}