/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:03:10 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 15:17:30 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memset(void *str, int c, size_t n)
{
    unsigned char *s = str;
    int index;

    index = 0;
    while (index < (int)(n / sizeof(char)))
    {
        s[index] = c;
        index++;
    }
    return str;
}

/*
#include <stdio.h>
int main()
{
    char ft_str[] = "hello world";
    char str[] = "hello world";

    printf("before - ft_memset: %s\n", ft_str);
    ft_memset(ft_str, '.', 8 * sizeof(char));
    printf("after - ft_memset: %s\n", ft_str);
    printf("\n\n");
    printf("before - memset: %s\n", str);
    memset(str, '.', 8 * sizeof(char));
    printf("after - memset: %s\n", str);
}
*/
