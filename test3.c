/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:23:20 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/04 11:52:13 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
# include "Libft/libft.h"
# include "Libft/ft_printf.h"

typedef struct s_stack
{
    int *numbers;
    int top;
    int size;
} t_stack;

/*
typedef struct s_operations
{
    char *operation;
    struct s_operations *next;
} t_operations;
*/
void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    free(stack_a->numbers);
    free(stack_b->numbers);
}

int is_valid_arg(char *arg)
{
    if (!arg || !*arg)
        return 0;

    while (*arg)
    {
        if ((*arg == '-' || *arg == '+') && *(arg + 1) != '\0')
            arg++;
        if (!isdigit(*arg))
            return 0;
        arg++;
    }

    return 1;
}
/*
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
*/
void ft_putnbr(int n)
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

int init_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
    stack_a->numbers = (int *)malloc(sizeof(int) * size);
    if (!stack_a->numbers)
    {
        ft_putstr("Error: Memory allocation failed.\n");
        return (1);
    }
    stack_a->top = -1;
    stack_a->size = size;

    stack_b->numbers = (int *)malloc(sizeof(int) * size);
    if (!stack_b->numbers)
    {
        ft_putstr("Error: Memory allocation failed.\n");
        free(stack_a->numbers);
        return (1);
    }
    stack_b->top = -1;
    stack_b->size = size;

    return (0);
}
/*
void print_sort_operations(t_operations *operations)
{
    while (operations)
    {
        ft_putstr(operations->operation);
        ft_putchar('\n');
        operations = operations->next;
    }
}
*/
/*
void add_sort_operation(t_operations **operations, char *operation)
{
    t_operations *new_operation = (t_operations *)malloc(sizeof(t_operations));
    if (!new_operation)
    {
        ft_putstr("Error: Memory allocation failed.\n");
        return;
    }
    new_operation->operation = strdup(operation);
    new_operation->next = NULL;

    if (*operations == NULL)
    {
        *operations = new_operation;
    }
    else
    {
        t_operations *current = *operations;
        while (current->next)
            current = current->next;
        current->next = new_operation;
    }
}
*/
void swap(t_stack *stack)
{
    //add_sort_operation(operations, "sa");
    ft_putstr("sa\n");
    int temp = stack->numbers[stack->top];
    stack->numbers[stack->top] = stack->numbers[stack->top - 1];
    stack->numbers[stack->top - 1] = temp;
}

void push(t_stack *src, t_stack *dst)
{
    //add_sort_operation(operations, "pb");
    ft_putstr("pb\n");
    dst->numbers[++dst->top] = src->numbers[src->top--];
}

void rotate(t_stack *stack)
{
    //add_sort_operation(operations, "ra");
    ft_putstr("ra\n");
    int first = stack->numbers[stack->top];
    int i = stack->top;
    while (i > 0)
    {
        stack->numbers[i] = stack->numbers[i - 1];
        i--;
    }
    stack->numbers[0] = first;
}

void reverse_rotate(t_stack *stack)
{
    //add_sort_operation(operations, "rra");
    ft_putstr("rra\n");
    int last = stack->numbers[0];
    int i = 0;
    while (i < stack->top)
    {
        stack->numbers[i] = stack->numbers[i + 1];
        i++;
    }
    stack->numbers[stack->top] = last;
}

