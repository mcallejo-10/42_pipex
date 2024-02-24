/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:25:11 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/06 15:11:59 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(char const *format, ...);
int	ft_print_str(int count, char *s);
int	ft_print_pointer(int count, void *p);
int	ft_print_char(char c);
int	ft_print_int(int count, int n);
int	ft_print_unsigned(int count, unsigned int u);
int	ft_print_hex(int count, unsigned int x);
int	ft_print_upphex(int count, unsigned int x);

#endif