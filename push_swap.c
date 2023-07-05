/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:30:36 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/05 22:41:00 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int is_sorted(t_stack *stack)
{
    if (stack->top > 0)
    {
        int i = 0;
        while (i < stack->top)
        {
            if (stack->numbers[i] > stack->numbers[i + 1])
                return 0;
            i++;
        }    
    }
    return 1; 
}

long long int check_duplicates(long long int *numbers,int count)
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

void print_stack(t_stack *stack_a, t_stack *stack_b) {
    t_stack sorted_stack;
    sorted_stack.top = -1;
    sorted_stack.start = 0;
    sorted_stack.end = stack_a->top;
    
    // Copier les nombres de la pile d'origine dans la pile triée
    for (int i = 0; i <= stack_a->top; i++) {
        sorted_stack.numbers[i] = stack_a->numbers[i];
        sorted_stack.top++;
    }
    
    // Trier la pile triée par ordre croissant
    radix_sort(&sorted_stack, stack_b);
    
    // Afficher la pile triée
    for (int i = 0; i <= sorted_stack.top; i++) {
        printf("%lld ", sorted_stack.numbers[i]);
    }
    printf("\n");
}




void print_operations(t_stack *stack) {
    for (int i = 0; i < stack->op_index; i++) {
        printf("%s\n", stack->operations[i]);
    }
}



void push_swap_sort(t_stack *stack_a, t_stack *stack_b) {
    initialize_operations(stack_a);
    
    while (!is_sorted(stack_a)) {
        int smallest_index = find_smallest_index(stack_a);
        
        if (smallest_index <= stack_a->top / 2) {
            while (smallest_index--) {
                rotate(stack_a);
                ft_strlcpy(stack_a->operations[stack_a->op_index], "ra", sizeof(stack_a->operations[stack_a->op_index]));
                stack_a->op_index++;
            }
        } else {
            while (smallest_index++ < stack_a->top) {
                reverse_rotate(stack_a);
                ft_strlcpy(stack_a->operations[stack_a->op_index], "rra", sizeof(stack_a->operations[stack_a->op_index]));
                stack_a->op_index++;
            }
        }
        
        push(stack_a, stack_b);
        ft_strlcpy(stack_a->operations[stack_a->op_index], "pb", sizeof(stack_a->operations[stack_a->op_index]));
        stack_a->op_index++;
    }
    
    while (stack_b->top >= 0) {
        push(stack_b, stack_a);
        ft_strlcpy(stack_a->operations[stack_a->op_index], "pa", sizeof(stack_a->operations[stack_a->op_index]));
        stack_a->op_index++;
    }
}


int main(int argc, char *argv[]) {
    t_stack stack_a;
    t_stack stack_b;
    int numbers_count;

    initialize_stack(&stack_a);
    initialize_stack(&stack_b);

    if (argc < 2) 
    {
        return 0;
    }
    numbers_count = 1;
    stack_a.top = -1;
    stack_b.top = -1;
    while (numbers_count < argc)
    {
        if (!is_valid_number_and_no_overflow(argv[numbers_count]))
        {
            ft_putstr("Error\n");
            return 1;
        }
        stack_a.numbers[++stack_a.top] = ft_atoi(argv[numbers_count]);
        numbers_count++;
    }
    int count = argc - 1;
    if (count > MAX_NUMBERS) {
        printf("Too many numbers. Maximum is %d\n", MAX_NUMBERS);
        return 0;
    }
    long long int *numbers = malloc(count * sizeof(long long int));
    int i = 0;
    while ( i < count) 
    {
        numbers[i] = ft_atoi(argv[i + 1]);
        i++;
    }
   if (check_duplicates(stack_a.numbers, stack_a.top + 1))
    {
        ft_putstr("Error\n");
        return 1;
    }
     if (is_sorted(&stack_a))
    {
        // Les valeurs sont déjà triées, afficher le message approprié
        ft_putstr("Pile already sorted\n");
        return 1;
    }
    push_swap_sort(&stack_a, &stack_b);

    //printf("Result:\n");
    print_stack(&stack_a, &stack_b);
    print_operations(&stack_a);

    destroy_stack(&stack_a);
    destroy_stack(&stack_b);

    free(numbers);

    return 0;
}

