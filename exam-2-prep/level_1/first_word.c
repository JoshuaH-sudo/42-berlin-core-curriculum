/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:56:18 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 16:10:26 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    first_word(char *input){
    int i;

    i = 0;
    while (input[i] == ' ' || input[i] == '\t')
        i++;
    while (input[i] != ' ' && input[i])
    {
        write(1, &input[i], 1);
        i++;
    }
}

int main(int argc, char **argv){
	if (argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);
    return (0);
}