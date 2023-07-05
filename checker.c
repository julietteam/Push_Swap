// Vérifier si la pile est vide
int	is_empty(const t_stack *stack)
{
	return stack->top == -1;
}

// Empiler un élément sur la pile
void	push(t_stack *stack, int number)
{
	if (stack->top == stack->size - 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	stack->numbers[++stack->top] = number;
}

// Dépiler un élément de la pile
int	pop(t_stack *stack)
{
	if (is_empty(stack))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return stack->numbers[stack->top--];
}

// Afficher "OK" sur la sortie standard
void	print_ok()
{
	ft_putstr("OK\n");
}

// Afficher "KO" sur la sortie standard
void	print_ko()
{
	ft_putstr("KO\n");
}

// Afficher "Error" sur la sortie d'erreur
void	print_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}


// Exécuter les instructions sur la pile
void	execute_instructions(t_stack *stack_a, t_stack *stack_b, char **instructions, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ft_strcmp(instructions[i], "sa") == 0)
			swap(stack_a);
		else if (ft_strcmp(instructions[i], "sb") == 0)
			swap(stack_b);
		else if (ft_strcmp(instructions[i], "ss") == 0)
			swap_both(stack_a, stack_b);
		else if (ft_strcmp(instructions[i], "pa") == 0)
			push(stack_a, pop(stack_b));
		else if (ft_strcmp(instructions[i], "pb") == 0)
			push(stack_b, pop(stack_a));
		// Ajoutez ici le code pour les autres instructions (ra, rb, rr, rra, rrb, rrr)
		else
			print_error();
	}
}

// Lire les instructions depuis l'entrée standard
char	**read_instructions(int *count)
{
	char	*line;
	char	**instructions;
	int		i;

	i = 0;
	instructions = malloc(sizeof(char *));
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		instructions = realloc(instructions, (suite)sizeof(char *) * (i + 1));
		instructions[i] = line;
		i++;
	}
	instructions[i] = NULL;
	*count = i;
	return instructions;
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		instructions_count;
	char	**instructions;

	initialize_stack(&stack_a, argc - 1);
	initialize_stack(&stack_b, 0);

	if (argc < 2)
		return 0;

	for (int i = 1; i < argc; i++)
		push(&stack_a, ft_atoi(argv[i]));

	instructions = read_instructions(&instructions_count);

	execute_instructions(&stack_a, &stack_b, instructions, instructions_count);

	if (is_sorted(&stack_a, &stack_b))
		print_ok();
	else
		print_ko();

	// Libérer la mémoire utilisée
	for (int i = 0; i < instructions_count; i++)
		free(instructions[i]);
	free(instructions);
	free(stack_a.numbers);
	free(stack_b.numbers);

	return 0;
}