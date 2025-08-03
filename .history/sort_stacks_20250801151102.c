#include "push_swap.h"

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (a->size > 3 && (!is_sorted(a)))
		pb(a,b);
	if (a->size > 3 && (!is_sorted(a)))
		pb(a,b);
	while (a->size > 3 && (!is_sorted(a)))
	{
		prep_nodes_a(&a, &b);//to do 
		pa_to_b(a, b);//to do
	}
	sort_three(a);
	while (b)
	{
		prep_nodes_b(a, b);//to do
		pb_to_a(a, b);//to do
	}
	assign_pos(a);//to do
	min_top(a);//to do
}
void	prep_nodes_a(t_stack *a, t_stack *b)
{
	assign_pos(&a);
	assign_pos(&b);
	assign_index(&a);
	assign_index(&b);
	set_target_ab(&a, &b);
	calculate_cost_a(&a);
	calculate_cost_b(&b);
	//find_cheapest(a);
}