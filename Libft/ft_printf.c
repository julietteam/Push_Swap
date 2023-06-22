/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:39:13 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/23 17:08:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	else
	{
		va_start(ap, str);
		while (str[i] != '\0')
		{	
			if (str[i] == '%')
			{
				count = count + ft_printfoption(ap, str[i + 1]);
				i++;
			}
			else
				count = count + ft_putchar(str[i]);
			i++;
		}
	}
	va_end (ap);
	return (count);
}
