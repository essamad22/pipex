/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:11:51 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/28 00:45:47 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_path(char **path, char *cmd)
{
	char	*tmp;
	int		i;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, X_OK) != -1)
			return (tmp);
		free(tmp);
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

char	**get_path(char ***cmd, char **envr)
{
	char	**paths;
	char	**tmp_2d;
	char	*tmp;
	int		i;

	paths = (char **)ft_calloc(sizeof(char *), 2);
	i = -1;
	while (envr[++i])
		if (ft_strncmp("PATH", envr[i], 4) == 0)
			tmp = envr[i] + 5;
	tmp_2d = ft_split(tmp, ':');
	tmp_2d = end_slash(tmp_2d);
	i = -1;
	while (++i < 2)
		paths[i] = cmd_path(tmp_2d, cmd[i][0]);
	while (--i > -1)
	{
		if (paths[i] == NULL)
			exit(127);	
	}
	return (paths);
}

void	get_cmd(t_pip *pip, char **av, char **envr)
{
	int i;

	i = -1;
	pip->cmd = (char***)ft_calloc(sizeof(char**), 2);
	while (++i < 2)
		pip->cmd[i] = ft_split(av[i], ' ');
	pip->path = get_path(pip->cmd, envr);
	while (pip->cmd[--i])
	{
		if (ft_strlen(pip->cmd[i][0]) == 0)
			exit(127);
	}
}

int main(int ac, char *av[], char **envr)
{
	t_pip pip;

	if (ac < 5)
	{
		ft_putstr_fd("not enough argument :\n", 2);
		ft_putstr_fd("\tUSAGE\t: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (2);
	}
	if (ac > 5)
	{
		ft_putstr_fd("too many arguments :\n", 2);
		ft_putstr_fd("\tUSAGE\t: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (2);
	}
	pip.input_fd = check_err(open(av[1], O_RDONLY), __FILE__ , __LINE__);
	get_cmd(&pip, av + 2, envr);
	execution(pip, av, envr);
}
