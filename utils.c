/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:48:37 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/14 15:07:46 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_array_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	exit_if_sorted_or_has_duplicate(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stack->a_size)
		{
			j = i + 1;
			while (j < stack->a_size)
			{
				if (stack->stack_a[i] == stack->stack_a[j])
					free_and_exit_with_message(stack, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(stack))
		free_and_exit_with_message(stack, NULL);
}

int	is_valid_integer(const char *str, long long *result)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && !ft_isdigit(str[i]))
			return (1);
		i++;
	}
	*result = sign * ft_atoi_check_overflow(str, result);
	if ((sign == -1 && (*result < INT_MIN || *result > 0))
		|| (sign == 1 && (*result > INT_MAX || *result < 0)))
		return (1);
	return (0);
}

int	ft_atoi_check_overflow(const char *str, long long *result)
{
	long long	r;
	int			sign;
	int			i;

	r = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r > LLONG_MAX / 10 || (r == LLONG_MAX / 10 && (str[i] - '0')
				> LLONG_MAX % 10))
			return ((*result = 0), (1));
		r = r * 10 + (str[i] - '0');
		i++;
	}
	*result = r * sign;
	if (*result > INT_MAX || *result < INT_MIN)
		return ((*result = 0), (1));
	return (0);
}

void	parse_numbers(t_stack *stack)
{
	char		**tmp;
	long long	num;
	int			i;
	int			z;

	z = 0;
	i = 0;
	tmp = ft_split(stack->join_args, ' ');
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		if (ft_atoi_check_overflow(tmp[i], &num) == 0)
			stack->stack_a[z++] = (int)num;
		else
		{
			ft_printf("Error\n");
			free(stack->stack_a);
			free(tmp[i]);
			free(tmp);
			exit(1);
		}
		free(tmp[i]);
		i++;
	}
	free(tmp);
	stack->a_size = z;
}