int is_sorted(t_stack *stack)
{
    int i = 0;
    while (i < stack->top)
    {
        if (stack->numbers[i] > stack->numbers[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int check_duplicates(int *numbers, int count)
{
    int i = 0;
    while (i < count - 1)
    {
        int j = i + 1;
        while (j < count)
        {
            if (numbers[i] == numbers[j])
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int get_max_value(int *array, int size)
{
    int max = array[0];
    int i = 1;
    while (i < size)
    {
        if (array[i] > max)
            max = array[i];
        i++;
    }
    return max;
}

int get_num_digits(int number)
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

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_value = get_max_value(stack_a->numbers, stack_a->top + 1);
    int num_digits = get_num_digits(max_value);
    int divisor = 1;

    int i = 0;
    while (i < num_digits)
    {
        // Réinitialiser les compteurs pour chaque itération de tri radix
        int count[10] = {0};

        // Compter le nombre d'éléments pour chaque chiffre
        int j = 0;
        while (j <= stack_a->top)
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
        int l = stack_a->top;
        while (l >= 0)
        {
            int digit = (stack_a->numbers[l] / divisor) % 10;
            stack_b->numbers[--count[digit]] = stack_a->numbers[l];

            // Afficher l'opération de tri
            if (stack_b->numbers[count[digit]] == stack_a->numbers[l])
            {
                ft_putstr("pb\n");
            }
            else
            {
                ft_putstr("ra\n");
            }

            l--;
        }

        // Copier les éléments triés de stack_b vers stack_a
        int m = 0;
        while (m <= stack_a->top)
        {
            stack_a->numbers[stack_a->top - m] = stack_b->numbers[m];
            m++;
        }

        divisor *= 10;
        i++;
    }
}

/*
void radix_sort(t_stack *stack_a, t_stack *stack_b, t_operations **operations)
{
    int max_value = get_max_value(stack_a->numbers, stack_a->top + 1);
    int num_digits = get_num_digits(max_value);
    int divisor = 1;

    int i = 0;
    while (i < num_digits)
    {
        // Réinitialiser les compteurs pour chaque itération de tri radix
        int count[10] = {0};

        // Compter le nombre d'éléments pour chaque chiffre
        int j = 0;
        while (j <= stack_a->top)
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
        int l = stack_a->top;
        
        while (l >= 0)
        {
            int digit = (stack_a->numbers[l] / divisor) % 10;
            stack_b->numbers[--count[digit]] = stack_a->numbers[l];
            l--;
        }
        */
       /*
         while (l >= 0)
        {
            int digit = (stack_a->numbers[l] / divisor) % 10;
            stack_b->numbers[--count[digit]] = stack_a->numbers[l];

            // Ajouter l'opération de tri à la liste
            if (stack_b->numbers[count[digit]] == stack_a->numbers[l])
            {
                char operation[4];
                sprintf(operation, "pb");
                add_sort_operation(operations, operation);
            }
            else
            {
                char operation[4];
                sprintf(operation, "ra");
                add_sort_operation(operations, operation);
            }

            l--;
        }
        // Copier les éléments triés de stack_b vers stack_a
        int m = 0;
        while (m <= stack_a->top)
        {
            stack_a->numbers[stack_a->top - m] = stack_b->numbers[m];
            m++;
        }
        divisor *= 10;
        i++;
    }
    print_sort_operations(*operations);
}
*/

void print_stack(t_stack *stack)
{
    int i;
    for (i = stack->top; i >= 0; i--)
    {
        ft_putnbr(stack->numbers[i]);
        ft_putchar(' ');
    }
    ft_putchar('\n');
}

int ft_atoi(const char *nptr)
{
    int result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;
    while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            sign = sign * (-1);
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10;
        result = result + (nptr[i] - 48);
        i++;
    }
    return (result * sign);
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    int i;

    if (argc < 2)
        return 0;
    if (init_stacks(&stack_a, &stack_b, argc - 1))
        return 1;
    i = 1;
    //t_operations *sort_operations = NULL;
    while (i < argc)
    {
        if (!is_valid_arg(argv[i]))
        {
            ft_putstr("Error: Invalid argument.\n");
            free_stacks(&stack_a, &stack_b);
            return 1;
        }
        stack_a.numbers[i - 1] = ft_atoi(argv[i]);
        stack_a.top++;
        i++;
    }
    if (check_duplicates(stack_a.numbers, stack_a.top + 1))
    {
        ft_putstr("Error: Duplicate numbers found.\n");
        free_stacks(&stack_a, &stack_b);
        return 1;
    }
    radix_sort(&stack_a, &stack_b);

    ft_putstr("Result: ");
    print_stack(&stack_a);
    free_stacks(&stack_a, &stack_b);

    return 0;
}
