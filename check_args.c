/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:53 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/17 16:38:05 by mcallejo         ###   ########.fr       */
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
		final_path = px_barjoin(pipex->all_path[i], "/");
		final_path = px_strjoin(final_path, cmd[0]);
		if (!final_path)
			print_err_free("Malloc error\n", pipex, 0);
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK) != 0)
				print_err_free("Execute access failure\n", pipex, 1);
			else
				return (final_path);
		}
		else
			free(final_path);
		i++;
	}
	print_err_free("Access error: ", pipex, 1);
	return (0);
}

char	**final_cmd(char *cmd, t_pipe *pipex)
{
	int		i;
	char	**final_cmd;

	i = 0;
	if (strchr_count(cmd, '\'') > 0)
	{
		final_cmd = split_with_quotes(cmd, pipex);
		return (final_cmd);
	}
	else if (cmd[0] == '/')
	{
		i = ft_strlen(cmd) - 1;
		while (cmd[i] != '/')
			i--;
		cmd = ft_substr(cmd, i + 1, ft_strlen(cmd));
	}
	final_cmd = ft_split(cmd, ' ');
	return (final_cmd);
}

int	subsrt_space(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\'')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 34))
			count++;
		i++;
	}
	return (count);
}

char	**split_with_quotes(char *cmd, t_pipe *pipex)
{
	char	**ret;
	int		i;
	int		start;

	start = 0;
	i = 0;
	ret = malloc(sizeof(char *) * (subsrt_space(cmd, ' ')
				+ (strchr_count(cmd, '\'') / 2) + 1));
	if (!ret)
		return (NULL);
	while (cmd[i++] != '\'' && cmd[i] != '\0')
	{
		if (i > 0 && cmd[i] != ' ' && cmd[i - 1] == ' ')
			start = i;
		if (cmd[i] != ' ' && (cmd[i + 1] == ' '))
		{
			ret[pipex->j] = ft_substr(cmd, start, i - start + 1);
			if (!ret[pipex->j])
				return (NULL);
			pipex->j++;
		}
	}
	split_quotes(ret, cmd, i, pipex->j);
	return (ret);
}

void	split_quotes(char **ret, char *cmd, int i, int j)
{
	int		flag;
	int		start;

	flag = 0;
	while (cmd[i])
	{
		if (cmd[i] != '\'' && cmd[i - 1] == '\'' && flag == 0)
		{
			start = i;
			flag = 1;
			while (cmd[i] != '\'')
				i++;
			ret[j++] = ft_substr(cmd, start, i - start);
		}
		else if (cmd[i] == '\'' && flag == 1)
			flag = 0;
		i++;
	}
}
