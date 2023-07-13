/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:49 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/13 16:43:16 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Libft/ft_printf.h"
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


void sort_four_to_five_elements(t_stack *stack)
{
    while (stack->b_size <= 1)
    {
        if (stack->stack_a[0] < 2)
            push("pb", stack);
        else
            rotate(stack->stack_a, stack->a_size, "up", "a");
    }
    
    if (stack->stack_b[0] == 0)
        swap("sb", stack->stack_b, stack->b_size);
    
    if (stack->a_size == 5 && stack->stack_a[2] != 4 && stack->stack_a[2] != 5)
        rotate(stack->stack_a, stack->a_size, (stack->stack_a[0] == 4 || stack->stack_a[0] == 5) ? "up" : "down", "a");
    else if (stack->stack_a[2] != 4)
        rotate(stack->stack_a, stack->a_size, (stack->stack_a[0] == 4) ? "up" : "down", "a");
    
    if (stack->stack_a[0] > stack->stack_a[1])
        swap("sa", stack->stack_a, stack->a_size);
    
    push("pa", stack);
    push("pa", stack);
}


static void	radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j)
{
    while (b_size-- && j <= bit_size && !is_array_sorted(stack))
	{
        if (((stack->stack_b[0] >> j) & 1) == 0)
			rotate(stack->stack_b, stack->b_size, "up", "b");
		else
			push("pa", stack);
	}
	if (is_array_sorted(stack))
		while (stack->b_size != 0)
			push("pa", stack);
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
				push("pb", stack);
			else
				rotate(stack->stack_a, stack->a_size, "up", "a");
		}
		radix_sort_stack_b(stack, stack->b_size, bit_size, i + 1);
	}
	while (stack->b_size != 0)
		push("pa", stack);
}

