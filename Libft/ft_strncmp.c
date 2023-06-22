/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:42:37 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 16:41:42 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
/*
 int main() 
{

        char    s1[] = "hello";
        char    s2[] = "helLO WORLD";
	size_t	n;

	n = 4;
   
	printf("%d\n", ft_strncmp(s1, s2, n));         
	printf("%d\n", strncmp(s1, s2, n)); 
     	return (0);
}
*/
