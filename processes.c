/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:52:41 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/25 19:09:28 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **envp, char **av, t_pipe *pipex, int fd[])
{
	ft_printf("entra en el child\n");
}

void	parent(char **envp, char **av, t_pipe *pipex, int fd[])
{
	ft_printf("entra en el parent\n");
}
