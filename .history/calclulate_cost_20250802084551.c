#include "push_swap.h"

void	calculate_cost_a(t_stack *a, t_stack *b)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		current->cost = current->pos;
		if (!(current->abm))
			current->cost = a->size - (current->pos);
		if (current->target->abm)
			current->cost += current->target->value;
		else
			current->cost += b->size - (current->target->value);
		current = current->next;
	}
}

void	calculate_cost_b(t_stack *b, t_stack *a)
{
	t_node	*current;

	current = b->top;
	while (current)
	{
		current->cost = current->pos;
		if (!(current->abm))
			current->cost = b->size - (current->pos);
		if (current->target->abm)
			current->cost += current->target->value;
		else
			current->cost += a->size - (current->target->value);
		current = current->next;
	}
}
void	get_cheapest_node(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;
	long	lowest_cost;

	current = stack->top;
	cheapest = NULL;
	lowest_cost = LONG_MAX;
	if (!stack)
		return ;
	while (current)
	{
		if (current->cost < lowest_cost)
		{
			lowest_cost = current->cost;
			cheapest = current;
		}
		current = current->next;
	}
	cheapest->lowest_c = true;
}
t_node	*find_cheapest(t_stack *stack)
{
	t_node	*cheapest;
	t_node	*current;

	current = stack->top;
	cheapest = NULL;
	while (current)
	{
		if (current->lowest_c)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);	
}
