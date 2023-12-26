/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:42:19 by lteng             #+#    #+#             */
/*   Updated: 2023/12/26 16:51:25 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	word_count(char *str)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			words++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}
	}
	return (words);
}

int	char_count(char *str)
{
	int	chars;
	int	words;
	int	i;

	chars = 0;
	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			chars++;
		i++;
	}
	return (chars);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i, j, k;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (word_count(str)) + 1);
	if (!tab)
		return (NULL);
	while (str[i])
	{
		k = 0;
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			tab[j] = malloc(sizeof(char) * char_count(str + i) + 1);
			if (!tab[j])
				return (NULL);
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
/*
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("Hello this is my World");
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}*/
