/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sauvegarde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:33:08 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/28 17:27:31 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>


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

void sb(Stack *stack)
{
    if (stack->size < 2)
        return;

    int temp = stack->stack[0];
    stack->stack[0] = stack->stack[1];
    stack->stack[1] = temp;
}

void ss(Stack *stack_a, Stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void rb(Stack *stack)
{
    if (stack->size <= 1)
        return;

    int temp = stack->stack[0];
    int i = 0;
    while (i < stack->size - 1)
    {
        stack->stack[i] = stack->stack[i + 1];
        i++;
    }
    stack->stack[stack->size - 1] = temp;
}

void rr(Stack *stack_a, Stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(Stack *stack)
{
    if (stack->size <= 1)
        return;

    int temp = stack->stack[stack->size - 1];
    int i = stack->size - 1;
    while (i > 0)
    {
        stack->stack[i] = stack->stack[i - 1];
        i--;
    }
    stack->stack[0] = temp;
}

void rrb(Stack *stack)
{
    if (stack->size <= 1)
        return;

    int temp = stack->stack[stack->size - 1];
    int i = stack->size - 1;
    while (i > 0)
    {
        stack->stack[i] = stack->stack[i - 1];
        i--;
    }
    stack->stack[0] = temp;
}

void rrr(Stack *stack_a, Stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}


int is_sorted(Stack *stack)
{
    int i = 0;
    while (i < stack->size - 1)
    {
        if (stack->stack[i] > stack->stack[i + 1])
            return 0;
        i++;
    }
    return 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:12:41 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/28 10:40:31 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack *create_stack(int size) {
    Stack *stack = malloc(sizeof(Stack));
    stack->stack = malloc(size * sizeof(long long));
    stack->size = 0;
    return stack;
}
void destroy_stack(Stack *stack) 
{
    free(stack->stack);
    free(stack);
}

void print_sorted_stack(Stack* stack) {
    int i = 0;
    while (i < stack->size) {
        ft_printf("%d ", stack->stack[i]);
        i++;
    }
    ft_putchar('\n');
}


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
    while (stack_b->size > 0) {
    pa(stack_a, stack_b);
    if (stack_a->size >= 2 && stack_a->stack[0] > stack_a->stack[1])
        sa(stack_a);
    else if (stack_a->size >= 2 && stack_a->stack[0] > stack_a->stack[stack_a->size - 1])
        ra(stack_a);
    }
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
    print_sorted_stack(stack_a);
    
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:10:04 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/28 10:40:40 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>


typedef struct s_node
{
    long long data;
    struct s_node* next;
} Node;

typedef struct 
{
        Node *top;
        long long *stack;
        int size;
} Stack;


Stack *create_stack(int size);
void print_sorted_stack(Stack *stack);
void push(Stack *stack, long long number);
void destroy_stack(Stack *stack);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void my_radixsort(int arr[], int n);
void print_stack(Stack *stack);
void push_swap(Stack *stack_a, Stack *stack_b);
int find_min_index(Stack *stack_a, int size_a);
//int find_max_index(Stack *stack_b, int size_b);
void sa(Stack *stack);
void sb(Stack *stack);
void ss(Stack *stack_a, Stack *stack_b);
void pa(Stack *src, Stack *dest);
void pb(Stack *src, Stack *dest);
void ra(Stack *stack);
void rb(Stack *stack);
void rr(Stack *stack_a, Stack *stack_b);
void rra(Stack *stack);
void rrb(Stack *stack);
void rrr(Stack *stack_a, Stack *stack_b);
int is_sorted(Stack *stack);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:49 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/28 10:24:32 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Libft/ft_printf.h"
#include "push_swap.h"



int getMax(int arr[], int n)
{
	int mx = arr[0];
	int i = 1;
    while (i < n)
    {
        if (arr[i] > mx)
            mx = arr[i];
        i++;
    }
    return (mx);
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    int i = 0;
    while (i < 10)
        count[i++] = 0;
    i = 0;
    while (i < n)
        count[(arr[i++] / exp) % 10]++;
    i = 1;
    while (i < 10)
        count[i] += count[i - 1]++;
    i = n - 1;
    while (i >= 0)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        i--;
    }
    i = 0;
    while (i < n)
    {
        arr[i] = output[i];
        i++;
    }
}


void my_radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    int exp = 1;
    while (m / exp > 0)
    {
        countSort(arr, n, exp);
        exp *= 10;
    }
}
void print_stack(Stack *stack)
{
    int i = 0;
    while (i < stack->size)
    {
        ft_printf("%d ", stack->stack[i]);
        i++;
    }
    ft_putchar('\n');
}

