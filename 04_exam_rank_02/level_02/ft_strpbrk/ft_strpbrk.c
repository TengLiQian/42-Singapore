/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:49:22 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 10:42:45 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	while (*s1)
	{
		i = 0;
		while (s2[i] != '\0')
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return ((char *)s1);
}
/*
int	main(void)
{
	printf("%s", ft_strpbrk("Hello World", "aeiou"));
	return (0);
}*/
