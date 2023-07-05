/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:48:37 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/05 22:14:57 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initialize_stack(t_stack *stack) {
    stack->start = 0;
    stack->end = 0;
    stack->top = -1;
    stack->operations = NULL;
    stack->op_index = 0;
}

void destroy_stack(t_stack *stack) {
    if (stack->operations != NULL) {
        for (int i = 0; i < stack->op_index; i++) {
            free(stack->operations[i]);
        }
        free(stack->operations);
    }
}

void initialize_operations(t_stack *stack) {
    stack->operations = malloc(MAX_OPERATIONS * sizeof(char *));
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        stack->operations[i] = malloc(4 * sizeof(char));
    }
}


int		get_max_value(long long int *array, int start, int end)
{
	int max = array[start];
	int i = start + 1;
	while (i <= end)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return max;
}

int get_min_value(long long int *array, int start, int end)
{
    int min = array[start];
    int i = start + 1;
    while (i <= end)
    {
        if (array[i] < min)
            min = array[i];
        i++;
    }
    return min;
}


long long int		get_num_digits(long long int number)
{
	int count = 0;
	if (number == 0)
		return 1;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return count;
}

void ft_putnbr(long long int n)
{
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }

    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
    {
        ft_putchar(n + '0');
    }
}


int		is_valid_number_and_no_overflow(char *str)
{
	int i;
	long long num;
	int sign;

	i = 0;
	sign = 1;
	num = 0;

	// si le nombre est négatif, on ignore le signe moins
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		// si le caractère n'est pas un chiffre, retourner 0 (faux)
		if (!ft_isdigit(str[i]))
			return (0);
		// check if num will be out of range when left-shifted
		if ((num > LLONG_MAX / 10) || ((num == LLONG_MAX / 10) && (str[i] - '0') > (LLONG_MAX % 10)))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}

	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int find_smallest_index(t_stack *stack) {
    int index = 0;
    int smallest = stack->numbers[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->numbers[i] < smallest) {
            smallest = stack->numbers[i];
            index = i;
        }
    }
    return index;
}

