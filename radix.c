/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:49 by juandrie          #+#    #+#             */
/*   Updated: 2023/07/10 23:08:35 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Libft/ft_printf.h"
#include "push_swap.h"

void	sort_three_elements(t_stack *stack)
{
    // Si le troisième élément du tableau n'est pas 2
	if (stack->stack_a[2] != 2)
	{
        // Si le premier élément est 2, on le déplace vers le haut
		if (stack->stack_a[0] == 2)
			rotate(stack->stack_a, stack->a_size, "up", "a");
		else
        // Sinon, on le déplace vers le bas
			rotate(stack->stack_a, stack->a_size, "down", "a");
	}
    // Si le premier élément est plus grand que le deuxième élément, on les échange
	if (stack->stack_a[0] > stack->stack_a[1])
		swap("sa", stack->stack_a, stack->a_size);
}

void	sort_four_to_five_elements(t_stack *stack)
{
    // Tant que la taille du tableau b est inférieure ou égale à 1
	while (stack->b_size <= 1)
	{
		// Si le premier élément est 0 ou 1, on le pousse vers le tableau b
        if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
			push("pb", stack);
        // Sinon, on le déplace vers le haut
		else
			rotate(stack->stack_a, stack->a_size, "up", "a");
	}
    // Si le premier élément du tableau b est 0, on échange les éléments du tableau b
	if (stack->stack_b[0] == 0)
		swap("sb", stack->stack_b, stack->b_size);
    // Si le troisième élément du tableau b n'est pas 4
	if (stack->stack_b[2] != 4)
	{
		// Si le premier élément est 4, on le déplace vers le haut
        if (stack->stack_b[0] == 4)
			rotate(stack->stack_a, stack->a_size, "up", "a");
         // Sinon, on le déplace vers le bas
		else
			rotate(stack->stack_a, stack->a_size, "down", "a");
	}
    // Si le premier élément est plus grand que le deuxième élément, on les échange
	if (stack->stack_a[0] > stack->stack_a[1])
		swap("sa", stack->stack_a, stack->a_size);
    // On pousse les éléments du tableau b vers le tableau a
	push("pa", stack);
	push("pa", stack);
}

int	is_array_sorted(t_stack *stack)
{
	int	i;

	i = 0;
    // On parcourt les éléments du tableau a de gauche à droite
	while (i < stack->a_size - 1)
	{
		// Si un élément est plus grand que l'élément suivant, le tableau n'est pas trié
        if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
    // Si on a parcouru tous les éléments sans trouver d'erreur, il est trié 
	return (1);
}

static void	radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j)
{
	// Tant que la taille du tableau b est supérieure à 0, que j est inférieur ou égal à bit_size et que le tableau a n'est pas trié
    while (b_size-- && j <= bit_size && !is_array_sorted(stack))
	{
		// Si le bit j de l'élément du tableau b est 0, on le déplace vers le haut
        if (((stack->stack_b[0] >> j) & 1) == 0)
			rotate(stack->stack_b, stack->b_size, "up", "b");
        // Sinon, on pousse l'élément du tableau b vers le tableau a
		else
			push("pa", stack);
	}
    // Si le tableau a est trié, on pousse tous les éléments du tableau b vers le tableau a
	if (is_array_sorted(stack))
		while (stack->b_size != 0)
			push("pa", stack);
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->a_size;
    // tant que la taille du tableau size est supérieure à 1 
	while (size > 1 && ++bit_size)
    // On divise par 2. Ca permet de réduire la taille jusqu'à ce qu'il ne reste plus qu'un seul bit.
		size = size / 2;
	i = -1;
    // Tant i est inférieur ou égale à bit_size
	while (++i <= bit_size)
	{
		// on adapte size à la taille du tableau à trier
        size = stack->a_size;
        //tant que le tableau n'est pas encore trié et que size est supérieur ou égal à 0
		while (size <= 0 && !is_array_sorted(stack))
		{
            // si le bit à la position i du premier nombre du tableau stack_a est égal à 0.
			if (((stack->stack_a[0] >> i) & 1) == 0)
				push("pb", stack);
            //Sinon, si le bit est 1, rotation du tableau stack_a vers le haut
			else
				rotate(stack->stack_a, stack->a_size, "up", "a");
		}
		radix_sort_stack_b(stack, stack->b_size, bit_size, i + 1);
	}
    // Tant que la taille du tableau b est différente de 0
	while (stack->b_size != 0)
		push("pa", stack);
}

/*
void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_value = get_max_value(stack_a->numbers, stack_a->start, stack_a->top);
    int num_digits = get_num_digits(max_value);
    int divisor = 1;

    int i = 0;
    if (is_sorted(stack_a))
        return;

    while (i < num_digits) {
        int count[10] = {0};

        int j = stack_a->start;
        while (j <= stack_a->top) {
            count[(stack_a->numbers[j] / divisor) % 10]++;
            j++;
        }

        int k = 1;
        while (k < 10) {
            count[k] += count[k - 1];
            k++;
        }

     int l = stack_a->top;
while (l >= stack_a->start) {
    int digit = (stack_a->numbers[l] / divisor) % 10;
    stack_b->numbers[--count[digit]] = stack_a->numbers[l];
    add_operation(stack_b, "pb"); // Enregistrer l'opération dans la pile B
    l--;
}

stack_a->start = stack_a->top + 1; // Mettre à jour l'indice de début de la pile A

// ...

int m = stack_a->start;
int n = stack_b->start;
while (n <= stack_b->top) {
    stack_a->numbers[m] = stack_b->numbers[n];
    add_operation(stack_a, "pa"); // Enregistrer l'opération dans la pile A
    m++;
    n++;
}

stack_a->start = stack_a->top - stack_b->size + 1; // Mettre à jour l'indice de début de la pile A
stack_b->start = stack_b->top + 1; // Mettre à jour l'indice de début de la pile B


        if (divisor == 1) {
            if (stack_a->top >= 1 && stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
                add_operation(stack_a, "sa");
            if (stack_b->top >= 1 && stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
                add_operation(stack_a, "sb");
            add_operation(stack_a, "ss");
        } else {
            if (stack_a->top >= 1 && stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
                add_operation(stack_a, "sa");
            if (stack_b->top >= 1 && stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
                add_operation(stack_a, "sb");
            if (stack_a->top >= 1)
                add_operation(stack_a, "ra");
            if (stack_b->top >= 1)
                add_operation(stack_a, "rb");
            if (stack_a->top >= 1 && stack_b->top >= 1)
                add_operation(stack_a, "rr");
            if (stack_a->top >= 1)
                add_operation(stack_a, "rra");
            if (stack_b->top >= 1)
                add_operation(stack_a, "rrb");
            if (stack_a->top >= 1 && stack_b->top >= 1)
                add_operation(stack_a, "rrr");
        }

        printf("After iteration %d:\n", i + 1);
        printf("Stack A: ");
        for (int j = stack_a->start; j <= stack_a->top; j++) {
            printf("%lld ", stack_a->numbers[j]);
        }
        printf("\n");
        printf("Stack B: ");
        for (int j = stack_b->start; j <= stack_b->top; j++) {
            printf("%lld ", stack_b->numbers[j]);
        }
        printf("\n");
        
        printf("Operations: ");
        print_operation(stack_a);
        printf("\n");

        if (is_sorted(stack_a))
            break;

        divisor *= 10;
        i++;
    }
}
*/


