/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:10:04 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/10 22:35:43 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define MAX_NUMBERS 1000 // Remplacez la valeur 1000 par la taille maximale souhaitée
#define MAX_OPERATIONS 1000 // Remplacez la valeur 1000 par la taille maximale souhaitée
#define MAX_ARGUMENT_LENGTH 1000

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
/*
typedef struct s_stack {
    long long int numbers[MAX_NUMBERS];
    int start;
    int end;
    int top;
	int capacity;
    char **operations;
    int op_index;
    int size;
} t_stack;

typedef struct s_operation {
    char *operation;
    struct s_operation *next;
} t_operation;


typedef struct Operation
{
    char* name; // Nom de l'opération (ex: "sa", "pb", etc.)
    struct Operation* next; // Pointeur vers l'opération suivante
} Operation;
*/

//t_stack *init_stack(int size);
//int		get_max_value(long long int *array, int start, int end);
//long long int		get_num_digits(long long int number);
//void	radix_sort(t_stack *stack_a, t_stack *stack_b);
//int		is_sorted(t_stack *stack);
//long long int		check_duplicates(long long int *numbers, int count);
//void	ft_putnbr(long long int n);
//int		is_valid_number_and_no_overflow(char *str);
//void print_sa(t_stack *stack_a);
//void print_sb(t_stack *stack_b);
//void print_ss(t_stack *stack_a, t_stack *stack_b);
//void print_pa(t_stack *stack_a, t_stack *stack_b);
//void print_pb(t_stack *stack_a, t_stack *stack_b);
//void print_ra(t_stack *stack_a);
//void print_rb(t_stack *stack_b);
//void print_rr(t_stack *stack_a, t_stack *stack_b);
//void print_rra(t_stack *stack_a);
//void print_rrb(t_stack *stack_b);
//void print_rrr(t_stack *stack_a, t_stack *stack_b);
void	swap(char *str, int *array, int size);
void	push(char *str, t_stack *stack);
void	rotate(int *array, int size, char *direction, char *list);
//int find_smallest_index(t_stack *stack);
//void push_swap_sort(t_stack *stack_a, t_stack *stack_b);
//void initialize_stack(t_stack *stack, int capacity);
//void destroy_stack(t_stack *stack);
//void initialize_operations(t_stack *stack);
//void print_operation(char *operation);
//void print_operation(t_stack *stack);
//void print_stack_state(t_stack *stack_a, t_stack *stack_b);
//int get_min_value(long long int *numbers, int start, int end);
//int find_largest_index(t_stack *stack);
//void print_operation_array(t_stack *stack);
//void add_operation(t_stack *stack, char *op);
//void add_operation(t_stack *stack, char *operation);
//void free_operations(char **operations);
//void print_operation_array(t_stack *stack);
void	sort_three_elements(t_stack *stack);
void	sort_four_to_five_elements(t_stack *stack);
int	is_array_sorted(t_stack *stack);
static void	radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j)__attribute__((unused));
void	radix_sort(t_stack *stack);
void	free_and_exit_with_message(t_stack *stack, char *msg);
static void	validate_arguments(int argc, char **argv)__attribute__((unused));
static void	join_args(int argc, char **argv, t_stack *s)__attribute__((unused));
void	exit_if_sorted_or_has_duplicate(t_stack *stack, int i);
void	parse_numbers(t_stack *stack);
void	create_index(t_stack *stack);
int	ft_atol(const char *nptr, t_stack *stack);
void	initialize_stacks(int argc, char **argv, t_stack *stack);
int	ft_count_words(char const *s, char c);

#endif