#include "push_swap.h"

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
	while (b)
	{
		prep_nodes_b(a, b);
	}
	assign_pos(a);
	min_top(a);//to do
}
void	prep_nodes_a(t_stack *a, t_stack *b)
{
	t_node *cheapest;

	assign_pos(a);
	assign_pos(b);
	assign_index(a);
	assign_index(b);
	set_target_ab(a, b);
	calculate_cost_a(a);
	calculate_cost_b(a);
	cheapest = get_cheapest_node(a);
	execute_move(a, b, cheapest);
}

prep_nodes_b(t_stack *a, t_stack *b)
{
	t_node *cheapest;

	assign_pos(a);
	assign_pos(b);
	set_target_ba(b, a);
	calculate_cost_a(a);
	calculate_cost_b(a);
	cheapest = get_cheapest_node(b);
	execute_move(b, a, cheapest);
}
