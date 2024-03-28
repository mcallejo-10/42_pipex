/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:41:15 by mcallejo          #+#    #+#             */
/*   Updated: 2024/03/17 16:49:58 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	strchr_count(char *str, char c)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}

void	*px_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*px_barjoin(char *path, char *buf)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	str = malloc(sizeof(char) * ((ft_strlen(path) + ft_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (path && path[++i] != '\0')
		str[i] = path[i];
	while (buf && buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	return (str);
}

char	*px_strjoin(char *path, char *buf)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	str = malloc(sizeof(char) * ((ft_strlen(path) + ft_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (path && path[++i] != '\0')
		str[i] = path[i];
	while (buf && buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	free(path);
	return (str);
}

char	*px_strtrim(char *s1, char *set)
{
	size_t			start;
	size_t			j;
	size_t			len;
	char			*ret;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1);
	while (len > start && ft_strchr(set, s1[len - 1]))
		len--;
	ret = (char *)malloc(sizeof(char) * ((len - start) + 1));
	if (!ret)
		return (NULL);
	j = 0;
	while (start < len)
	{
		ret[j] = s1[start];
		j++;
		start++;
	}
	ret[j] = '\0';
	free(s1);
	return (ret);
}
