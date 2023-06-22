/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:58:56 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 17:52:47 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		compteur;

	if (src == NULL && dest == NULL)
		return (NULL);
	compteur = 0;
	destination = (char *)dest;
	source = (const char *)src;
	while (compteur < n)
	{
		destination[compteur] = source[compteur];
		compteur++;
	}
	return (dest);
}

// int	main(void)
// {
// 	const char src[] = "Tu vas te recopier non de dieu";
// 	char dest [] = "bienvenue dans la destination";
// 	printf("ma fonction; %s\n", (char *)ft_memcpy(dest, src, 20));
// 	printf("la vraie fonction; %s\n", (char *)memcpy(dest, src, 20));
// 	return (0);
// }
