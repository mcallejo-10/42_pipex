/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:22:36 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:30:15 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (start >= ft_strlen(s))
	{
		ret = ft_calloc(1, sizeof(char));
		if (!ret)
			return (NULL);
		return (ret);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = ft_calloc(sizeof(char), len + 1);
	if (!ret)
		return (NULL);
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}
/*
int	main(void)
{
	char	*str;
	char	*ret;

	str = "lorem ipsum dolor";
	ret = ft_substr(str, 0, 10);
	printf("%s", ret);
	return (0);
}
*/