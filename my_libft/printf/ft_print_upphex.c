/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upphex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:51:58 by mcallejo          #+#    #+#             */
/*   Updated: 2023/10/25 17:27:11 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upphex(int count, unsigned int x)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (x >= 16)
		count = ft_print_upphex(count, x / 16);
	if (count == -1)
		return (-1);
	count += ft_print_char(base[x % 16]);
	return (count);
}
