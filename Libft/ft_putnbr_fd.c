/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:21:20 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/16 16:19:04 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = n * (-1);
			ft_putchar_fd('-', fd);
		}
		if (n >= 0 && n < 10)
		{
			ft_putchar_fd(n + '0', fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
/*
int	main(void)
{
	int	n;
	int	fd;

	n = 12345;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
}
*/