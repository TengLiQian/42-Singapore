/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:26:25 by lteng             #+#    #+#             */
/*   Updated: 2023/12/07 16:17:26 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
				argv[1][i] += 2 * ('M' - argv[1][i]) + 1;
			else if (argv[1][i] >= 'N' && argv[1][i] <= 'Z')
				argv[1][i] -= 2 * ('Z' - argv[1][i]) + 1;
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
				argv[1][i] += 2 * ('m' - argv[1][i]) + 1;
			else if (argv[1][i] >= 'n' && argv[1][i] <= 'z')
				argv[1][i] -= 2 * ('z' - argv[1][i]) + 1;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
