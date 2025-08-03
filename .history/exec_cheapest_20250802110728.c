#include "push_swap.h"

static void	prep_p(t_stack *stack, t_node *tar, char s_name)
{
	while(stack->top != tar)
	{
		if (s_name == 'a')
		{
			if (tar->abm)
				ra(stack);
			else
				rra(stack);
		}
		else if (s_name == 'b')
		{
			if (tar->abm)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	pa_greedy(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	cheapest = get_cheapest_node(a);
	if (cheapest->abm && cheapest->target->abm)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->abm) && !(cheapest->target->abm))
		rev_rotate_both(a, b, cheapest);
	prep_p(a, cheapest, 'a');
	prep_p(b, cheapest->target, 'b');
	pb(a, b);
}

void	pb_greedy(t_stack *a, t_stack *b)
{
	t_node	*current;

	current = b->top;
	prep_p(a, current->target, 'a');
	pa(a, b);
}