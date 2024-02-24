/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:59:54 by mcallejo          #+#    #+#             */
/*   Updated: 2023/10/25 17:00:36 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_aux(int count, unsigned long long x)
{
	char	*base;
	int		err;

	base = "0123456789abcdef";
	if (x >= 16)
	{
		count = ft_print_aux(count, x / 16);
		if (count == -1)
			return (-1);
	}
	err = ft_print_char(base[x % 16]);
	if (err != -1)
		count += err;
	else
		return (-1);
	return (count);
}

int	ft_print_pointer(int count, void *p)
{
	count = ft_print_str(count, "0x");
	if (count == -1)
		return (-1);
	count = ft_print_aux(count, (unsigned long long)p);
	if (count == -1)
		return (-1);
	return (count);
}
