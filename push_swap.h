/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:10:04 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/22 17:47:15 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <stdbool.h>

typedef struct 
{
        int *stack;
        int size;
} Stack;

Stack *create_stack(int size);
void push(Stack *stack, int value);
void destroy_stack(Stack *stack);
void perform_pa(Stack *stack_a, Stack *stack_b);
void perform_rra(Stack *stack_a);
void perform_rrb(Stack *stack_b);
void perform_rrr(Stack *stack_a, Stack *stack_b);
void perform_ra(Stack *stack_a);
void perform_rb(Stack *stack_b);
void perform_rr(Stack *stack_a, Stack *stack_b);
void perform_pb(Stack *stack_a, Stack *stack_b);
void perform_sa(Stack *stack_a);
void perform_sb(Stack *stack_b);
void perform_ss(Stack *stack_a, Stack *stack_b);
int should_perform_rra(Stack *stack_a, int value);
int should_perform_ra(Stack *stack_a, int value);
int find_min_index(Stack *stack);
void rotate_to_index(Stack *stack, int index);
int find_max_index(Stack *stack);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixsort(int arr[], int n);
void print_stack(Stack *stack);
void push_swap(Stack *stack_a, Stack *stack_b);
void sa(Stack *stack);
void sb(Stack *stack);
void ss(Stack *stack_a, Stack *stack_b);
void pa(Stack *src, Stack *dest);
void pb(Stack *src, Stack *dest);
void ra(Stack *stack);
void rb(Stack *stack);
void rr(Stack *stack_a, Stack *stack_b);
void rra(Stack *stack);
void rrb(Stack *stack);
void rrr(Stack *stack_a, Stack *stack_b);



#endif