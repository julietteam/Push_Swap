/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:33:29 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/15 15:25:26 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}
/*
int     main()
{
	int     c;

	c = 'm';
	printf("%c -> %c\n", c, ft_tolower(c));
 	printf("%c -> %c\n", c, tolower(c));

	c = 'D';
	printf("%c -> %c\n", c, ft_tolower(c));
	printf("%c -> %c\n", c, tolower(c));

 	c = '9';
	printf("%c -> %c\n", c, ft_tolower(c));
	printf("%c -> %c\n", c, tolower(c));
	return (0);
}
*/
