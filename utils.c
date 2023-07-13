/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:48:37 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/13 17:21:46 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_array_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
        if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	exit_if_sorted_or_has_duplicate(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stack->a_size)
		{
			j = i + 1;
			while (j < stack->a_size)
			{
				if (stack->stack_a[i] == stack->stack_a[j])
					free_and_exit_with_message(stack, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(stack))
		free_and_exit_with_message(stack, NULL);
		
}


int is_valid_integer(const char *str, long long *result)
{
    int sign = 1;
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]))
            return (0);
        else if (str[i] != ' ')
            return 1;
        i++;
    }
    if ((!&ft_isdigit) || (i > 1 && (str[0] == '-' || str[0] == '+') && !(str[1] >= '0' && str[1] <= '9')))
        return 1;
    *result = sign * ft_atoi_check_overflow(str, result);
    if ((sign == -1 && (*result < INT_MIN || *result > 0)) || (sign == 1 && (*result > INT_MAX || *result < 0)))
        return 1;
    return 0;
}


int ft_atoi_check_overflow(const char *str, long long *result)
{
    long long r = 0;
    int sign = 1;
    int i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (r > LLONG_MAX / 10 || (r == LLONG_MAX / 10 && (str[i] - '0') > LLONG_MAX % 10))
            return (*result = 0), 1;
        r = r * 10 + (str[i] - '0');
        i++;
    }
    *result = r * sign;
    if (*result > INT_MAX || *result < INT_MIN)
        return (*result = 0), 1;
    return 0;
}


void parse_numbers(t_stack *stack)
{
    char **tmp = ft_split(stack->join_args, ' ');
    int i;
    int z;
    z = 0;
    i = 0;
    while (tmp[i] != NULL && tmp[i][0] != '\0')
    {
        long long num;
        if (ft_atoi_check_overflow(tmp[i], &num) == 0)
            stack->stack_a[z++] = (int)num;
        else
        {
            printf("Error\n");
            free(stack->stack_a);
            free(tmp[i]);
            free(tmp);
            exit(1);
        }
        free(tmp[i]);
        i++;
    }
    free(tmp);
    stack->a_size = z;
}

int	ft_count_words(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
				i++;
	}
	return (word);
}


void	initialize_stacks(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	stack->a_size = 0;
	stack->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			stack->a_size += ft_count_words(argv[i + 1], ' ');
		else
			stack->a_size++;
		i++;
	}
	stack->stack_a = malloc(stack->a_size * sizeof * stack->stack_a);
	if (stack->stack_a == NULL)
		free_and_exit_with_message(stack, "Error\n");
	stack->stack_b = malloc(stack->a_size * sizeof * stack->stack_b);
	if (stack->stack_b == NULL)
		free_and_exit_with_message(stack, "Error\n");
}

void	create_index(t_stack *stack)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(stack->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_message(stack, "Error\n");
	i = -1;
	while (++i < stack->a_size)
	{
		k = 0;
		j = -1;
		while (++j < stack->a_size)
			if (stack->stack_a[i] > stack->stack_a[j])
				k++;
		new_a[i] = k;
	}
	i = stack->a_size;
	while (i--)
		stack->stack_a[i] = new_a[i];
	free(new_a);
}

