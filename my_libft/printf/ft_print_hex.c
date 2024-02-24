/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:00:09 by mcallejo          #+#    #+#             */
/*   Updated: 2023/10/25 17:23:10 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(int count, unsigned int x)
{
	char	*base;

	base = "0123456789abcdef";
	if (x >= 16)
		count = ft_print_hex(count, x / 16);
	if (count == -1)
		return (-1);
	count += ft_print_char(base[x % 16]);
	return (count);
}
