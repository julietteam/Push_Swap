/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:57:15 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 11:16:28 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	while (s[i] != '\0')
		i++;
	if (ch == '\0')
		return ((char *) s + i);
	i--;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int	main()
{
	const char s[] = "coucougguu";
	int	c;

	c = 'u';
	printf("Ma derniere occurence est : %s\n", ft_strrchr(s, c));
	printf("Ma derniere occurence est : %s\n", strrchr(s, c));
	return (0);
}
*/