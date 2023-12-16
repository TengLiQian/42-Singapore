/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:41:55 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 10:48:43 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_occ(char a, char *str, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[pos] == str[pos - i - 1])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (str_occ(argv[1][i], argv[1], i) == 0)
			{
				j = 0;
				while (argv[2][j] != '\0')
				{
					if (argv[1][i] == argv[2][j])
						write(1, &argv[1][i], 1);
					j++;
				}
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
