/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:16:40 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/15 15:22:49 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int argument)
{
	if (argument >= 'a' && argument <= 'z')
		return (1);
	else if (argument >= 'A' && argument <= 'Z')
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
int	main()
{
	printf("%d\n",ft_isalpha(10));
	printf("%d\n", isalpha(10));
	return (0);
}
*/
