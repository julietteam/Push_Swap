/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:49 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/14 14:29:51 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Libft/ft_printf.h"
#include "push_swap.h"

static void	radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(stack))
	{
		if (((stack->stack_b[0] >> j) & 1) == 0)
			rotate(stack->stack_b, stack->b_size, "up", "b");
		else
			push_pa(stack);
	}
	if (is_array_sorted(stack))
		while (stack->b_size != 0)
			push_pa(stack);
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	i = -1;
	while (++i <= bit_size)
	{
		size = stack->a_size;
		while (size-- && !is_array_sorted(stack))
		{
			if (((stack->stack_a[0] >> i) & 1) == 0)
				push_pb(stack);
			else
				rotate(stack->stack_a, stack->a_size, "up", "a");
		}
		radix_sort_stack_b(stack, stack->b_size, bit_size, i + 1);
	}
	while (stack->b_size != 0)
		push_pb(stack);
}
