/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:28:53 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/05 15:47:23 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void print_sa(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        swap(stack_a);
        ft_putstr("sa");
        ft_putchar('\n');
    }
}

void print_sb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        swap(stack_b);
        ft_putstr("sb");
        ft_putchar('\n');
    }
}

void print_ss(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        swap(stack_a);
        swap(stack_b);
        ft_putstr("ss");
        ft_putchar('\n');
    }
}

void print_pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->top >= 0)
    {
        push(stack_b, stack_a);
        ft_putstr("pa");
        ft_putchar('\n');
		stack_a->start++;
        stack_a->end--;
    }
}

void print_pb(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 0)
    {
        push(stack_a, stack_b);
        ft_putstr("pb");
        ft_putchar('\n');
		stack_a->start++;
        stack_a->end--;
    }
}

void print_ra(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        rotate(stack_a);
        ft_putstr("ra");
        ft_putchar('\n');
    }
}

void print_rb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        rotate(stack_b);
        ft_putstr("rb");
        ft_putchar('\n');
    }
}

void print_rr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        rotate(stack_a);
        rotate(stack_b);
        ft_putstr("rr");
        ft_putchar('\n');
    }
}

void print_rra(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        reverse_rotate(stack_a);
        ft_putstr("rra");
        ft_putchar('\n');
    }
}

void print_rrb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        reverse_rotate(stack_b);
        ft_putstr("rrb");
        ft_putchar('\n');
    }
}

void print_rrr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        ft_putstr("rrr");
        ft_putchar('\n');
    }
}

void	swap(t_stack *stack)
{
	int temp = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = temp;
}

void	push(t_stack *src, t_stack *dst)
{
	if (src->top >= 0)
	{
		dst->numbers[++dst->top] = src->numbers[src->top--];
	}
}

void	rotate(t_stack *stack)
{
	if (stack->top >= 0)
	{
		int first = stack->numbers[stack->top];
		int i = stack->top;
		while (i > 0) {
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
		stack->numbers[0] = first;
	}
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->top >= 0)
	{
		int last = stack->numbers[0];
		int i = 0;
		while (i < stack->top) {
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
		stack->numbers[stack->top] = last;
	}
}
