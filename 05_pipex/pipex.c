/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:19 by lteng             #+#    #+#             */
/*   Updated: 2024/01/04 15:36:13 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, char	*input_output)
{
	int	fd;

	if (input_output == "input")
		fd = open(file, O_RDONLY, 0777);
	if (input_output == "output")
		fd = open(file, O_WRONLY | OTRUNC | O_CREAT, 0777);
	return (fd);
}

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
	int		fd;
	char	*cmdpath;

	cmdpath = ft_findpath(argv[2]);
	fd = open_file(argv[1], "input");
	dup2(fd, 0);
	close(pipefd[0]);
	if (dup2(pipefd[1], STDIN_FILENO) == -1)
		ft_error("Error redirecting standard input\n");
	execve(cmdpath, argv[2], NULL);
	close(pipefd[1]);
	exit(EXIT_SUCCESS);
}

int	parent_process(int pipefd[], char *argv[])
{
	int		fd;
	char	*cmdpath;

	cmdpath = ft_findpath(argv[3]);
	fd = open_file(argv[4], "output");
	dup2(fd, 1);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDOUT_FILENO) == -1)
		ft_error("Error redirecting standard output\n");
	execve(cmdpath, argv[3], NULL);
	close(pipefd[0]);
	exit(EXIT_SUCCESS);
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
	else
		parent_process(pipefd, argv);
	return (0);
}
