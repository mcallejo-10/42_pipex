/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:56:59 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 19:27:41 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nlen(int n)
{
	int					nlen;
	long long int		ntemp;

	ntemp = (long long int)n;
	nlen = 0;
	if (n == 0)
		return (1);
	if (ntemp < 0)
	{
		ntemp = ntemp * -1;
		nlen++;
	}
	while (ntemp > 0)
	{
		ntemp = ntemp / 10;
		nlen++;
	}
	return (nlen);
}

char	*ft_isneg(char *a, long long int nlong, int nlen)
{
	nlong = nlong * -1;
	a[0] = '-';
	while (nlen > 0)
	{
		a[nlen--] = '0' + nlong % 10;
		nlong = nlong / 10;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char			*a;
	int				nlen;
	long long int	nlong;

	nlong = (long long int)n;
	nlen = ft_nlen(n);
	a = malloc(sizeof(char) * (nlen + 1));
	if (!a)
		return (0);
	a[nlen--] = '\0';
	if (n < 0)
	{
		return (ft_isneg(a, nlong, nlen));
	}
	while (nlen >= 0)
	{
		a[nlen--] = '0' + nlong % 10;
		nlong = nlong / 10;
	}
	return (a);
}
/*
int	main(void)
{
	int		n;
	char	*a;

	n = -21474836495LL;
	a = ft_itoa(n);
	printf("%s\n", a);
	return (0);
}*/
