/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:48:58 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 14:54:42 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t		longueur;
	char		*ptr;
	int			i;

	i = 0;
	longueur = ft_strlen(str);
	ptr = (char *)malloc((longueur + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int		main()
{
	const char	str[] = "hello";

	printf("%s\n", ft_strdup(str));
	printf("%s\n", strdup(str));
	free(ft_strdup(str));
	free(strdup(str));

	return (0);
}
*/