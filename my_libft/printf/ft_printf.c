/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:37 by mcallejo          #+#    #+#             */
/*   Updated: 2023/10/25 16:51:21 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_eval_format(int count, va_list arglist, char c)
{
	if (c == 'c')
		count += ft_print_char(va_arg(arglist, int));
	if (c == 's')
		count = ft_print_str(count, va_arg(arglist, char *));
	if (c == 'p')
		count = ft_print_pointer(count, va_arg(arglist, void *));
	if (c == 'd' || c == 'i')
		count = ft_print_int(count, va_arg(arglist, int));
	if (c == 'u')
		count = ft_print_unsigned(count, va_arg(arglist, unsigned int));
	if (c == 'x')
		count = ft_print_hex(count, va_arg(arglist, unsigned int));
	if (c == 'X')
		count = ft_print_upphex(count, va_arg(arglist, unsigned int));
	if (c == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list		arglist;
	int			i;
	int			count;

	va_start(arglist, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = ft_eval_format(count, arglist, format[i]);
			i++;
		}
		else
		{
			count = count + ft_print_char(format[i]);
			i++;
		}
		if (count == -1)
			return (-1);
	}
	return (count);
}

// int	main(void)
// {
// 	//char			c = 'm';
// 	//char			*s = "dos";
// 	int				i = 42;
// 	//unsigned int	u = 100;
// 	int				ret;
// 	int				ret2;

// 	ret = ft_printf("Mi p: %i\n", i);
// 	ret2 = printf("Su p: %i\n", i);
// 	printf("el retorno de la función es: %d\n", ret);
// 	printf("El retorno de la función original es: %d\n", ret2);
// 	return (0);
// }