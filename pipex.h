/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:10:29 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/17 16:49:44 by mcallejo         ###   ########.fr       */
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

# define DEF_PATH "/usr/local/bin:/usr/bin:/bin:\
	/usr/sbin:/sbin:/usr/local/go/bin:"

typedef struct s_pipe
{
	int		in_fd;
	int		out_fd;
	char	**all_path;
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	int		j;

}	t_pipe;

/// MAIN_PIPEX ///
int		parsing(char **av, char *envp[], t_pipe *pipex);
void	init_pipex(t_pipe *pipex);
void	init_all_paths(t_pipe *pipex, char **envp);

/// CHECK_ARGS ///
char	*check_cmd_access(t_pipe *pipex, char **cmd);
char	**final_cmd(char *cmd, t_pipe *pipex);
char	**split_with_quotes(char *cmd, t_pipe *pipex);
int		subsrt_space(const char *s, char c);
void	split_quotes(char **ret, char *cmd, int i, int j);

/// PROCESSES ///
void	child(char **envp, char *av, t_pipe *pipex, int fd[]);
void	parent(char **envp, char *av, t_pipe *pipex, int fd[]);

/// UTILS_PIPEX ///
int		strchr_count(char *str, char c);
void	*px_free(char **str);
char	*px_strjoin(char *raw, char *buf);
char	*px_barjoin(char *raw, char *buf);
char	*px_strtrim(char *s1, char *set);

/// ERRORS ///
void	free_matrix(char **arr);
void	clean_pipex(t_pipe *pipex);
int		print_err_free(char *msg, t_pipe *pipex, int flag);

#endif