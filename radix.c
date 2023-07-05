/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:49 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/05 22:42:35 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Libft/ft_printf.h"
#include "push_swap.h"


void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max_value = get_max_value(stack_a->numbers, stack_a->start, stack_a->end);
	int num_digits = get_num_digits(max_value);
	int divisor = 1;

	int i = 0;
    if (is_sorted(stack_a))
    return;

	while (i < num_digits)
	{
		// Réinitialiser les compteurs pour chaque itération de tri radix
		int count[10] = {0};

		// Compter le nombre d'éléments pour chaque chiffre dans la plage spécifiée
		int j = stack_a->start;
		while (j <= stack_a->end)
		{
			count[(stack_a->numbers[j] / divisor) % 10]++;
			j++;
		}

		// Calculer les positions finales pour chaque chiffre
		int k = 1;
		while (k < 10)
		{
			count[k] += count[k - 1];
			k++;
		}

		// Placer les éléments dans le bon ordre dans stack_b
		int l = stack_a->end;
		while (l >= stack_a->start)
		{
			int digit = (stack_a->numbers[l] / divisor) % 10;
			stack_b->numbers[--count[digit]] = stack_a->numbers[l];
			l--;
		}

		// Copier les éléments triés de stack_b vers stack_a en ordre croissant
        int m = stack_a->start;
		while (m <= stack_a->end)
		{
   			stack_a->numbers[m] = stack_b->numbers[m];
    		m++;
		}
		divisor *= 10;
		i++;
	}
}


