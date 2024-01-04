/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:19 by lteng             #+#    #+#             */
/*   Updated: 2024/01/04 17:22:48 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

const extern char	**environ;

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char	*ft_path(char *cmd)
{
	char	**path;
	char	*testpath;
	int		i;

	path = NULL;
	i = 0;
	if (!*environ || !environ)
		return (NULL);
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
			path = ft_split(environ[i] + 5, ':');
		i++;
	}
	i = 0;
	while (path[i])
	{
		testpath = ft_strjoin(ft_strjoin(path[i], "/"), cmd);
		if (access(testpath, F_OK) != 0)
		{
			free(path);
			return (testpath);
		}
		free(testpath);
		i++;
	}
	free(path);
	return (NULL);
}

int	open_file(char *file, int input_output)
{
	int	fd;

	if (input_output == 0)
		fd = open(file, O_RDONLY, 0777);
	else if (input_output == 1)
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	else
		fd = -1;
	if (fd == -1)
		ft_error("Error opening file");
	return (fd);
}

int	child_process(int pipefd[], char *argv[])
{
	int		fd;
	char	*cmdpath;

	cmdpath = ft_path(argv[2]);
	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	close(pipefd[0]);
	if (dup2(pipefd[1], STDIN_FILENO) == -1)
		ft_error("Error redirecting standard input\n");
	execve(get_path(argv[2]), argv[2], NULL);
	close(pipefd[1]);
	exit(EXIT_SUCCESS);
}

int	parent_process(int pipefd[], char *argv[])
{
	int		fd;
	char	*cmdpath;

	cmdpath = ft_path(argv[3]);
	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDOUT_FILENO) == -1)
		ft_error("Error redirecting standard output\n");
	execve(get_path(argv[3]), argv[3], NULL);
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
