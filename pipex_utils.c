/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:12:22 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 23:03:41 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_fd(int n_fd, char *file, int line)
{
	if (n_fd == -1)
	{
		ft_printf("ERROR: (%s): %d %s\n", file, line, strerror(errno));
		exit(1);
	}
	return (n_fd);
}
