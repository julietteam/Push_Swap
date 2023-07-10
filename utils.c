/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:48:37 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/10 23:26:44 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void	parse_numbers(t_stack *stack)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(stack->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		stack->stack_a[z++] = ft_atol(tmp[i++], stack);
		free(tmp[i - 1]);
	}
	free(tmp);
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

int	ft_atol(const char *nptr, t_stack *stack)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648)
			free_and_exit_with_message(stack, "Error\n");
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			free_and_exit_with_message(stack, "Error\n");
		res = res * 10 + (nptr[i++] - '0');
	}
	return ((int)(res * sign));
}

/*
t_stack *init_stack(int size)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (stack == NULL)
        return NULL;

    stack->operations = malloc(size * sizeof(char *));
    if (stack->operations == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->size = size;
    stack->op_index = 0;

    return stack;
}

void initialize_stack(t_stack *stack, int capacity) 
{
    stack->start = 0;
    stack->end = -1;
    stack->top = -1;
    stack->op_index = 0;
    stack->capacity = capacity;
    stack->operations = NULL;
    //  stack->operations = malloc(capacity * sizeof(int *));
    //for(int i = 0; i < capacity; i++) 
    //{
    //    stack->operations[i] = NULL;
    //}
}


void initialize_operations(t_stack *stack) {
    stack->operations = malloc(MAX_OPERATIONS * sizeof(char *));
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        stack->operations[i] = malloc(4 * sizeof(char));
        stack->operations[i][0] = '\0'; // Initialise chaque chaîne à une chaîne vide
        
    }
}

void destroy_stack(t_stack *stack) {
    if (stack->operations != NULL) {
        for (int i = 0; i < stack->op_index; i++) {
            free(stack->operations[i]);
            stack->operations[i] = NULL;  // Ajouté pour éviter double free
        }
        free(stack->operations);
        stack->operations = NULL;  // Ajouté pour éviter double free
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

int get_min_value(long long int *numbers, int start, int end) {
    int min_value = numbers[start];
    int i = start + 1;;

   while (i <= end) {
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
        i++;
    }

    return min_value;
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

int find_largest_index(t_stack *stack) {
    int index = 0;
    int largest = stack->numbers[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->numbers[i] > largest) {
            largest = stack->numbers[i];
            index = i;
        }
    }
    return index;
}


void print_operation_array(t_stack *stack)
{
    for (int i = 0; i < stack->op_index; i++)
    {
        char *operation = stack->operations[i];
        if (operation != NULL)
        {
            if (strcmp(operation, "sa") == 0)
            {
                printf("sa\n");
            }
            else if (strcmp(operation, "sb") == 0)
            {
                printf("sb\n");
            }
            else if (strcmp(operation, "ss") == 0)
            {
                printf("ss\n");
            }
            else if (strcmp(operation, "pa") == 0)
            {
                printf("pa\n");
            }
            else if (strcmp(operation, "pb") == 0)
            {
                printf("pb\n");
            }
            else if (strcmp(operation, "ra") == 0)
            {
                printf("ra\n");
            }
            else if (strcmp(operation, "rb") == 0)
            {
                printf("rb\n");
            }
            else if (strcmp(operation, "rr") == 0)
            {
                printf("rr\n");
            }
            else if (strcmp(operation, "rra") == 0)
            {
                printf("rra\n");
            }
            else if (strcmp(operation, "rrb") == 0)
            {
                printf("rrb\n");
            }
            else if (strcmp(operation, "rrr") == 0)
            {
                printf("rrr\n");
            }
            else
            {
                printf("Unknown operation\n");
            }
        }
    }
}



void add_operation(t_stack *stack, char *op)
{
    char *operation = malloc((strlen(op) + 1) * sizeof(char));
    strcpy(operation, op);
    stack->operations[stack->op_index] = operation;
    stack->op_index++;
}

void add_operation(t_stack *stack, char *operation) {
    // Allouer de la mémoire pour stocker l'opération
    char *new_operation = strdup(operation);

    // Mettre à jour le tableau d'opérations dans la structure t_stack
    stack->operations[stack->op_index] = new_operation;
    stack->op_index++;
}


// Fonction pour libérer la mémoire occupée par la liste d'opérations
void free_operations(char **operations)
{
    int i = 0;
    while (operations[i] != NULL) {
        free(operations[i]);
        i++;
    }
    free(operations);
}
*/