/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:42:10 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:27:41 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*ub;

	ub = b;
	i = 0;
	if (c == '0')
		return (b);
	while (i < len)
	{
		ub[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
