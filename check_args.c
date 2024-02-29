/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:18:19 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/29 12:35:59 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd_access(t_pipe *pipex, char **cmd)
{
	char	*final_path;
	int		i;

	i = 0;
	while (pipex->all_path[i])
	{
		final_path = ft_strjoin(pipex->all_path[i], "/");
		final_path = ft_strjoin(final_path, cmd[0]);
		ft_printf("FINAL PATH: %s\n", final_path);
		if (!final_path)
			return (print_err_free("Error 1\n", pipex));
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK) != 0)
				return (print_err_free("Error 2\n", pipex));
			else
			{
				ft_printf("se puede ejecutar!!!!\n");
				return (1);
			}
		}
		i++;
	}
	return (print_err_free("Error 3\n", pipex));
}

char	**final_cmd(char *cmd, t_pipe *pipex)
{
	int		i;
	char	**final_cmd;

	if (cmd[0] == '/')
	{
		i = ft_strlen(cmd) - 1;
		while (cmd[i] != '/')
			i--;
		cmd = ft_substr(cmd, i + 1, ft_strlen(cmd));
	}
	final_cmd = ft_split(cmd, ' ');
	return (final_cmd);
}
