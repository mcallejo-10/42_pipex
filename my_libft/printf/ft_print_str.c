/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:27:22 by mcallejo          #+#    #+#             */
/*   Updated: 2023/10/25 17:20:52 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(int count, char *s)
{
	int	err;

	if (!s)
		s = "(null)";
	err = 0;
	while (*s && err != -1)
	{
		err = ft_print_char(*s);
		if (err != -1)
		{
			count += err;
			s++;
		}
		else
			return (-1);
	}
	return (count);
}
