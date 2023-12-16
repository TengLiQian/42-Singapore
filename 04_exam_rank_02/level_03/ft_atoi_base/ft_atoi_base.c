/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:13:21 by lteng             #+#    #+#             */
/*   Updated: 2023/12/16 16:50:24 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 1;
	result = 0;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result += (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'z')
			result += (str[i] - 'a' + 10);
		i++;
	}
	return (n * result);
}
/*
int	main(void)
{
	const char	*str1;

	str1 = "12A";
	printf("%s\n%i", str1, ft_atoi_base(str1, 16));
	return (0);
}*/
