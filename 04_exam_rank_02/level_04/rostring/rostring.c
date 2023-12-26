/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:54:07 by lteng             #+#    #+#             */
/*   Updated: 2023/12/26 17:01:53 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	word_count(char *str)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			words++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
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
		if (str[i] != ' ' && str[i] != '\t')
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
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			tab[j] = malloc(sizeof(char) * char_count(str + i) + 1);
			if (!tab[j])
				return (NULL);
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	**words;
	int		i;

	i = 0;
	if (argc == 2)
	{
		words = ft_split(argv[1]);
		while (words[i + 1])
		{
			ft_putstr(words[i + 1]);
			write(1, " ", 1);
			i++;
		}
		ft_putstr(words[0]);
	}
	write(1, "\n", 1);
	return (0);
}
