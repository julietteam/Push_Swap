/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:33:08 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/22 11:55:40 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(Stack *stack)
{
    if (stack->size < 2)
        return;

    int temp = stack->stack[0];
    stack->stack[0] = stack->stack[1];
    stack->stack[1] = temp;
}

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

void pa(Stack *src, Stack *dest)
{
    if (src->size <= 0)
        return;

    dest->stack[dest->size] = src->stack[src->size - 1];
    (dest->size)++;
    (src->size)--;
}

void pb(Stack *src, Stack *dest)
{
    if (src->size <= 0)
        return;

    dest->stack[dest->size] = src->stack[src->size - 1];
    (dest->size)++;
    (src->size)--;
}

void ra(Stack *stack)
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
