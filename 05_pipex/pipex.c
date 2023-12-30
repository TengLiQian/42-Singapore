/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:19 by lteng             #+#    #+#             */
/*   Updated: 2023/12/30 17:12:24 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_validity(char *cmd)
{

}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	child_process(int pipefd[], char *argv[])
{
	close(pipefd[0]); //UNUSED
	if (dup2(pipefd[1], STDIN_FILENO) == -1)
		ft_error("Error redirecting standard input\n");

	execve(cmd1);

	//CODE

	close(pipefd[1]);
}

int	parent_process(int pipefd[], char *argv[])
{
	close(pipefd[1]); //UNUSED

	//CODE


	close(pipefd[0]);
}

int	main(int argc, char *argv[])
{
	int		pipefd[2];
	pid_t	process_id;

	if (argc != 5)
		ft_error("Expecting ./pipex infile cmd cmd outfile\n");
	if (pipe(pipefd) == -1)
		ft_error("Pipe\n");
	process_id = fork();
	if (process_id == -1)
		ft_error("Fork\n");
	if (process_id == 0)
		child_process(pipefd, argv);
	parent_process(pipefd, argv);
	return (0);
}
