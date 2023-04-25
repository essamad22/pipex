/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:07:54 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 23:18:40 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct	s_pipe {
	int	fd[2];
	int input_fd;
	int	output_fd;
}	t_pipe;
int	check_fd(int n_fd, char *file, int line);
#endif
