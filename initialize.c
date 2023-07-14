/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:04:42 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/14 14:06:47 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
			i++;
		}
		else
			i++;
	}
	return (word);
}

void	initialize_stacks(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	stack->a_size = 0;
	stack->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			stack->a_size += ft_count_words(argv[i + 1], ' ');
		else
			stack->a_size++;
		i++;
	}
	stack->stack_a = malloc(stack->a_size * sizeof * stack->stack_a);
	if (stack->stack_a == NULL)
		free_and_exit_with_message(stack, "Error\n");
	stack->stack_b = malloc(stack->a_size * sizeof * stack->stack_b);
	if (stack->stack_b == NULL)
		free_and_exit_with_message(stack, "Error\n");
}

void	create_index(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(stack->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_message(stack, "Error\n");
	i = -1;
	while (++i < stack->a_size)
	{
		k = 0;
		j = -1;
		while (++j < stack->a_size)
			if (stack->stack_a[i] > stack->stack_a[j])
				k++;
	new_a[i] = k;
	}
	i = stack->a_size;
	while (i--)
		stack->stack_a[i] = new_a[i];
	free(new_a);
}
