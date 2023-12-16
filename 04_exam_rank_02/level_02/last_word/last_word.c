/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:49:45 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 12:17:48 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	nonspace_index;

	i = 0;
	nonspace_index = -1;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] != ' ')
				nonspace_index = i;
			i++;
		}
		if (nonspace_index != -1)
		{
			i = nonspace_index;
			while (argv[1][i - 1] != ' ')
				i--;
		}
		while (argv[1][i] != '\0')
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
