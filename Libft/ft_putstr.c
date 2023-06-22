/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:28:40 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/23 11:29:46 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

/*
int		main(void)
{
	char	*s = "Bonjour";
	

	printf("%d\n",ft_putstr(s));
	return (0);
}
*/