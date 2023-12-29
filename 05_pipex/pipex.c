/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:19 by lteng             #+#    #+#             */
/*   Updated: 2023/12/29 20:36:55 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


https://www.rozmichelle.com/pipes-forks-dups/

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int	pipefd[2];
	pid_t	p_id;

	if (argc == 5)
	{
		pipe(pipefd);
		if (pipe(pipefd) == -1)
			return (perror("Pipe"));
		p_id = fork();
		if (p_id < 0)
			return (perror("Fork: "));
		if (p_id == 0)
			// This is child process
		else
			// This is parent process
	}
	return (0);
}
