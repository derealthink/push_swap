#include "push_swap.h"

static void	rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_single(t_stack *stack, int cost, void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *))
{
	while (cost > 0)
	{
		rotate(stack);
		cost--;
	}
	while (cost < 0)
	{
		rev_rotate(stack);
		cost++;
	}
}

void	execute_move(t_stack *from, t_stack *to, t_node *node)
{
	int	cost_from = node->cost_a;
	int	cost_to = node->cost_b;

	if (!node)
		exit(1);

	rotate_both(from, to, &cost_from, &cost_to);
	rotate_single(from, cost_from, ra, rra);  // <-- these need to adjust for `from`
	rotate_single(to, cost_to, rb, rrb);

	if (from == a && to == b)
		pb(a, b);
	else if (from == b && to == a)
		pa(b, a);
}