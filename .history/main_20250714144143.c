 #include "push_swap.h"
 
 int	main(int argc, char **argv)
 {
	t_stack stack_a;
	t_stack	stack_b;
	int		i;
	int		num;

	init_stack(&stack_a);
	init_stack(&stack_b);
	i = 1;
	while (i < argc)
	{
		num = atoi(argv[i]);
		t_node *new_node = create_node(num);
		if (!new_node)
		{
			printf("Error: malloc failed\n");
			return (1);
		}
		push_bottom(&stack_a, create_node(num));
		i++;
	}

	print_stack(&stack_a, 'A');
	print_stack(&stack_b, 'B');
	return (0);
 }