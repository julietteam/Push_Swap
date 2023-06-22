/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:43:10 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/17 15:12:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	strlen;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (len > strlen)
		len = strlen;
	if (start + len > strlen)
		len = len - start;
	if (start > strlen)
		len = 0;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
/*
int	main(void)
{
	char const	s[] = "coucou toi";
	unsigned int	start;
	size_t		len;

	start = 5;
	len = 12;

	printf("%s\n", ft_substr(s, start, len));
	free(ft_substr(s, start, len));
	return (0);
}
*/