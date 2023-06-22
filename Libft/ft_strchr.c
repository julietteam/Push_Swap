/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:43:30 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 11:01:11 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*
int	main()
{
	const char s[] = "coucou bonjour";
	int	c;

	c = 'b';
	printf("Ma chaine commencant a : %s\n", ft_strchr(s, c));
	printf("Ma chaine commencant a : %s\n", strchr(s, c));
	return (0);
}
*/