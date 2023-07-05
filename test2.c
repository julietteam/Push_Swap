/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:24:15 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/03 11:58:54 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct s_stack
{
    int *numbers;
    int top;
} t_stack;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
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


void	push(t_stack *source, t_stack *destination)
{
	if (source->top >= 0)
	{
		destination->top++;
		destination->numbers[destination->top] = source->numbers[source->top];
		source->top--;
	}
}

void	rotate(t_stack *stack)
{
	if (stack->top > 0)
	{
		int	first_element = stack->numbers[0];
		for (int i = 0; i < stack->top; i++)
			stack->numbers[i] = stack->numbers[i + 1];
		stack->numbers[stack->top] = first_element;
	}
}

void	print_instructions(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top >= 0)
	{
		printf("pa\n");
		push(stack_a, stack_b);
	}
}

int		get_max_value(int *array, int size)
{
	int max_value = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	return max_value;
}

int		get_num_digits(int number)
{
	int num_digits = 0;
	while (number > 0)
	{
		number /= 10;
		num_digits++;
	}
	return num_digits;
}

bool	is_sorted(t_stack *stack)
{
	for (int i = 0; i < stack->top; i++)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return false;
	}
	return true;
}

bool	check_duplicates(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
				return true;
		}
	}
	return false;
}

int		ft_atoi(const char *str)
{
	int	result = 0;
	int	sign = 1;
	int	i = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			return 0;
		}
	}
	return result * sign;
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_value = get_max_value(stack_a->numbers, stack_a->top + 1);
	int	max_digits = get_num_digits(max_value);
	int	divisor = 1;

	for (int i = 0; i < max_digits; i++)
	{
		for (int j = 0; j <= stack_a->top; j++)
		{
			if ((stack_a->numbers[j] / divisor) % 10 == i)
			{
				push(stack_a, stack_b);
				printf("pb\n");
			}
			else
			{
				rotate(stack_a);
				printf("ra\n");
			}
		}

		while (stack_b->top >= 0)
		{
			push(stack_b, stack_a);
			printf("pa\n");
		}

		divisor *= 10;
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error: Not enough arguments.\n");
		return 1;
	}

	int	size = argc - 1;
	int	*numbers = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
	}

	if (check_duplicates(numbers, size))
	{
		printf("Error: Duplicate numbers are not allowed.\n");
		free(numbers);
		return 1;
	}

	t_stack stack_a;
	stack_a.numbers = numbers;
	stack_a.top = size - 1;

	t_stack stack_b;
	stack_b.numbers = (int *)malloc(sizeof(int) * size);
	stack_b.top = -1;

	radix_sort(&stack_a, &stack_b);

	if (is_sorted(&stack_a) && stack_b.top == -1)
		print_instructions(&stack_a, &stack_b);
	else
		printf("Error: Sorting failed.\n");

	free(numbers);
	free(stack_b.numbers);

	return 0;
}
