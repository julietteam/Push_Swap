/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:10:04 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/05 22:42:02 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define MAX_NUMBERS 1000 // Remplacez la valeur 1000 par la taille maximale souhaitée
#define MAX_OPERATIONS 1000 // Remplacez la valeur 1000 par la taille maximale souhaitée
# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef enum {
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	SA,
	SB,
	SS,
	PA,
	PB,
} t_operation;

typedef struct s_stack {
    long long int numbers[MAX_NUMBERS];
    int start;
    int end;
    int top;
    char **operations;
    int op_index;
} t_stack;




void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
int		get_max_value(long long int *array, int start, int end);
long long int		get_num_digits(long long int number);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
long long int		check_duplicates(long long int *numbers, int count);
void	ft_putnbr(long long int n);
int		is_valid_number_and_no_overflow(char *str);
void print_sa(t_stack *stack_a);
void print_sb(t_stack *stack_b);
void print_ss(t_stack *stack_a, t_stack *stack_b);
void print_pa(t_stack *stack_a, t_stack *stack_b);
void print_pb(t_stack *stack_a, t_stack *stack_b);
void print_ra(t_stack *stack_a);
void print_rb(t_stack *stack_b);
void print_rr(t_stack *stack_a, t_stack *stack_b);
void print_rra(t_stack *stack_a);
void print_rrb(t_stack *stack_b);
void print_rrr(t_stack *stack_a, t_stack *stack_b);
int find_smallest_index(t_stack *stack);
void print_operations(t_stack *stack_a);
void push_swap_sort(t_stack *stack_a, t_stack *stack_b);
void initialize_stack(t_stack *stack);
void destroy_stack(t_stack *stack);
void initialize_operations(t_stack *stack);
void print_stack(t_stack *stack_a, t_stack *stack_b);


#endif