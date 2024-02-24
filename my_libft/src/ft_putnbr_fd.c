/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:01 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:22:37 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nlong;

	nlong = (long long int)n;
	if (n < 0)
	{
		nlong = nlong * -1;
		write(fd, "-", 1);
	}
	if (nlong > 9)
	{
		ft_putnbr_fd(nlong / 10, fd);
		ft_putchar_fd(nlong % 10 + '0', fd);
	}
	else if (nlong < 10)
		ft_putchar_fd(nlong + '0', fd);
}
