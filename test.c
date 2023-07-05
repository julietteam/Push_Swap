#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#define MAX_NUMBERS 1000 // Remplacez la valeur 1000 par la taille maximale souhaitée

typedef struct	s_stack
{
	int			numbers[MAX_NUMBERS];
	int			top;
}				t_stack;


void	swap(t_stack *stack)
{
	int temp = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = temp;
}

void	push(t_stack *src, t_stack *dst)
{
	dst->numbers[++dst->top] = src->numbers[src->top--];
}

void	rotate(t_stack *stack)
{
	int first = stack->numbers[stack->top];
	int i = stack->top;
	while (i > 0) {
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = first;
}

void	reverse_rotate(t_stack *stack)
{
	int last = stack->numbers[0];
	int i = 0;
	while (i < stack->top) {
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[stack->top] = last;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

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

int		get_max_value(int *array, int size)
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

int		get_num_digits(int number)
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

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
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

int ft_atoi(const char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    // Ignorer les espaces initiaux
    while (str[i] == ' ')
        i++;

    // Vérifier le signe
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    // Convertir les chiffres en entier
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

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

void print_sa(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        swap(stack_a);
        ft_putstr("sa");
        ft_putchar('\n');
    }
}

void print_sb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        swap(stack_b);
        ft_putstr("sb");
        ft_putchar('\n');
    }
}

void print_ss(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        swap(stack_a);
        swap(stack_b);
        ft_putstr("ss");
        ft_putchar('\n');
    }
}

void print_pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->top >= 0)
    {
        push(stack_b, stack_a);
        ft_putstr("pa");
        ft_putchar('\n');
    }
}

void print_pb(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 0)
    {
        push(stack_a, stack_b);
        ft_putstr("pb");
        ft_putchar('\n');
    }
}

void print_ra(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        rotate(stack_a);
        ft_putstr("ra");
        ft_putchar('\n');
    }
}

void print_rb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        rotate(stack_b);
        ft_putstr("rb");
        ft_putchar('\n');
    }
}

void print_rr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top >= 1 && stack_b->top >= 1)
    {
        rotate(stack_a);
        rotate(stack_b);
        ft_putstr("rr");
        ft_putchar('\n');
    }
}

void print_rra(t_stack *stack_a)
{
    if (stack_a->top >= 1)
    {
        reverse_rotate(stack_a);
        ft_putstr("rra");
        ft_putchar('\n');
    }
}

void print_rrb(t_stack *stack_b)
{
    if (stack_b->top >= 1)
    {
        reverse_rotate(stack_b);
        ft_putstr("rrb");
        ft_putchar('\n');

    }
}

void print_rrr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top > 1 && stack_b->top > 1)
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        ft_putstr("rrr");
        ft_putchar('\n');
    }
}
void print_operations(t_stack *stack_a, t_stack *stack_b)
{
    int i = stack_a->top;

    while (i >= 0)
    {
        if (i == stack_a->top)
            print_pa(stack_a, stack_b);
        else
        {
            print_pa(stack_a, stack_b);
            print_pb(stack_a, stack_b);
            print_ra(stack_a);
            print_rb(stack_b);
            print_rr(stack_a, stack_b);
            print_sa(stack_a);
            print_sb(stack_b);
            print_ss(stack_a, stack_b);
            print_rra(stack_a);
            print_rrb(stack_b);
            print_rrr(stack_a, stack_b);
        }
        i--;
    }
}
int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    int numbers_count;

    if (argc < 2)
        return 0;

    // Initialise stack_a avec les nombres d'entrée
    numbers_count = 1;
    stack_a.top = -1;
    stack_b.top = -1;
    while (numbers_count < argc)
    {
        stack_a.numbers[++stack_a.top] = ft_atoi(argv[numbers_count]);
        numbers_count++;
    }
    // Vérifier les doublons
    if (check_duplicates(stack_a.numbers, stack_a.top + 1))
    {
        ft_putstr("Error\n");
        return 1;
    }
	// Vérifier si la pile est déjà triée
	if (is_sorted(&stack_a))
	{
    	// Les valeurs sont déjà triées, afficher le message approprié
    	ft_putstr("Pile already sorted\n");
		return 1;
	} 
	radix_sort(&stack_a, &stack_b);
	print_operations(&stack_a, &stack_b);
    // Afficher les chiffres triés dans le bon ordre
    ft_putstr("Result:\n");
    print_stack(&stack_a);
    return 0;
}
