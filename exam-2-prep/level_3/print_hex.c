/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:44:33 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 18:58:40 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int num = 0;
    
    while (*str)
    {
        num *= 10;
        num += *str - '0';
        str++;
    }

    return (num);
}

void print_hex(int n)
{
    char *letters = "0123456789abcdef";
    if (n >= 16)
        print_hex(n / 16);
    write(1, &letters[n % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
}