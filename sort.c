/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:09:00 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/14 14:34:21 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stack *stack)
{
	if (stack->stack_a[2] != 2)
	{
		if (stack->stack_a[0] == 2)
			rotate(stack->stack_a, stack->a_size, "up", "a");
		else
			rotate(stack->stack_a, stack->a_size, "down", "a");
	}
	if (stack->stack_a[0] > stack->stack_a[1])
		swap("sa", stack->stack_a, stack->a_size);
}

void	push_lowest_values(t_stack *stack)
{
	while (stack->b_size <= 1)
	{
		if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
			push_pb(stack);
		else
			rotate(stack->stack_a, stack->a_size, "up", "a");
	}
	if (stack->stack_b[0] == 0)
		swap("sb", stack->stack_b, stack->b_size);
}

void	rotate_middle_values(t_stack *stack)
{
	if (stack->a_size == 5)
	{
		if (stack->stack_a[2] != 4 && stack->stack_a[2] != 5)
		{
			if (stack->stack_a[0] == 4 || stack->stack_a[0] == 5)
				rotate(stack->stack_a, stack->a_size, "up", "a");
			else
				rotate(stack->stack_a, stack->a_size, "down", "a");
		}
	}
	else if (stack->stack_a[2] != 4)
	{
		if (stack->stack_a[0] == 4)
			rotate(stack->stack_a, stack->a_size, "up", "a");
		else
			rotate(stack->stack_a, stack->a_size, "down", "a");
	}
}

void	sort_four_to_five_elements(t_stack *stack)
{
	push_lowest_values(stack);
	rotate_middle_values(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		swap("sa", stack->stack_a, stack->a_size);
	push_pa(stack);
	push_pa(stack);
}
