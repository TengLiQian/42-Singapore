/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:09:30 by lteng             #+#    #+#             */
/*   Updated: 2023/10/14 13:35:51 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_addstorage(char *storage, int bytes_read, char *buffer)
{
	int		i;
	int		j;
	int		slength;
	char	*temp;

	i = 0;
	j = 0;
	if (!storage)
		slength = 0;
	else
		slength = ft_strlen(storage);
	temp = malloc(sizeof(char) * (bytes_read + slength + 1));
	if (!temp)
		return (NULL);
	while (storage && storage[i] != '\0')
	{
		temp[i] = storage[i];
		i++;
	}
	while (j < bytes_read)
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free (storage);
	return (temp);
}

char	*ft_read(char *storage, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
			free (storage);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		storage = ft_addstorage(storage, bytes_read, buffer);
		if (ft_strnewline(storage) == 1)
			break ;
	}
	free (buffer);
	return (storage);
}

char	*ft_result(char *storage)
{
	char	*result;
	int		i;
	int		new_line;

	i = 0;
	new_line = ft_linepos(storage);
	if (new_line == 0)
		return (NULL);
	result = malloc(sizeof(char) * new_line + 1);
	if (!result)
		return (NULL);
	while (i < new_line)
	{
		result[i] = storage[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_new(char *storage, char *result)
{
	char	*temp;
	int		i;
	int		rlength;
	int		slength;

	rlength = ft_strlen(result);
	slength = ft_strlen(storage);
	temp = malloc(sizeof(char) * (slength - rlength + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (storage[rlength + i] != '\0')
	{
		temp[i] = storage[rlength + i];
		i++;
	}
	temp[i] = '\0';
	free (storage);
	if (temp[0] == '\0')
	{
		free (temp);
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*result;

	if (fd < 0 || fd > 1024)
		return (NULL);
	storage[fd] = ft_read(storage[fd], fd);
	if (!storage[fd])
		return (NULL);
	result = ft_result(storage[fd]);
	storage[fd] = ft_new(storage[fd], result);
	return (result);
}
/*
int	main(void)
{
	int	fd;
	int	i;
	char	*a;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		a = get_next_line(fd);
		printf("%s", a);
		free (a);
		i++;
	}
	return (0);
}
*/
