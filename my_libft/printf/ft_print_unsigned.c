/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:59:28 by mcallejo          #+#    #+#             */
/*   Updated: 2023/10/25 17:24:06 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(int count, unsigned int u)
{
	if (u > 9)
		count = ft_print_unsigned(count, u / 10);
	if (count == -1)
		return (-1);
	count += ft_print_char(u % 10 + '0');
	return (count);
}
