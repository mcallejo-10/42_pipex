/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:53 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/05 18:44:56 by mcallejo         ###   ########.fr       */
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

	if (ft_strncmp(cmd, "awk", 3) == 0)
	{
		final_cmd = split_awk(cmd, ' ');
		i = 0;
		while (cmd[i] != '\'')
			i++;
		final_cmd[i] = ft_substr(cmd, i, ft_strlen(cmd));
		final_cmd[i + 1] = NULL;
		ft_printf("%s\n%s\n%s\n", final_cmd[0], final_cmd[1], final_cmd[2]);
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

int	subsrt_awk(const char *s, char c)
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

char	**split_awk(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		start;

	ret = malloc(sizeof(char *) * (subsrt_awk(s, c) + 2));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	start = 0;
	while (s[i++] != '\'')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\''))
		{
			ret[j++] = ft_substr(s, start, i - start +1);
			if (ret[j - 1] == NULL)
				return (0);
		}
	}
	ret[j] = NULL;
	return (ret);
}
