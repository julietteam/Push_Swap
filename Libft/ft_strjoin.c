/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:24:59 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/10 18:29:39 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		longueur;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	longueur = (ft_strlen(s1) + ft_strlen(s2));
	s3 = malloc(sizeof(char) * (longueur + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		s3[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		i++;
		s2++;
	}
	s3 [i] = '\0';
	return (s3);
}
/*
int	main()
{
	char const	s1[] = "coucou";
	char const	s2[] = "bonjour, comment ca va ?";


	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/