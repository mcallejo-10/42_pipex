/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:52:41 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/28 09:53:46 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **envp, char **av, t_pipe *pipex, int fd[])
{
	ft_printf("entra en el child\n");
	close(fd[0]);
	pipex->in_fd = open(av[1], O_RDONLY);
	if (pipex->in_fd == -1)
		print_err_free("No lee el in flie\n", pipex);
	if (dup2(pipex->in_fd, STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		print_err_free("dup2 fd", pipex);
	}
	close(fd[1]);
	if (execve(pipex->path1, pipex->cmd1, envp) == -1)
		print_err_free("error en execve", pipex);
}

void	parent(char **envp, char **av, t_pipe *pipex, int fd[])
{
	ft_printf("entra en el parent\n");
	
	close(fd[1]);
	pipex->out_fd = open(av[5], O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (pipex->out_fd == -1)
		print_err_free("No lee el out flie\n", pipex);
	if (dup2(pipex->out_fd, STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		print_err_free("dup2 fd", pipex);
	}
	close(pipex->out_fd);
	if (execve(pipex->path2, pipex->cmd2, envp) == -1)
		print_err_free("error en execve", pipex);
}
