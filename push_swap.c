/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:30:36 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/10 20:02:41 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int is_sorted(t_stack *stack)
{
    if (stack->top >= 0)
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

void print_stack_state(t_stack *stack_a, t_stack *stack_b) {
    printf("Stack A: ");
    for (int i = 0; i <= stack_a->top; i++)
        printf("%lld ", stack_a->numbers[i]);
    printf("\n");

    printf("Stack B: ");
    for (int i = 0; i <= stack_b->top; i++)
        printf("%lld ", stack_b->numbers[i]);
    printf("\n");
}
/*
void print_operation(char *operation) 
{
    if (operation != NULL)
        printf("%s\n", operation);
}
*/
void print_operation(t_stack *stack) {
    printf("Operations: ");
    for (int i = stack->op_index - 1; i >= 0; i--) {
        printf("%s ", stack->operations[i]);
    }
    printf("\n");
}




/*
void push_swap_sort(t_stack *stack_a, t_stack *stack_b) {
    initialize_operations(stack_a);
    
    if (is_sorted(stack_a)) {
        // La pile A est déjà triée, il n'y a pas besoin de faire des opérations de tri
        return;
    }

    // Trier la pile A en utilisant le tri radix
    radix_sort(stack_a, stack_b);
    print_stack_state(stack_a, stack_b);
    while (!is_sorted(stack_a)) {
        int smallest_index = find_smallest_index(stack_a);

        if (smallest_index <= stack_a->top / 2) {
            while (smallest_index--) {
                print_ra(stack_a);
                print_stack_state(stack_a, stack_b);
            }
        } else {
            while (smallest_index++ < stack_a->top) {
                print_rra(stack_a);
                print_stack_state(stack_a, stack_b);
            }
        }

        print_pb(stack_a, stack_b);
        print_stack_state(stack_a, stack_b);
    }

    while (stack_b->top >= 0) {
        print_pa(stack_a, stack_b);
        print_stack_state(stack_a, stack_b);
    }
}
*/

void push_swap_sort(t_stack *stack_a, t_stack *stack_b) 
{
    //printf("Start push_swap_sort\n");
    if (is_sorted(stack_a)) 
    {
        printf("Pile already sorted\n");
        return;
    }

    int capacity = stack_a->top + 1;
    int *temp_array = malloc(capacity * sizeof(int));
    initialize_stack(stack_b, capacity);
    initialize_operations(stack_a);
    radix_sort(stack_a, stack_b);
    //printf("Operations:\n");
    print_operation_array(stack_a);


    
    free(temp_array);
    destroy_stack(stack_b);
    //printf("End push_swap_sort\n");  // Fin de la fonction
}



int main(int argc, char *argv[]) {
    t_stack stack_a;
    t_stack stack_b;
    int capacity = argc - 1;
    //int numbers_count;
    initialize_stack(&stack_a, capacity);
    initialize_stack(&stack_b, capacity);

    if (argc < 2) 
    {
        return 0;
    }
    // Concaténer les arguments entre guillemets en un seul argument
    char *concatenated_args = ft_calloc(MAX_ARGUMENT_LENGTH, sizeof(char));
    for (int i = 1; i < argc; i++) {
        ft_strlcat(concatenated_args, argv[i], MAX_ARGUMENT_LENGTH);
        if (i != argc - 1) {
            ft_strlcat(concatenated_args, " ", MAX_ARGUMENT_LENGTH);
        }
    }

    // Diviser l'argument concaténé en tokens individuels
    char **tokens = ft_split(concatenated_args, ' ');

    // Parcourir les tokens et les ajouter à stack_a
    int i = 0;
    while (tokens[i]) {
        if (!is_valid_number_and_no_overflow(tokens[i])) {
            ft_putstr("Error\n");
            return 1;
        }
        stack_a.numbers[++stack_a.top] = ft_atoi(tokens[i]);
        i++;
    }

    // Libérer la mémoire allouée pour les tokens
    free(tokens);

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

    destroy_stack(&stack_a);
    destroy_stack(&stack_b);

    //free(numbers);

    return 0;
}


/*
int main(int argc, char* argv[])
{
    int capacity = argc - 1;
    t_stack stack_a;
    t_stack stack_b;
    int numbers_count;
    initialize_stack(&stack_a, capacity);
    initialize_stack(&stack_b, capacity);

    if (argc < 2)
    {
        return 0;
    }
    long long int* numbers = parse_numbers(argv, argc, &stack_a);
    if (numbers == NULL)
    {
        ft_putstr("Error parsing numbers\n");
        return 1;
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
    if (count > MAX_NUMBERS)
    {
        printf("Too many numbers. Maximum is %d\n", MAX_NUMBERS);
        return 0;
    }
    long long int* numbers = malloc(count * sizeof(long long int));
    int i = 0;
    while (i < count)
    {
        numbers[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    if (check_duplicates(numbers, count))
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

    destroy_stack(&stack_a);
    destroy_stack(&stack_b);

    free(numbers);

    return 0;
}
*/
/*
void push_swap_sort(t_stack *stack_a, t_stack *stack_b) {
    if (is_sorted(stack_a)) {
        printf("Pile already sorted\n");
        return;
    }

    int capacity = stack_a->top + 1;
    int *temp_array = malloc(capacity * sizeof(int));
    initialize_stack(stack_b, capacity);

    radix_sort(stack_a, stack_b);

    char *operations = malloc(1);
    operations[0] = '\0';

    bool sorted = is_sorted(stack_a);
    while (!sorted && !is_sorted(stack_a)) {
        int smallest_index = find_smallest_index(stack_a);

        if (smallest_index <= stack_a->top / 2) {
            while (smallest_index--) {
                char *operation = "ra\n";
                char *new_operations = malloc(MAX_OPERATIONS);
                strlcpy(new_operations, operations, MAX_OPERATIONS);
                strlcat(new_operations, operation, MAX_OPERATIONS);
                free(operations);
                operations = new_operations;
            }
        } else {
            while (smallest_index++ < stack_a->top) {
                char *operation = "rra\n";
                char *new_operations = malloc(MAX_OPERATIONS);
                strlcpy(new_operations, operations, MAX_OPERATIONS);
                strlcat(new_operations, operation, MAX_OPERATIONS);
                free(operations);
                operations = new_operations;
            }
        }

        char *operation = "pb\n";
        char *new_operations = malloc(MAX_OPERATIONS);
        strlcpy(new_operations, operations, MAX_OPERATIONS);
        strlcat(new_operations, operation, MAX_OPERATIONS);
        free(operations);
        operations = new_operations;

        sorted = is_sorted(stack_a);
    }

    printf("%s", operations);

    free(operations);
    free(temp_array);
    destroy_stack(stack_b);
}





int main(int argc, char *argv[]) {
    int capacity = argc - 1;
    t_stack stack_a;
    t_stack stack_b;
    int numbers_count;
    Operation* operations = NULL; 
    initialize_stack(&stack_a, capacity);
    initialize_stack(&stack_b, capacity);
    
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
    //print_stack(&stack_a, &stack_b);
    print_operations(&stack_a);

    destroy_stack(&stack_a);
    destroy_stack(&stack_b);

    free(numbers);

    return 0;
}

*/