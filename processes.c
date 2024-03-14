/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:52:41 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/12 17:54:17 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(char **envp, char *av, t_pipe *pipex, int fd[])
{
	close(fd[1]);
	pipex->out_fd = open(av, O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (pipex->out_fd == -1)
		print_err_free("outfile error:", pipex, 1);
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		print_err_free("dup2 error ", pipex, 1);
	}
	if (dup2(pipex->out_fd, STDOUT_FILENO) < 0)
	{
		close(pipex->out_fd);
		print_err_free("dup2 error ", pipex, 0);
	}
	close(pipex->out_fd);
	if (execve(pipex->path2, pipex->cmd2, envp) == -1)
	{
		print_err_free("execve error", pipex, 1);
	}
	close(fd[0]);
}

void	child(char **envp, char *av, t_pipe *pipex, int fd[])
{
	close(fd[0]);
	pipex->in_fd = open(av, O_RDONLY);
	if (pipex->in_fd == -1)
		print_err_free("Infile error", pipex, 1);
	if (dup2(pipex->in_fd, STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		print_err_free("dup2 error ", pipex, 1);
	}
	close(pipex->in_fd);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		print_err_free("Outfile error: ", pipex, 1);
	if (execve(pipex->path1, pipex->cmd1, envp) == -1)
		print_err_free("execve error", pipex, 1);
}
