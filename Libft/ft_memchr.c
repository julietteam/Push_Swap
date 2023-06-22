/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:32:18 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 17:41:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < (unsigned char) n)
	{
		if (str[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

// int main() 
// {

//     const char s[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
//     unsigned char n = 10;

//     // On recherche une valeur inhéxistante :
// 	//char *str = ft_memchr( s, 57, n );
// 	char *str = memchr( s, 57, n );
// 	printf( "57 is %s\n", ( str != NULL ? "found" : "not found" ) );

//     // On recherche une valeur existante :
// 	//str = ft_memchr( s, 50, n );
// 	str = memchr( s, 50, n );
// 	printf( "50 is %s\n", ( str != NULL ? "found" : "not found" ) );
// 	if ( str != NULL )
// 	{
// 		printf( "La valeur à la position calculée est %c\n", *((char *) str) );
//    	}
//     return (0);
// }
