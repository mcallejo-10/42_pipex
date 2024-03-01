/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:18:19 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/01 17:30:07 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_cmd_access(t_pipe *pipex, char **cmd)
{
	char	*final_path;
	int		i;

	i = 0;
	while (pipex->all_path[i])
	{
		final_path = ft_strjoin(pipex->all_path[i], "/");
		final_path = ft_strjoin(final_path, cmd[0]);
		if (!final_path)
			print_err_free("Error all paths\n", pipex, 0);
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK) != 0)
				print_err_free("Execute access failure\n", pipex, 0);
			else
				return (final_path);
		}
		i++;
	}
	print_err_free("Error 3\n", pipex, 0);
	return (0);
}

char	**final_cmd(char *cmd)
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
