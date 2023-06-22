/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:04:42 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/19 15:47:42 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include "libft.h"

int		ft_hexa(unsigned int n, const char c);
int		ft_printf(const char *str, ...);
int		ft_printfoption(va_list ap, const char format);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_printpointeur(uintptr_t ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_printnbr(int n);
int		ft_printpercent(void);

#endif