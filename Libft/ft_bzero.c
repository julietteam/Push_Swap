/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:20:33 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/17 14:36:51 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			compteur;
	unsigned char	*ptr;

	compteur = 0;
	ptr = s;
	while (compteur < n)
	{
		*(ptr + compteur) = '\0';
		compteur++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "coucou, tu peux mettre des backslash zero";
	printf("la valeur originale est ; %s\n", str);
	ft_bzero(str, 5);
	printf("la valeur modifiee de ma fonction est : %s\n", str);
	bzero(str, 5);
	printf("la valeur modifiee de la vraie fonction est : %s\n", str);
}
*/
