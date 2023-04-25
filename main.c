/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:11:51 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 23:20:39 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char *av[])
{
	t_pipe pipe;
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
	pipe.input_fd = check_fd(open(av[1], O_RDONLY), __FILE__ , __LINE__);
	printf("%d", pipe.input_fd);
}
