/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:49 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/12 18:13:28 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Libft/ft_printf.h"
#include "push_swap.h"



void	sort_three_elements(t_stack *stack)
{
    // Si le troisième élément du tableau n'est pas 2
	if (stack->stack_a[2] != 2)
	{
        // Si le premier élément est 2, on le déplace vers le haut
		if (stack->stack_a[0] == 2)
			rotate(stack->stack_a, stack->a_size, "up", "a");
		else
        // Sinon, on le déplace vers le bas
			rotate(stack->stack_a, stack->a_size, "down", "a");
	}
    // Si le premier élément est plus grand que le deuxième élément, on les échange
	if (stack->stack_a[0] > stack->stack_a[1])
		swap("sa", stack->stack_a, stack->a_size);
}

void sort_four_to_five_elements(t_stack *stack)
{
    while (stack->b_size <= 1)
    {
        if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
            push("pb", stack);
        else
            rotate(stack->stack_a, stack->a_size, "up", "a");
    }

    if (stack->stack_b[0] == 0)
        swap("sb", stack->stack_b, stack->b_size);

    if (stack->a_size == 5)
    {
        if (stack->stack_a[2] != 4 && stack->stack_a[2] != 5)
        {
            if (stack->stack_a[0] == 4 || stack->stack_a[0] == 5)
                rotate(stack->stack_a, stack->a_size, "up", "a");
            else
                rotate(stack->stack_a, stack->a_size, "down", "a");
        }
    }
    else if (stack->stack_a[2] != 4)
    {
        if (stack->stack_a[0] == 4)
            rotate(stack->stack_a, stack->a_size, "up", "a");
        else
            rotate(stack->stack_a, stack->a_size, "down", "a");
    }

    if (stack->stack_a[0] > stack->stack_a[1])
        swap("sa", stack->stack_a, stack->a_size);

    push("pa", stack);
    push("pa", stack);
}


int	is_array_sorted(t_stack *stack)
{
	int	i;

	i = 0;
    // On parcourt les éléments du tableau a de gauche à droite
	while (i < stack->a_size - 1)
	{
		// Si un élément est plus grand que l'élément suivant, le tableau n'est pas trié
        if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
    // Si on a parcouru tous les éléments sans trouver d'erreur, il est trié 
	return (1);
}

static void	radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j)
{
	// Tant que la taille du tableau b est supérieure à 0, que j est inférieur ou égal à bit_size et que le tableau a n'est pas trié
    while (b_size-- && j <= bit_size && !is_array_sorted(stack))
	{
		// Si le bit j de l'élément du tableau b est 0, on le déplace vers le haut
        if (((stack->stack_b[0] >> j) & 1) == 0)
			rotate(stack->stack_b, stack->b_size, "up", "b");
        // Sinon, on pousse l'élément du tableau b vers le tableau a
		else
			push("pa", stack);
	}
    // Si le tableau a est trié, on pousse tous les éléments du tableau b vers le tableau a
	if (is_array_sorted(stack))
		while (stack->b_size != 0)
			push("pa", stack);
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->a_size;
    // tant que la taille du tableau size est supérieure à 1 
	while (size > 1 && ++bit_size)
    // On divise par 2. Ca permet de réduire la taille jusqu'à ce qu'il ne reste plus qu'un seul bit.
		size /= 2;
        //size = stack->a_size;
	i = -1;
    // Tant i est inférieur ou égale à bit_size
	while (++i <= bit_size)
	{
		// on adapte size à la taille du tableau à trier
        size = stack->a_size;
        //tant que le tableau n'est pas encore trié et que size est supérieur ou égal à 0
		while (size-- && !is_array_sorted(stack))
		{
            // si le bit à la position i du premier nombre du tableau stack_a est égal à 0.
			if (((stack->stack_a[0] >> i) & 1) == 0)
				push("pb", stack);
            //Sinon, si le bit est 1, rotation du tableau stack_a vers le haut
			else
				rotate(stack->stack_a, stack->a_size, "up", "a");
		}
		radix_sort_stack_b(stack, stack->b_size, bit_size, i + 1);
	}
    // Tant que la taille du tableau b est différente de 0
	while (stack->b_size != 0)
		push("pa", stack);
}

