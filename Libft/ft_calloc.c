/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:48:31 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/15 16:17:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tableau;
	size_t	taillemax;

	taillemax = nmemb * size;
	if (size != 0 && (taillemax / size != nmemb))
		return (NULL);
	tableau = malloc (taillemax);
	if (!tableau)
		return (NULL);
	ft_bzero(tableau, taillemax);
	return (tableau);
}
/*
int main(void)
{
	int	*tab;
	//tab = ft_calloc(0,4);
	tab = calloc(0, 4);
	printf("%p\n", tab);
	free(tab);
	return (0);
}
*/