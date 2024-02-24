/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:37:47 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:27:41 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if (((91 > c) && (c > 64)) || ((123 > c) && (c > 96)))
		return (1);
	else
		return (0);
}
/*
int main()
{
    char    c;
    int    res;
    
    c = '6';
    res = ft_isalpha(c);
    printf("%i", res);
    return (0);
}*/
