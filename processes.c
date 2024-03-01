/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:52:41 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/01 12:20:00 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(char **envp, char *av, t_pipe *pipex, int fd[])
{
	write(1, "entra en el parent\n", 19);
	close(fd[1]);
	pipex->out_fd = open(av, O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (pipex->out_fd == -1)
	{
		perror("Out_fd");
		print_err_free("No lee el out flie\n", pipex);
	}
	ft_printf("lo ha abierto??\n");
	ft_printf("out_fd: %i\n", pipex->out_fd);
	if (dup2(pipex->out_fd, STDOUT_FILENO) < 0)
	{
		close(pipex->out_fd);
		print_err_free("dup2 fd\n", pipex);
	}
	ft_printf("duplicado??\n");
	//close(pipex->out_fd);
	close(fd[0]);
	ft_printf("path2:%s\ncmd2: %s\nenvp:%s\n", pipex->path2, pipex->cmd2[0], envp);
	if (execve(pipex->path2, pipex->cmd2, envp) == -1)
	{
		perror("Error ejecutando slida");
		print_err_free("error en execve\n\n", pipex);
	}
	ft_printf("Final;)\n");
}

void	child(char **envp, char *av, t_pipe *pipex, int fd[])
{
	// write(1, "entra en el child\n", 18);
	close(fd[0]);
	pipex->in_fd = open(av, O_RDONLY);
	if (pipex->in_fd == -1)
		print_err_free("No lee el in flie\n", pipex);
	if (dup2(pipex->in_fd, STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		print_err_free("dup2 fd", pipex);
	}
	ft_printf("path1:%s\ncmd%s\nenvp:%s\n", pipex->path1, pipex->cmd1[0], envp);

	if (execve(pipex->path1, pipex->cmd1, envp) == -1)
		print_err_free("error en execve\n\n", pipex);
	close(pipex->in_fd);
	close(fd[1]);
}
