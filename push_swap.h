/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:10:04 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/14 14:59:28 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stack;

void	swap(char *str, int *array, int size);
void	push_pa(t_stack *stack);
void	push_pb(t_stack *stack);
void	rotate(int *array, int size, char *direction, char *list);
void	sort_three_elements(t_stack *stack);
void	sort_four_to_five_elements(t_stack *stack);
void	push_lowest_values(t_stack *stack);
void	rotate_middle_values(t_stack *stack);
int		is_array_sorted(t_stack *stack);
void	radix_sort(t_stack *stack);
void	free_and_exit_with_message(t_stack *stack, char *msg);
void	exit_if_sorted_or_has_duplicate(t_stack *stack, int i);
void	parse_numbers(t_stack *stack);
void	create_index(t_stack *stack);
void	initialize_stacks(int argc, char **argv, t_stack *stack);
int		ft_count_words(char const *s, char c);
int		is_valid_integer(const char *str, long long *result);
int		ft_atoi_check_overflow(const char *str, long long *result);

#endif