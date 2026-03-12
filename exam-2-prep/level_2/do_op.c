/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:53:54 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 16:59:27 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void numbr(int nbr)
{
    char c;

    if (nbr >= 10)
        numbr(nbr / 10);
    c = (nbr % 10) + '0';
    write(1, &c, 1);
}

void do_op(int num1, char op, int num2)
{
    int result;

    result = 0;

    if (op == '*')
        result = num1 * num2;
    else if (op == '/')
        result = num1 / num2;
    else if (op == '%')
        result = num1 % num2;
    else if (op == '+')
        result = num1 + num2;
    else if (op == '-')
        result = num1 - num2;

    numbr(result);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int num1 = atoi(argv[1]);
    char op = *argv[2];
    int num2 = atoi(argv[3]);

    do_op(num1, op, num2);

    return (0);
}