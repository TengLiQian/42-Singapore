/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:57:21 by lteng             #+#    #+#             */
/*   Updated: 2023/12/22 15:16:15 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_printhex(int nbr)
{
	char	*str;

	str = "123456789abcdef";
	if (nbr > 15)
	{
		ft_printhex(nbr / 16);
		ft_printhex(nbr % 16);
	}
	if (nbr <= 15)
		write(1, &str[nbr - 1], 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_printhex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
