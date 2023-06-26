/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:12:41 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/26 22:01:06 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(Stack* stack, long long number) {
    if (number > 0) {
        // Vérifier si le nombre positif est déjà présent
        int isDuplicate = 0;
        int i = 0;
        
        // Parcourir la pile pour vérifier les doublons
        while (i < stack->size) {
            if (stack->stack[i] == number) {
                isDuplicate = 1;
                break;
            }
            i++;
        }
        
        // Si le nombre est un doublon, afficher un message d'erreur
        if (isDuplicate) {
            ft_printf("Error: Duplicate number\n");
            exit(1);
        }
        
        // Ajouter le nombre à la pile
        stack->stack[stack->size] = number;
        stack->size++;
    }
}

void sa(Stack* stack) {
    if (stack->size < 2)
        return;

    int temp = stack->stack[0];
    stack->stack[0] = stack->stack[1];
    stack->stack[1] = temp;
    ft_printf("sa\n");
}

void ra(Stack* stack) {
    if (stack->size <= 1)
        return;

    int temp = stack->stack[0];
    for (int i = 1; i < stack->size; i++) {
        stack->stack[i - 1] = stack->stack[i];
    }
    stack->stack[stack->size - 1] = temp;
    printf("ra\n");
}

void pb(Stack* src, Stack* dest) {
    if (src->size <= 0)
        return;

    dest->stack[dest->size] = src->stack[src->size - 1];
    (dest->size)++;
    (src->size)--;
    ft_printf("pb\n");
}

void pa(Stack* dest, Stack* src) {
    if (src->size <= 0)
        return;

    dest->stack[dest->size] = src->stack[src->size - 1];
    (dest->size)++;
    (src->size)--;
    ft_printf("pa\n");
}

void selection_sort(Stack* stack_a, Stack* stack_b) {
    int size = stack_a->size;
    while (size > 0) {
        int min_index = find_min_index(stack_a, size);

        // Si l'élément minimum est proche du sommet, effectuer une rotation vers le haut
        if (min_index <= size / 2) {
            while (min_index > 0) {
                ra(stack_a);
                min_index--;
            }
        }
        // Sinon, effectuer une rotation vers le bas
        else {
            min_index = size - min_index;
            while (min_index > 0) {
                rra(stack_a);
                min_index--;
            }
        }

        pb(stack_a, stack_b);
        size--;
    }
}

void push_swap(Stack* stack_a, Stack* stack_b) {
    int size = stack_a->size;
    while (size > 0) {
        int min_index = 0;
        int min_value = stack_a->stack[0];

        // Trouver l'élément minimum dans stack_a
        int i = 1;
        while (i < size) {
            if (stack_a->stack[i] < min_value) {
                min_value = stack_a->stack[i];
                min_index = i;
            }
            i++;
        }

        // Déplacer l'élément minimum de stack_a vers stack_b
        int j = min_index;
        while (j < stack_a->size - 1) {
            pb(stack_a, stack_b);
            if (j == 0)
                j = stack_a->size - 1;
            else
                j--;
        }
        pb(stack_a, stack_b);
        size--;
    }

    // Remettre les éléments de stack_b dans stack_a dans l'ordre décroissant
    while (stack_b->size > 0) {
        pa(stack_a, stack_b);
        if (stack_a->size >= 2 && stack_a->stack[0] > stack_a->stack[1])
            sa(stack_a);
    }
}

int find_min_index(Stack* stack_a, int size_a) {
    int min_index = 0;
    int min_value = stack_a->stack[0];

    int i = 1;
    while (i < size_a) {
        if (stack_a->stack[i] < min_value) {
            min_value = stack_a->stack[i];
            min_index = i;
        }
        i++;
    }

    return min_index;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        return 0;
    }

    Stack* stack_a = create_stack(argc - 1);
    Stack* stack_b = create_stack(argc - 1);

    int i = 1;
    while (i < argc) {
        char* arg = argv[i];

        // Vérification de chaque caractère de l'argument
        int j = 0;
        while (arg[j] != '\0') {
            if (arg[j] < '0' || arg[j] > '9') {
                fprintf(stderr, "Error\n");
                destroy_stack(stack_a);
                destroy_stack(stack_b);
                return 1;
            }
            j++;
        }

        int value = atoi(arg);
        push(stack_a, value);

        i++;
    }

    push_swap(stack_a, stack_b);

    destroy_stack(stack_a);
    destroy_stack(stack_b);

    return 0;
}

/*

// Trouver l'indice de la valeur maximale dans stack_b
int find_max_index(Stack *stack_b, int size_b) {
    int max_index = 0;
    int max_value = stack_b->stack[0];

    int i = 1;
    while (i < size_b) {
        if (stack_b->stack[i] > max_value) {
            max_value = stack_b->stack[i];
            max_index = i;
        }
        i++;
    }

    return max_index;
}
*/
