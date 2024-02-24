/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:10:29 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/24 19:49:03 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./my_libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define DEF_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:"

typedef struct s_pipe
{
	int		in_fd;
	int		out_fd;
	char	**all_path;
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
}	t_pipe;

/// MAIN PIPEX ///
int		parsing(char **av, char *envp[], t_pipe *pipex);
void	init_pipex(t_pipe *pipex);
void	init_all_paths(t_pipe *pipex, char *envp[]);

/// ERROR ///
void	free_matrix(char **arr);
int		print_err_free(char *msg, t_pipe *pipex);







#endif