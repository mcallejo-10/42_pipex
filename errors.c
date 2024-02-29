/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:29:19 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/29 12:46:38 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	clean_pipex(t_pipe *pipex)
{
	if (pipex->all_path)
		free_matrix(pipex->all_path);
	if (pipex->path1)
		free(pipex->path1);
	if (pipex->path1)
		free(pipex->path1);
	if (pipex->cmd1)
		free_matrix(pipex->cmd1);
	if (pipex->cmd2)
		free_matrix(pipex->cmd2);
	if (pipex)
		free(pipex);
}

int	print_err_free(char *msg, t_pipe *pipex)
{
	write(2, msg, ft_strlen(msg));
	clean_pipex(pipex);
	return (0);
}
