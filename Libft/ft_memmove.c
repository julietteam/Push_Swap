/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:21:40 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/15 16:17:26 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	int			i;

	destination = dest;
	source = src;
	if (destination > source)
	{
		i = (int) n - 1;
		while (i >= 0)
		{
			destination[i] = source[i];
			i--;
		}
	}
	else if (source > destination)
	{
		i = 0;
		while (i < (int) n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	//char 			dest[] = "hello";
	char		src[] = "hello, comment ca va ";

	printf("ma fonction; %s\n", (char *)ft_memmove(src + 3, src, 5));
	printf("la vraie fonction ; %s\n", (char *)memmove(src + 3, src, 5));
	return (0);
}
*/