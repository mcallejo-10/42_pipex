/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:26:47 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:30:15 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (*dst != '\0')
	{
		dst++;
		i++;
	}
	while ((*src != '\0') && (i < dstsize -1))
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = '\0';
	if (dstlen > dstsize)
		dstlen = dstsize;
	return (dstlen + srclen);
}
/*
int main()
{
	char arr[] = "hola";
	char arr2[] = "adeu";

	//ft_strlcat(arr2, arr, 4);
	strlcat(arr2, arr, 5);
	printf("dst: %s\n", arr2);
	printf("Origen: %s\n", arr);

	return (0);
}*/
