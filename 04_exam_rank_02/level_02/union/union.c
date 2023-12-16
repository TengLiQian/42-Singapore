/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:27:04 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 17:01:12 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_double(char *str, int pos)
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

int	ft_double2(char a, char *str2)
{
	int	i;

	i = 0;
	while (str2[i] != '\0')
	{
		if (str2[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (ft_double(argv[1], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			if (ft_double(argv[2], i) == 0
				&& ft_double2(argv[2][i], argv[1]) == 0)
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
