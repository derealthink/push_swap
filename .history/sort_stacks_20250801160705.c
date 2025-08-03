#include "push_swap.h"

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

void	prep_nodes_b(t_stack *a, t_stack *b)
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
void	min_top(t_stack *a)
{
	t_node	*current;

	assign_pos(a);
	current = a->top;
	while (current && current->index != 0)
		current = current->next;
	if (!current)
		return ;
	if (current->abm)
	{
		while (a->top->index != 0)
			ra(a);
	}
	else
	{
		while (a->top->index != 0)
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
	while (b)
	{
		prep_nodes_b(a, b);
	}
	assign_pos(a);
	min_top(a);
}