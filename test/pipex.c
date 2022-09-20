/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:28:38 by iczarnie          #+#    #+#             */
/*   Updated: 2022/09/20 20:00:37 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *fd, char **argv, char **envp)
{
	int	inputfile;

	inputfile = open(argv[1], O_RDONLY);
	if (inputfile == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(inputfile, STDIN_FILENO);
	execute(argv[2], envp);
}

void	parent(int *fd, char **argv, char **envp)
{
	int	outputfile;

	outputfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outputfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outputfile, STDOUT_FILENO);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	id1;

	if (argc != 5)
		ft_putstr_fd ("Wrong number of arguments - not 5", 1);
	else
	{
		if (pipe(fd) == -1)
			error();
		id1 = fork();
		if (id1 == -1)
			error();
		if (id1 == 0)
		{
			close(fd[0]);
			child(fd, argv, envp);
		}
		else
		{
			close(fd[1]);
			waitpid(id1, NULL, 0);
			parent(fd, argv, envp);
		}
	}
	return (0);
}
