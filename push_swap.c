/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:12:41 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/22 17:48:43 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(Stack *stack, int value) 
{
    // Vérifier si l'élément est déjà présent dans la pile
    int i = 0;
    int found = 0;
    while (i < stack->size) {
        if (stack->stack[i] == value) {
            // L'élément est un doublon, prendre une action appropriée
            found = 1;
            break;
        }
        i++;
    }

    if (found == 0) {
        // L'élément n'est pas un doublon, l'insérer dans la pile
        stack->stack[stack->size++] = value;
    }
}

void perform_rrb(Stack *stack_b)
{
    rrb(stack_b);
    printf("rrb\n");
}

void perform_rrr(Stack *stack_a, Stack *stack_b)
{
    rrr(stack_a, stack_b);
    printf("rrr\n");
}
void perform_rra(Stack *stack_a) {
    rra(stack_a);
    printf("rra\n");
}

void perform_ra(Stack *stack_a) {
    ra(stack_a);
    printf("ra\n");
}

void perform_rb(Stack *stack_b)
{
    rb(stack_b);
    printf("rb\n");
}

void perform_rr(Stack *stack_a, Stack *stack_b)
{
    rr(stack_a, stack_b);
    printf("rr\n");
}

void perform_pa(Stack *stack_a, Stack *stack_b) {
    pa(stack_a, stack_b);
    printf("pa\n");
}

void perform_pb(Stack *stack_a, Stack *stack_b) {
    pb(stack_a, stack_b);
    printf("pb\n");
}

void perform_sa(Stack *stack_a)
{
    sa(stack_a);
    printf("sa\n");
}

void perform_sb(Stack *stack_b) {
    sb(stack_b);
    printf("sb\n");
}

void perform_ss(Stack *stack_a, Stack *stack_b)
{
    ss(stack_a, stack_b);
    printf("ss\n");
}


int should_perform_rra(Stack *stack_a, int value)
{
    int max_index = find_max_index(stack_a);
    int current_index = find_index(stack_a, value);

    if (current_index > max_index / 2)
        return 1;
    else
        return 0;
}

int should_perform_ra(Stack *stack_a, int value)
{
    int max_index = find_max_index(stack_a);
    int current_index = find_index(stack_a, value);

    if (current_index <= max_index / 2)
        return 1;
    else
        return 0;
}

int find_min_index(Stack *stack_b) {
    int min = stack_b->stack[stack_b->size - 1];
    int min_index = stack_b->size - 1;
    int i = stack_b->size - 2;
    while (i >= 0) {
        if (stack_b->stack[i] < min) {
            min = stack_b->stack[i];
            min_index = i;
        }
        i--;
    }
    return min_index;
}

int find_max_index(Stack *stack_b) {
    int max = stack_b->stack[stack_b->size - 1];
    int max_index = stack_b->size - 1;
    int i = stack_b->size - 1;
    while (i >= 0) {
        if (stack_b->stack[i] > max) {
            max = stack_b->stack[i];
            max_index = i;
        }
        i--;
    }
    return max_index;
}

void rotate_to_index(Stack *stack, int index) {
    int i = 0;
    while (i < index) {
        rb(stack);
        printf("rb\n");
        i++;
    }
}

void push_swap(Stack *stack_a, Stack *stack_b) 
{
    int size = stack_a->size;
    int *arr = stack_a->stack;
    radixsort(arr, size);

    int i = size - 1;
    while (i >= 0) 
    {
        if (arr[i] == stack_a->stack[stack_a->size - 1])
        { 
            perform_pa(stack_a, stack_b);
            i--;
        }
        else
        {
            if (should_perform_rra(stack_a, i))
            {
                perform_rra(stack_a);
            }
            else if (should_perform_ra(stack_a, i))
            {
                perform_ra(stack_a);
            }
            else 
            {
                perform_pb(stack_a, stack_b);
                if (should_perform_sb(stack_b))
                {
                    perform_sb(stack_b);
                }
            }
        }
    }

    int min_index = find_min_index(stack_b);
    rotate_to_index(stack_b, min_index);
    perform_pa(stack_b, stack_a);

    int max_index = find_max_index(stack_b);
    rotate_to_index(stack_b, max_index);
    perform_pa(stack_b, stack_a);
}