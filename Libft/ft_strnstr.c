/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:16:01 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 17:57:38 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!big && len == 0)
		return (NULL);
	if (little[j] == '\0')
		return ((char *)big);
	while ((big[i] != '\0') && (i < len))
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] != '\0' && big[i + j] == little[j] && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

// int	main() 
// {
// 	printf("%s\n", ft_strnstr("foo bar baz", "bar", 12));
// 	//printf("%s\n", strnstr("hello", "", 5));

// 	return (0);
// }
