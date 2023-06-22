/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:12 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/15 15:23:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	compteur;
	char	*ptr;

	compteur = 0;
	ptr = s;
	while (compteur < n)
	{
		*(ptr + compteur) = c;
		compteur++;
	}
	return (s);
}
/*	
int	main(void)
{
	char str[] = "salut toi, tu piges quelque chose?";
	printf("la valeur originale est: %s\n", str);
	ft_memset(str, 40, 15);
	printf("la valeur modifiee de ma fonction est: %s\n", str);
	memset(str, 40, 15);
	printf("la valeur modifiee de la vraie fonction est: %s\n", str);
}
*/
