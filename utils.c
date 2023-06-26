/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:48:37 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/26 18:17:34 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


Stack *create_stack(int size) {
    Stack *stack = malloc(sizeof(Stack));
    stack->stack = malloc(size * sizeof(long long));
    stack->size = 0;
    return stack;
}
void destroy_stack(Stack *stack) 
{
    free(stack->stack);
    free(stack);
}

