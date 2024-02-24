/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:15:19 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:27:41 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;
	char	*str;
	int		flag;

	flag = 0;
	a = (unsigned char)c;
	i = 0;
	str = (char *)s;
	while (s[i] && flag == 0)
	{
		if (str[i] == a)
		{
			return (str + i);
			flag = 1;
		}
		i++;
	}
	if (a == '\0')
		return (str + i);
	return (NULL);
}
/*
int main()
{
	const char	*str = "hola caracola";
	int			c = 'l';
	char		*res;
	
	res = ft_strchr(str, c);
	if (res != NULL)
        printf("El caracter '%c' posición %ld\n", c, res - str);
    else
        printf("El caracter '%c' no se encontró en la cadena.\n");

	return (0);
}*/
