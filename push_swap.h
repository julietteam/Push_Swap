/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:10:04 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/26 22:03:04 by julietteand      ###   ########.fr       */
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

typedef struct 
{
        long long *stack;
        int size;
} Stack;

#define STACK_SIZE 100

Stack *create_stack(int size);
void push(Stack *stack, long long number);
void destroy_stack(Stack *stack);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void my_radixsort(int arr[], int n);
void print_stack(Stack *stack);
void push_swap(Stack *stack_a, Stack *stack_b);
int find_min_index(Stack *stack_a, int size_a);
//int find_max_index(Stack *stack_b, int size_b);
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
int is_sorted(Stack *stack);
void selection_sort(Stack* stack_a, Stack* stack_b);


#endif
