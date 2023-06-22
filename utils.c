/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:48:37 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/22 16:12:36 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


Stack *create_stack(int size)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->stack = malloc(size * sizeof(int));
    stack->size = 0;
    return stack;
}
void destroy_stack(Stack *stack) 
{
    free(stack->stack);
    free(stack);
}