/*
void radix_sort(t_stack *stack_a, t_stack *stack_b) 
{
    int max_value = get_max_value(stack_a->numbers, stack_a->start, stack_a->top);
    int num_digits = get_num_digits(max_value);
    int divisor = 1;

    int i = 0;
    if (is_sorted(stack_a))
        return;

    while (i < num_digits) {
        int count[10] = {0};

        int j = stack_a->start;
        while (j <= stack_a->top) {
            count[(stack_a->numbers[j] / divisor) % 10]++;
            j++;
        }

        int k = 1;
        while (k < 10) {
            count[k] += count[k - 1];
            k++;
        }

        int l = stack_a->top;
        while (l >= stack_a->start) 
        {
            int digit = (stack_a->numbers[l] / divisor) % 10;
            stack_b->numbers[--count[digit]] = stack_a->numbers[l];
            add_operation(stack_a, "pb");
            l--;
        }
        
        int m = stack_a->start;
        int n = stack_b->start;
        while (n <= stack_a->top ) 
        {
            stack_a->numbers[m] = stack_b->numbers[n];
            add_operation(stack_a, "pa");
            m++;
            n++;
        }

        if (divisor == 1) 
        {
            if (stack_a->top >= 1 && stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
                add_operation(stack_a, "sa");
            if (stack_b->top >= 1 && stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
                add_operation(stack_a, "sb");
            add_operation(stack_a, "ss");
        } 
        else 
        {
            if (stack_a->top >= 1 && stack_a->numbers[stack_a->top] > stack_a->numbers[stack_a->top - 1])
                add_operation(stack_a, "sa");
            if (stack_b->top >= 1 && stack_b->numbers[stack_b->top] < stack_b->numbers[stack_b->top - 1])
                add_operation(stack_a, "sb");
            if (stack_a->top >= 1)
                add_operation(stack_a, "ra");
            if (stack_b->top >= 1)
                add_operation(stack_a, "rb");
            if (stack_a->top >= 1 && stack_b->top >= 1)
                add_operation(stack_a, "rr");
            if (stack_a->top >= 1)
                add_operation(stack_a, "rra");
            if (stack_b->top >= 1)
                add_operation(stack_a, "rrb");
            if (stack_a->top >= 1 && stack_b->top >= 1)
                add_operation(stack_a, "rrr");
                 // Afficher l'état de la pile après chaque itération
        }
        divisor *= 10;
        i++;
    }
}
*/





