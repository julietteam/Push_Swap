/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:31:24 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/17 14:54:22 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int		len;

	len = 0;
	if (n == 0)
	len = 1;
	if (n < 0)
	{
		n = n *(-1);
		len = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	l_nb;
	int		i;

	l_nb = n;
	i = ft_intlen(l_nb);
	ptr = ft_calloc(i + 1, sizeof (char));
	if (!ptr)
		return (NULL);
	if (l_nb == 0)
		ptr[--i] = '0';
	if (l_nb < 0)
	{
		ptr[0] = '-';
		l_nb = l_nb * (-1);
	}
	i--;
	while (l_nb > 0)
	{
		ptr[i] = ((l_nb % 10) + 48);
		l_nb = l_nb / 10;
		i--;
	}
	return (ptr);
}
/*
int	main(void)
{
	int		n;

	n = -6;
	printf("itoa: %s\n", ft_itoa(n));
	//printf("itoa: %d\n", itoa(n));
}
*/