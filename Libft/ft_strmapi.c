/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:07:03 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 10:59:42 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char		*ptr;
	int			i;
	int			l;

	i = 0;
	if (!s || !f)
		return (0);
	l = ft_strlen(s);
	ptr = malloc(sizeof(char) * l + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	f(unsigned int i, char c)
{
	char	ptr;

	ptr = c + i;
	return (ptr);
}
/*
int		main()
{
	char	*ptr1;
	char 	*ptr2;

	ptr1 = "efg";
	ptr2 = ft_strmapi(ptr1, *f);
	printf("%s\n", ptr2);
}
*/