/*
void radix_sort(t_stack *stack_a, t_stack *stack_b) 
{
    printf("Start radix_sort\n"); 
    int max_value = get_max_value(stack_a->numbers, stack_a->start, stack_a->top);
    int num_digits = get_num_digits(max_value);
    int divisor = 1;

    int i = 0;
    if (is_sorted(stack_a))
        return;

    while (i < num_digits) {
        printf("Iteration %d:\n", i + 1);

        // Réinitialiser les compteurs pour chaque itération de tri radix
        int count[10] = {0};

        // Compter le nombre d'éléments pour chaque chiffre dans la plage spécifiée
        int j = stack_a->start;
        while (j <= stack_a->top) {
            count[(stack_a->numbers[j] / divisor) % 10]++;
            j++;
        }

        // Afficher les valeurs des compteurs avant de les mettre à jour
       // printf("Count array before update:\n");
        for (int k = 0; k < 10; k++) {
       //printf("%d ", count[k]);
        }
        //printf("\n");

        // Calculer les positions finales pour chaque chiffre
        int k = 1;
        while (k < 10) {
            count[k] += count[k - 1];
            k++;
        }

        // Afficher les valeurs des compteurs après mise à jour
        //printf("Stack A:");
        for (int k = 0; k < 10; k++) {
        //printf("%d ", count[k]);
        }
        //printf("\n");

        // Placer les éléments dans le bon ordre dans stack_b
        int l = stack_a->top;
        while (l >= stack_a->start) {
            int digit = (stack_a->numbers[l] / divisor) % 10;
            stack_b->numbers[--count[digit]] = stack_a->numbers[l];
            l--;
        }

        // Copier les éléments triés de stack_b vers stack_a en ordre croissant
        // Copier les éléments triés de stack_b vers stack_a en ordre croissant
        int m = stack_a->start;
        int n = stack_b->start;
        while (n <= stack_a->top ) 
        {
            stack_a->numbers[m] = stack_b->numbers[n];
            m++;
            n++;
        }
        // Ajouter les opérations de tri à stack_a->operations


        // Afficher l'état de la pile après chaque itération
        //printf("Stack A:");
        printf("Operations:\n");
        for (int k = stack_a->start; k <= stack_a->top; k++) {
            //printf(" %lld", stack_a->numbers[k]);
            printf("%s\n", stack_a->operations[k]);
        }
        printf("\n\n");

        divisor *= 10;
        i++;
    }
    printf("End radix_sort\n");  // Fin de la fonction
}

*/



/*
void radix_sort(t_stack *stack_a, t_stack *stack_b) {
    int max_value = get_max_value(stack_a->numbers, stack_a->start, stack_a->top);
    int num_digits = get_num_digits(max_value);
    int divisor = 1;

    int i = 0;
    if (is_sorted(stack_a))
        return;
	
    while (i < num_digits) {
        printf("Iteration %d:\n", i + 1);

        // Réinitialiser les compteurs pour chaque itération de tri radix
        int count[10] = {0};

        // Compter le nombre d'éléments pour chaque chiffre dans la plage spécifiée
        int j = stack_a->start;
        while (j <= stack_a->top) {
            count[(stack_a->numbers[j] / divisor) % 10]++;
            j++;
        }

        // Calculer les positions finales pour chaque chiffre
        int k = 1;
        while (k < 10) {
            count[k] += count[k - 1];
            k++;
        }

        // Placer les éléments dans le bon ordre dans stack_b
        int l = stack_a->top;
        while (l >= stack_a->start) {
            int digit = (stack_a->numbers[l] / divisor) % 10;
            stack_b->numbers[--count[digit]] = stack_a->numbers[l];
            l--;
        }

        // Copier les éléments triés de stack_b vers stack_a en ordre croissant
        int m = stack_a->start;
        int n = stack_b->start;
        while (m <= stack_a->top) {
            stack_a->numbers[m] = stack_b->numbers[n];
            m++;
            n++;
        }

        // Afficher l'état de la pile après chaque itération
        printf("Stack A:");
        for (int k = stack_a->start; k <= stack_a->top; k++) {
            printf(" %lld", stack_a->numbers[k]);
        }
        printf("\n\n");

        divisor *= 10;
        i++;
    }
}
*/