/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:08:54 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/28 00:40:57 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	sec_proc(t_pip pip, char **av, char **envr)
{
	close(pip.fd[1]);
	pip.output_fd = check_err(open(av[4], 2 | O_CREAT, 0644), __FILE__, __LINE__);
	dup2(pip.fd[0], STDIN_FILENO);
	close(pip.fd[0]);
	dup2(pip.output_fd, STDOUT_FILENO);
	close(pip.output_fd);
	execve(pip.path[1], pip.cmd[1], envr);
}

void	first_proc(t_pip pip, char **envr)
{
	close(pip.fd[0]);
	dup2(pip.input_fd, STDIN_FILENO);
	close(pip.input_fd);
	dup2(pip.fd[1], STDOUT_FILENO);
	close(pip.fd[1]);
	execve(pip.path[0], pip.cmd[0], envr);
}

void	execution(t_pip pip, char **av, char **envr)
{
	pid_t	pid;
	pid_t	pid2;
	int		st;

	check_err(pipe(pip.fd), __FILE__, __LINE__);
	pid = check_err(fork(), __FILE__, __LINE__);
	if (pid == 0)
	{
		first_proc(pip, envr);
	}
	pid2 = check_err(fork(), __FILE__, __LINE__);
	if (pid2 == 0)
		sec_proc(pip, av, envr);
	close(pip.fd[0]);
	close(pip.fd[1]);
	waitpid(pid, &st, 0);
	waitpid(pid2, &st, 0);
	exit(st);
}