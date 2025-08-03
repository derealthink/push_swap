#include "push_swap.h"

void	calculate_cost_a(t_stack *a)//calc for a and b so 2 functions but not 2 variable3s
{
	t_node	*current = a->top;
	int		cost_a;
	int		cost_b;

	while (current)
	{
		if (current->abm)
			cost_a = current->pos;
		else
			cost_a = (a->size - current->pos) * -1;
		if (current->target->abm)
			cost_b = current->target->pos;
		else
			cost_b = (b->size - current->target->pos) * -1;
		current->cost_a = cost_a;
		current->cost_b = cost_b;
		current->cost = abs(cost_a) + abs(cost_b);
		current = current->next;
	}
}
