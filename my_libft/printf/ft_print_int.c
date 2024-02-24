/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:58:40 by mcallejo          #+#    #+#             */
/*   Updated: 2023/10/25 17:26:45 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int count, int di)
{
	long int	nlong;

	nlong = (long int)di;
	if (di < 0)
	{
		nlong = nlong * -1;
		if ((ft_print_char('-')) == -1)
			return (-1);
		count += 1;
	}
	if (nlong > 9)
	{
		count = ft_print_int(count, nlong / 10);
		if (count == -1)
			return (-1);
		count += ft_print_char(nlong % 10 + '0');
	}
	else if (nlong < 10)
		count += ft_print_char(nlong + '0');
	return (count);
}
