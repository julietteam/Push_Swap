/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:33:08 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/26 21:56:45 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void sb(Stack *stack)
{
    if (stack->size < 2)
        return;

    int temp = stack->stack[0];
    stack->stack[0] = stack->stack[1];
    stack->stack[1] = temp;
}

void ss(Stack *stack_a, Stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void rb(Stack *stack)
{
    if (stack->size <= 1)
        return;

    int temp = stack->stack[0];
    int i = 0;
    while (i < stack->size - 1)
    {
        stack->stack[i] = stack->stack[i + 1];
        i++;
    }
    stack->stack[stack->size - 1] = temp;
}

void rr(Stack *stack_a, Stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(Stack *stack)
{
    if (stack->size <= 1)
        return;

    int temp = stack->stack[stack->size - 1];
    int i = stack->size - 1;
    while (i > 0)
    {
        stack->stack[i] = stack->stack[i - 1];
        i--;
    }
    stack->stack[0] = temp;
}

void rrb(Stack *stack)
{
    if (stack->size <= 1)
        return;

    int temp = stack->stack[stack->size - 1];
    int i = stack->size - 1;
    while (i > 0)
    {
        stack->stack[i] = stack->stack[i - 1];
        i--;
    }
    stack->stack[0] = temp;
}

void rrr(Stack *stack_a, Stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}


int is_sorted(Stack *stack)
{
    int i = 0;
    while (i < stack->size - 1)
    {
        if (stack->stack[i] > stack->stack[i + 1])
            return 0;
        i++;
    }
    return 1;
}