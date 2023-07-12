/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:28:53 by julietteand       #+#    #+#             */
/*   Updated: 2023/07/12 18:12:29 by julietteand      ###   ########.fr       */
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

