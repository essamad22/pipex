/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:12:22 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/27 16:28:17 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **p)
{
	while (*p)
		free(p++);
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
	return(tmp);
}
int	check_err(int n_fd, char *file, int line)
{
	if (n_fd == -1)
	{
		ft_printf("ERROR: (%s): %d %s\n", file, line, strerror(errno));
		exit(1);
	}
	return (n_fd);
}
