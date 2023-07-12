/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:29:17 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/11 22:33:36 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
long long int	ft_atoi(const char *nptr)
{
	long long int	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((result > LLONG_MAX / 10) || ((result == LLONG_MAX / 10) && (nptr[i] - '0') > (LLONG_MAX % 10)))
		{
			if (sign == 1)
				return (-1);	// overflow
			else
				return (0);		// underflow
		}
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
*/

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10;
		result = result + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
/*
int	main()
{
	char	nptr[] = "          -1234ab567";

	printf("mon atoi: %d\n", ft_atoi(nptr));
	printf("le vrai atoi: %d\n", atoi(nptr));
}
*/
