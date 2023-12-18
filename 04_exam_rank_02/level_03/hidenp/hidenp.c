/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:33:24 by lteng             #+#    #+#             */
/*   Updated: 2023/12/18 15:47:53 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_char_found(char a, char *str, int pos)
{
	while (str[pos] != '\0')
	{
		if (a == str[pos])
			return (1);
		pos++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	count;
	int	pos;

	i = 0;
	count = 0;
	pos = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (ft_char_found(argv[1][i], argv[2], pos) == 1)
				count += 1;
			i += 1;
		}
		if (count == ft_strlen(argv[1]))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
