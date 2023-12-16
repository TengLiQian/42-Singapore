/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:50:48 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 17:00:57 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_found(char a, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (a == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (ft_found(argv[1][i], argv[2]) != 0)
				counter++;
			i++;
		}
		if (counter == i)
		{
			i = 0;
			while (argv[1][i] != '\0')
				write(1, &argv[1][i++], 1);
			write(1, "\0", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
