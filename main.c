/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:21:58 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/13 16:42:35 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit_with_message(t_stack *stack, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (stack != NULL)
	{
		if (stack->stack_a != NULL)
			free(stack->stack_a);
		if (stack->stack_b != NULL)
			free(stack->stack_b);
		if (stack->join_args != NULL)
			free(stack->join_args);
		if (stack != NULL)
			free(stack);
	}
	exit(1);
}


static void validate_arguments(int argc, char **argv)
{
    int i, j;
    i = 0;
    if (argc < 2)
        free_and_exit_with_message(NULL, "");
    while (++i < argc)
    {
        j = 0;
        if (argv[i][0] == '\0')
            free_and_exit_with_message(NULL, "Error\n");
        while (argv[i][j] != '\0')
        {
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ') && (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
                free_and_exit_with_message(NULL, "Error\n");
			j++;
        }
		long long num;
        if (is_valid_integer(argv[i], &num) != 0)
          free_and_exit_with_message(NULL, "Error\n");
    }
}


static void	join_args(int argc, char **argv, t_stack *stack)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	stack->join_args = ft_strdup(tmp);
	if (stack->join_args == NULL)
		free_and_exit_with_message(stack, "Error\n");
	if (tmp)
		free(tmp);
}



int	main(int argc, char **argv)
{
	t_stack	*stack;

	validate_arguments(argc, argv);
	stack = malloc(sizeof * stack);
	if (stack == NULL)
		exit(1);
	initialize_stacks(argc, argv, stack);
	join_args(argc, argv, stack);
	parse_numbers(stack);
	exit_if_sorted_or_has_duplicate(stack, 0);
	create_index(stack);
	if (stack->a_size == 2 && stack->stack_a[0] > stack->stack_a[1])
		swap("sa", stack->stack_a, stack->a_size);
	else if (stack->a_size == 3)
		sort_three_elements(stack);
	else if (stack->a_size >= 4 && stack->a_size <= 5)
		sort_four_to_five_elements(stack);
	else
        radix_sort(stack);
	exit_if_sorted_or_has_duplicate(stack, 1);
	free_and_exit_with_message(stack, "Error\n");
	return (0);
}
