/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:00:26 by iczarnie          #+#    #+#             */
/*   Updated: 2022/09/20 20:00:26 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

void	free_things(char **command_plus_arguments, char **all_paths)
{
	int	i;

	i = -1;
	while (all_paths[++i])
		free (all_paths[i]);
	free (all_paths);
	i = -1;
	while (command_plus_arguments[++i])
		free (command_plus_arguments[i]);
	free (command_plus_arguments);
}

void	path_iteration(char **command_plus_arguments,
char **all_paths, char **envp)
{
	int		i;
	char	*path;
	char	*part_path;

	i = 0;
	while (all_paths[i])
	{
		part_path = ft_strjoin (all_paths[i], "/");
		path = ft_strjoin (part_path, command_plus_arguments[0]);
		free(part_path);
		if (access (path, F_OK) == 0)
		{
			if (execve(path, command_plus_arguments, envp) == -1)
				error();
		}
		free(path);
		i++;
	}
}

void	execute(char *argv, char **envp)
{
	char	**command_plus_arguments;
	int		i;
	char	**all_paths;

	command_plus_arguments = ft_split(argv, ' ');
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	path_iteration(command_plus_arguments, all_paths, envp);
	free_things(command_plus_arguments, all_paths);
	error();
}
