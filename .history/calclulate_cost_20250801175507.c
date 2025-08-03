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

void calculate_cost_b(t_stack *a, t_stack *b)
{
    t_node *current = b->top;
    
    while (current)
    {
        // Cost to move target in stack A
        if (current->target->abm)
            current->cost_b = current->target->pos;
        else
            current->cost_b = (a->size - current->target->pos) * -1; // Use a->size, not b->size
        
        // Cost to move current node to top of B
        if (current->abm)
            current->cost_a = current->pos;
        else
            current->cost_a = (b->size - current->pos) * -1;
        
        // Optimize for combined operations
        if ((current->cost_a > 0 && current->cost_b > 0) || 
            (current->cost_a < 0 && current->cost_b < 0))
            current->cost = abs(max(current->cost_a, current->cost_b));
        else
            current->cost = abs(current->cost_a) + abs(current->cost_b);
        
        current = current->next;
    }
}

t_node	*get_cheapest_node(t_stack *a)
{
	t_node	*current = a->top;
	t_node	*cheapest = NULL;
	int		lowest_cost = INT_MAX;

	while (current)
	{
		if (current->cost < lowest_cost)
		{
			lowest_cost = current->cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
