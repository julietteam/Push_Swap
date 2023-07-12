/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:28:53 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/11 12:21:37 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;
    // si la taille est inférieure ou égale à 0, la fonction s'arrête 
	if (size <= 0)
		return ;
    // sinon elle change les valeurs du tableau array
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_stack *stack)
{
	int	tmp;
    // Si str est égale à pa, alors il faut déplacer un élément stack b vers stack a 
	if (ft_strncmp(str, "pa", 3) == 0)
	{
        // Vérifie si la taille de stack_b est supérieure à 0
		if (stack->b_size <= 0)
			return ;
        // Stocke la valeur du premier élément de stack_b dans tmp
		tmp = stack->stack_b[0];
        // Déplace tous les éléments de stack_a d'une position vers la droite
		ft_memmove(stack->stack_a + 1, stack->stack_a, sizeof(int) * stack->a_size);
        // Place la valeur de tmp à la première position de stack_a
		stack->stack_a[0] = tmp;
        // Diminue la taille de stack_b de 1
		stack->b_size--;
        // Déplace tous les éléments restants de stack_b d'une position vers la gauche
		ft_memmove(stack->stack_b, stack->stack_b + 1, sizeof(int) * stack->b_size);
        // Augmente la taille de stack_b de 1
		stack->a_size++;
	}
    // Sinon, si str est égale à "pb", il faut déplacer un élément de stack_a vers stack_b
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		// Vérifie si la taille de stack_a est supérieure à 0
        if (stack->a_size <= 0)
			return ;
        // Stocke la valeur du premier élément de stack_a dans tmp
		tmp = stack->stack_a[0];
        // Déplace tous les éléments de stack_b d'une position vers la droite
		ft_memmove(stack->stack_b + 1, stack->stack_b, sizeof(int) * stack->b_size);
        // Place la valeur de tmp à la première position de stack_b
		stack->stack_b[0] = tmp;
        // Diminue la taille de stack_a de 1
		stack->a_size--;
        // Déplace tous les éléments restants de stack_a d'une position vers la gauche
		ft_memmove(stack->stack_a, stack->stack_a + 1, sizeof(int) * stack->a_size);
        // Augmente la taille de stack_b de 1
		stack->b_size++;
	}
     // Affiche la chaîne de caractères str sur la sortie standard
	ft_putendl_fd(str, 1);
}

void	rotate(int *array, int size, char *direction, char *list)
{
	int	tmp;
    // Si la taille est inférieure à 0, la fonction se termine immédiatement
	if (size < 0)
		return ;
    // Si direction est égal à "up", il faut effectuer une rotation vers le haut
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		 // Stocke la valeur du premier élément du tableau dans tmp
        tmp = array[0];
         // Déplace tous les éléments du tableau d'une position vers la gauche
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
        // Place la valeur stockée dans tmp à la dernière position du tableau
		array[size - 1] = tmp;
        // Écrit le caractère 'r' sur la sortie standard
		write(1, "r", 1);
	}
    // Sinon, si direction est égal à "down", il faut effectuer une rotation vers le bas
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		// Stocke la valeur du dernier élément du tableau dans tmp
        tmp = array[size - 1];
        // Déplace tous les éléments du tableau d'une position vers la droite
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
        // Place la valeur stockée dans tmp à la première position du tableau
		array[0] = tmp;
        // Écrit les caractères 'rr' sur la sortie standard
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}


