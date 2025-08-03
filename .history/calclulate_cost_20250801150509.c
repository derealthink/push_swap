#include "push_swap.h"

void	calculate_cost_a(t_stack *a)
{
	t_node	*current = a->top;

	while (current)
	{
		if (current->abm)
			current->cost_a = current->pos;
		else
			current->cost_a = (a->size - current->pos) * -1;

		current = current->next;
	}
}

void	calculate_cost_b(t_stack *b)
{
	t_node	*current = b->top;

	while (current)
	{
		if (current->target->abm)
			current->cost_b = current->target->pos;
		else
			current->cost_b = (b->size - current->target->pos) * -1;

		current->cost = abs(current->cost_a) + abs(current->cost_b);
		current = current->next;
	}
}

