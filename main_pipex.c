/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:22:16 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/17 16:59:34 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_all_paths(t_pipe *pipex, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->all_path = ft_split(envp[i], ':');
			pipex->all_path[0] = px_strtrim(pipex->all_path[0], "PATH=");
			return ;
		}
		i++;
	}
	if (!pipex->all_path)
		pipex->all_path = ft_split(DEF_PATH, ':');
}

void	init_pipex(t_pipe *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->all_path = NULL;
	pipex->path1 = NULL;
	pipex->path2 = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->j = 0;
}

int	parsing(char **av, char *envp[], t_pipe *pipex)
{
	init_all_paths(pipex, envp);
	pipex->cmd1 = final_cmd(av[2], pipex);
	pipex->cmd2 = final_cmd(av[3], pipex);
	pipex->path1 = check_cmd_access(pipex, pipex->cmd1);
	pipex->path2 = check_cmd_access(pipex, pipex->cmd2);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	t_pipe	*pipex;

	pipex = NULL;
	if (ac != 5)
		return (print_err_free("Invalid number of arguments\n", pipex, 0));
	pipex = malloc(sizeof(t_pipe));
	if (!pipex)
		return (print_err_free("Malloc error\n", pipex, 0));
	if (!envp)
		return (print_err_free("Envp error\n", pipex, 0));
	init_pipex(pipex);
	parsing(av, envp, pipex);
	if (pipe(fd) < 0)
		print_err_free("Pipe error\n", pipex, 0);
	pid = fork();
	if (pid < 0)
		print_err_free("pid error\n", pipex, 0);
	if (pid == 0)
		child(envp, av[1], pipex, fd);
	waitpid(pid, NULL, 0);
	if (pid != 0)
		parent(envp, av[4], pipex, fd);
	return (0);
}
