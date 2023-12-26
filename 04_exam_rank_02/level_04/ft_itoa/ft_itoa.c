/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:18:48 by lteng             #+#    #+#             */
/*   Updated: 2023/12/26 11:48:12 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	long		temp;
	char		*result;

	temp = n;
	len = ft_count(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		temp *= -1;
	while (len > 0)
	{
		result[len - 1] = temp % 10 + '0';
		temp /= 10;
		len--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
/*
int	main(void)
{
	char	*result;

	result = ft_itoa(-12324242);
	printf("%s", result);
	free(result);
	return (0);
}*/
