 #include "push_swap.h"
 
 int	main(int argc, char **argv)
 {
	t_stack stack_a;
	t_stack	stack_b;
	int		i;
	int		num;
	int		*iarr;

	iarr = NULL;
	i = 0;
	num = 0;
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc ==  2)
	{
		num = arg_count(argv[1]);
		iarr = parse_wq(argv[1]);
		if (!iarr)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		while (i < num)
		{
			t_node *new_node = create_node(iarr[i]);
			if (!new_node)
			{
				printf("Error: malloc failed\n");
				free(iarr);
				return (1);
			}
			push_bottom(&stack_a, new_node);
			i++;
		}
		free(iarr);
	}
	else 
	{
		num = argc - 1;
		iarr = parse_ma(argv + 1, argc);
		if (!iarr)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		while (i < argc)
		{
			t_node *new_node = create_node(iarr[i]); 
			if (!new_node)
			{
				printf("Error: malloc failed\n");
				free(iarr);
				return (1);
			}
			push_bottom(&stack_a, new_node);
			i++;
		}
		free(iarr);
	}
	return (0);
 }

