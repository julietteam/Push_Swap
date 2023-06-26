/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:49 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/26 21:42:02 by julietteand      ###   ########.fr       */
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
    while (i < n)
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
