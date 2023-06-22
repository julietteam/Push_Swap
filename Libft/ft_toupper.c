/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:41:35 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/15 15:25:36 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		c = c - 32;
	}
	return (c);
}
/*
int	main()
{
	int	c;

	c = 'm';
	printf("%c -> %c\n", c, ft_toupper(c));
	printf("%c -> %c\n", c, toupper(c));

	c = 'D';
	printf("%c -> %c\n", c, ft_toupper(c));
	printf("%c -> %c\n", c, toupper(c));

	c = '9';
	printf("%c -> %c\n", c, ft_toupper(c));
	printf("%c -> %c\n", c, toupper(c));
	return (0);
}
*/
