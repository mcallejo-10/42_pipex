/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:20:57 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:30:15 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	a;

	a = (unsigned char)c;
	str = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (str[len] == a)
			return (str + len);
		else
			len--;
	}
	return (NULL);
}
/*int main()
{
	const char	*str = "hola caracola";
	int			c = 'h';
	char		*res;
	
	res = ft_strrchr(str, c);
	if (res != NULL)
        printf("El caracter '%c' posición %ld\n", c, res - str);
    else
        printf("El caracter '%c' no se encontró en la cadena.\n");

	return (0);
}*/
