/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:52:41 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/29 18:02:54 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(char **envp, char *av, t_pipe *pipex, int fd[])
{
	write(1, "entra en el parent\n", 19);
	close(fd[1]);
	pipex->out_fd = open(av, O_CREAT | O_RDWR, 0666);
	if (pipex->out_fd == -1)
	{
		perror("Error al abrir el archivo de salida");
		print_err_free("No lee el out flie\n", pipex);
	}
	if (dup2(pipex->out_fd, STDOUT_FILENO) < 0)
	{
		close(pipex->out_fd);
		print_err_free("dup2 fd\n", pipex);
	}
	close(fd[0]);
	if (execve(pipex->path2, pipex->cmd2, envp) == -1)
	{
		perror("Error ejecutando slida");
		print_err_free("error en execve\n\n", pipex);
	}
}

void	child(char **envp, char *av, t_pipe *pipex, int fd[])
{
	write(1, "entra en el child\n", 18);
	close(fd[0]);
	pipex->in_fd = open(av, O_RDONLY);
	if (pipex->in_fd == -1)
		print_err_free("No lee el in flie\n", pipex);
	check_cmd_access(pipex, pipex->cmd1);
	if (dup2(pipex->in_fd, STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		print_err_free("dup2 fd", pipex);
	}
	close(pipex->in_fd);
	close(fd[1]);
	if (execve(pipex->path1, pipex->cmd1, envp) == -1)
		print_err_free("error en execve\n\n", pipex);
}
