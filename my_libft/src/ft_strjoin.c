/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:00:46 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:30:15 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	lenjoin;

	lenjoin = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof (char) * lenjoin);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, lenjoin);
	ft_strlcat(join, s2, lenjoin);
	if (!join)
		return (0);
	else
		return (join);
}
/*
int main()
{
	char arr[] = "hola";
	char arr2[] = "adeu";
	char	*res;
	res = ft_strjoin(arr2, arr);
	printf("res: %s\n", arr2);
	return (0);
}*/
