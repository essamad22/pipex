/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:07:54 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/28 17:54:26 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>

typedef struct s_pip {
	int		fd[2];
	int		input_fd;
	int		output_fd;
	char	***cmd;
	char	**path;
}	t_pip;

void	execution(t_pip pip, char **av, char **envr);
void	ft_free(char **p);
char	**end_slash(char **path);
int		check_err(int n_fd, char *file, int line, bool to_exit);
#endif
