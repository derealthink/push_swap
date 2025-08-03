#include "push_swap.h"

static	void	prep_nodes_a(t_stack *a, t_stack *b)
{
	t_node *cheapest;

	assign_pos(a);
	assign_pos(b);
	set_target_a(a, b);
	calculate_cost_a(a);
	calculate_cost_b(b);
	cheapest = get_cheapest_node(a);
	execute_move(a, b, cheapest);
}

static	void	prep_nodes_b(t_stack *a, t_stack *b)
{
	t_node *cheapest;

	assign_pos(a);
	assign_pos(b);
	set_target_ba(b, a);
	calculate_cost_a(a);
	calculate_cost_b(b);
	cheapest = get_cheapest_node(b);
	execute_move(b, a, cheapest);
}
static	void	min_top(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current->value != find_min(a)->value)
	{
		if (find_min(a)->abm)
			ra(a);
		else
			rra(a);
	}
}
void	sort_stacks(t_stack *a, t_stack *b)
{
		if (a->size > 3 && (!is_sorted(a)))
		pb(a,b);
	if (a->size > 3 && (!is_sorted(a)))
		pb(a,b);
	while (a->size > 3 && (!is_sorted(a)))
	{
		prep_nodes_a(a, b);
	}
	sort_three(a);
	while (b->top)
	{
		prep_nodes_b(a, b);
	}
	assign_pos(a);
	min_top(a);
}