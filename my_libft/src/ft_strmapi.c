/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:57:43 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:30:15 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;
	size_t			slen;

	slen = ft_strlen(s);
	ret = malloc(sizeof(char) * slen + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < slen)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
/*
int main(void)
{
	char	*s = "hola caracola";
	char	*ret;

	ret = ft_strmapi(s, toupper);
	printf("%s", ret);
	return (0);
}*/
