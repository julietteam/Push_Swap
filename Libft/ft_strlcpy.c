/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:16:08 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/15 16:24:10 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	compteur;
	int	longueur;

	compteur = 0;
	longueur = ft_strlen(src);
	if (size != 0)
	{
		while (src[compteur] != '\0' && (unsigned long) compteur < size - 1)
		{
			dst[compteur] = src[compteur];
			compteur++;
		}
	dst[compteur] = '\0';
	}
	return (longueur);
}
/*
int main()
{
	const char	src[] = "coucou";
	char		dst[] = "bonjour, comment ca va ?";

	printf("longueur: %ld\n copie: %s\n", ft_strlcpy(dst, src, 50), dst);
	//printf("longueur: %d\n copie: %s\n", strlcpy(dst, src, 50), dst);
	return (0);
}
*/
