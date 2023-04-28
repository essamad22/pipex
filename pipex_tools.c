/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:12:22 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/28 17:17:20 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

char	**end_slash(char **path)
{
	char	**tmp;
	int		len;

	if (path == NULL)
		return (NULL);
	len = 0;
	while (path[len])
		len++;
	tmp = (char **)ft_calloc(len + 1, sizeof(char *));
	len = -1;
	while (path[++len])
		tmp[len] = ft_strjoin(path[len], "/");
	ft_free(path);
	return(tmp);
}
int	check_err(int n_fd, char *file, int line, bool to_exit)
{
	if (n_fd == -1)
	{
		ft_printf("ERROR: (%s): %d %s\n", file, line, strerror(errno));
		if (to_exit == true)
			exit(1);
	}
	return (n_fd);
}
