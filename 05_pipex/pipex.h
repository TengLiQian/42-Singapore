/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:11:27 by lteng             #+#    #+#             */
/*   Updated: 2024/01/05 16:58:11 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

// for free
# include <stdlib.h>

// for access, close, read, write, execve, exit, fork, pipe
# include <unistd.h>

// for open
# include <fcntl.h>

// for perror
# include <stdio.h>

// for waitpid
# include <sys/wait.h>

#endif
