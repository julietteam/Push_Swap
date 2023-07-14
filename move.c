/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:28:53 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/14 14:36:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push_pa(t_stack *stack)
{
	int	tmp;

	if (stack->b_size <= 0)
		return ;
	tmp = stack->stack_b[0];
	ft_memmove(stack->stack_a + 1, stack->stack_a,
		sizeof(int) * stack->a_size);
	stack->stack_a[0] = tmp;
	stack->b_size--;
	ft_memmove(stack->stack_b, stack->stack_b + 1,
		sizeof(int) * stack->b_size);
	stack->a_size++;
	ft_putendl_fd("pa", 1);
}

void	push_pb(t_stack *stack)
{
	int	tmp;

	if (stack->a_size <= 0)
		return ;
	tmp = stack->stack_a[0];
	ft_memmove(stack->stack_b + 1, stack->stack_b,
		sizeof(int) * stack->b_size);
	stack->stack_b[0] = tmp;
	stack->a_size--;
	ft_memmove(stack->stack_a, stack->stack_a + 1,
		sizeof(int) * stack->a_size);
	stack->b_size++;
	ft_putendl_fd("pb", 1);
}

void	rotate(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
