/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:18:19 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/25 14:13:53 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd_access(t_pipe *pipex, char **cmd)
{
	char	*final_path;
	int		i;

	i = 0;
	while (pipex->all_path)
	{
		final_path = ft_strjoin(pipex->all_path[i], cmd[0]);
		if (!final_path)
		{
			free_matrix(cmd);
			ft_printf("error1\n");
			return (0);
		}
		if (access(final_path, F_OK) == 0)
		{
			ft_printf("hay acceso?");
			if (access(final_path, X_OK) != 0)
			{
			free_matrix(cmd);
			ft_printf("error2\n");
			return (0);
			}
			else
				return (1);
		}
		free(final_path);
		free_matrix(cmd);
		ft_printf("error3\n");
		return (0);
	}
	return(0);	
}