/*
void print_sa(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        int temp = stack_a->numbers[stack_a->top];
        stack_a->numbers[stack_a->top] = stack_a->numbers[stack_a->top - 1];
        stack_a->numbers[stack_a->top - 1] = temp;
        stack_a->operations[stack_a->top] = ft_strdup("sa");
    }
}


void print_sb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        int temp = stack_b->numbers[stack_b->top];
        stack_b->numbers[stack_b->top] = stack_b->numbers[stack_b->top - 1];
        stack_b->numbers[stack_b->top - 1] = temp;
        stack_b->operations[stack_b->top] = ft_strdup("sb");
    }
}

void print_ss(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        int temp_a = stack_a->numbers[stack_a->top];
        stack_a->numbers[stack_a->top] = stack_a->numbers[stack_a->top - 1];
        stack_a->numbers[stack_a->top - 1] = temp_a;

        int temp_b = stack_b->numbers[stack_b->top];
        stack_b->numbers[stack_b->top] = stack_b->numbers[stack_b->top - 1];
        stack_b->numbers[stack_b->top - 1] = temp_b;
        stack_a->operations[stack_a->top] = ft_strdup("ss");
        stack_b->operations[stack_b->top] = ft_strdup("ss");
    }
}


void print_pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->top >= 0)
    {
        stack_a->numbers[++stack_a->top] = stack_b->numbers[stack_b->top--];
        stack_a->operations[stack_a->top] = ft_strdup("pa");
    }
}


void print_pb(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 0)
    {
        stack_b->numbers[++stack_b->top] = stack_a->numbers[stack_a->top--];
        stack_b->operations[stack_b->top] = ft_strdup("pb");
    }
}


void print_ra(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        int first = stack_a->numbers[stack_a->top];
        int i = stack_a->top;
        while (i > 0) {
            stack_a->numbers[i] = stack_a->numbers[i - 1];
            i--;
        }
        stack_a->numbers[0] = first;
         stack_a->operations[stack_a->top] = ft_strdup("ra");
    }
}

void print_rb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        int first = stack_b->numbers[stack_b->top];
        int i = stack_b->top;
        while (i > 0) {
            stack_b->numbers[i] = stack_b->numbers[i - 1];
            i--;
        }
        stack_b->numbers[0] = first;
        stack_b->operations[stack_b->top] = ft_strdup("rb");
    }
}


void print_rr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        int first_a = stack_a->numbers[stack_a->top];
        int first_b = stack_b->numbers[stack_b->top];

        int i = stack_a->top;
        while (i > 0) {
            stack_a->numbers[i] = stack_a->numbers[i - 1];
            i--;
        }
        stack_a->numbers[0] = first_a;

        i = stack_b->top;
        while (i > 0) {
            stack_b->numbers[i] = stack_b->numbers[i - 1];
            i--;
        }
        stack_b->numbers[0] = first_b;
        stack_a->operations[stack_a->top] = ft_strdup("rr");
        stack_b->operations[stack_b->top] = ft_strdup("rr");
    }
}


void print_rra(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        int last = stack_a->numbers[stack_a->top];
        int i = stack_a->top;
        while (i > 0)
        {
            stack_a->numbers[i] = stack_a->numbers[i - 1];
            i--;
        }
        stack_a->numbers[0] = last;
        stack_a->operations[stack_a->top] = ft_strdup("rra");
    }
}


void print_rrb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        int last = stack_b->numbers[stack_b->top];
        int i = stack_b->top;
        while (i > 0)
        {
            stack_b->numbers[i] = stack_b->numbers[i - 1];
            i--;
        }
        stack_b->numbers[0] = last;
        stack_b->operations[stack_b->top] = ft_strdup("rrb");

    }
}

void print_rrr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        int last_a = stack_a->numbers[stack_a->top];
        int last_b = stack_b->numbers[stack_b->top];
        
        // Décalage des éléments de la pile A
        int i = stack_a->top;
        while (i > 0)
        {
            stack_a->numbers[i] = stack_a->numbers[i - 1];
            i--;
        }
        stack_a->numbers[0] = last_a;
        
        // Décalage des éléments de la pile B
        i = stack_b->top;
        while (i > 0)
        {
            stack_b->numbers[i] = stack_b->numbers[i - 1];
            i--;
        }
        stack_b->numbers[0] = last_b;
        stack_a->operations[stack_a->top] = ft_strdup("rrr");
        stack_b->operations[stack_b->top] = ft_strdup("rrr");
    
    }
}


*/
