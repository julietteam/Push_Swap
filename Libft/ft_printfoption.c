/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfoption.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:35:14 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/23 11:29:20 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfoption(va_list ap, const char format)
{
	int				count;

	count = 0;
	if (format == 'c')
		count = count + ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count = count + ft_putstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		count = count + ft_printnbr(va_arg(ap, int));
	else if (format == 'u')
		count = count + ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		count = count + ft_hexa(va_arg(ap, unsigned int), format);
	else if (format == 'p')
		count = count + ft_printpointeur(va_arg(ap, uintptr_t));
	else if (format == '%')
		count = count + ft_printpercent();
	return (count);
}
