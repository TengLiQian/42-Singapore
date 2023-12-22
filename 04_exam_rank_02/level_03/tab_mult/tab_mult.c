/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:56:25 by lteng             #+#    #+#             */
/*   Updated: 2023/12/22 17:35:33 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	result;

	result = 0;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr <= 9)
	{
		result = '0' + nbr;
		write(1, &result, 1);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_multiply(int a, int b)
{
	return (a * b);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	a;

	i = 1;
	a = 0;
	if (argc == 2 && ft_atoi(argv[1]) <= 238609294 && ft_atoi(argv[1]) >= 0)
	{
		while (i < 10)
		{
			a = i + '0';
			write(1, &a, 1);
			write(1, " x 9 = ", 7);
			ft_putnbr(ft_multiply(i, ft_atoi(argv[1])));
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
