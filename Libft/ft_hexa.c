/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:43:33 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/23 15:58:07 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ulen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_hexa(unsigned int n, const char c)
{
	int		longueur;
	char	*hex1;
	char	*hex2;

	hex1 = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	longueur = ft_ulen(n);
	if (n >= 16)
		ft_hexa((n / 16), c);
	n = n % 16;
	if (c == 'x')
		write(1, &hex1[n], 1);
	else if (c == 'X')
		write(1, &hex2[n], 1);
	return (longueur);
}
