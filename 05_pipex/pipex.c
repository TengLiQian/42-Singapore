/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:19 by lteng             #+#    #+#             */
/*   Updated: 2024/01/06 11:56:58 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

char	*ft_path(char *cmd)
{

}

int	child_process(int pipefd[], char *cmd1, char *file1, char *envp[])
{
	int		fd;
	char	*cmdpath;
	char	**cmd;

	close(pipefd[0]);
	cmdpath = ft_path(cmd1);
	cmd = ft_split(cmd1, ' ');
	fd = open(file1, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening file child");
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error("Error redirecting standard output\n");
	if (execve(cmdpath, cmd, envp) == -1)
		ft_error("Error executing command\n");
	ft_error("execve");
	exit(0);
}

int	parent_process(int pipefd[], char *cmd2, char *file2, char *envp[])
{
	int		fd;
	char	*cmdpath;
	char	**cmd;

	close(pipefd[1]);
	cmdpath = ft_path(cmd2);
	cmd = ft_split(cmd2, ' ');
	fd = open(file2, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		ft_error("Error opening file parent");
	printf("Parent: %i\n", fd);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_error("Error redirecting standard input\n");
	if (execve(cmdpath, cmd, envp) == -1)
		ft_error("Error executing command\n");
	exit(0);
}

int	main(int argc, char *argv[], char *envp[])
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
		child_process(pipefd, argv[2], argv[1], envp);
	else
	{
		wait(NULL);
		parent_process(pipefd, argv[3], argv[4], envp);
	}
	return (0);
}
