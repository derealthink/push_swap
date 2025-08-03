#include "push_swap.h"

static t_node	*find_min(t_stack *stack)
{
	long	min_val;
	t_node *current;
	t_node *min;
	
	min_val = LONG_MAX;
	current = stack->top;
	min = NULL;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min = current;
		}
		current = current->next;
	}
	return (min);
}

void	t_stack	find_target_b(t_stack *b, t_stack *a)
{
	t_node	*current_a = a->top;
	t_node	*best_target = NULL;
	int		best_index = INT_MIN;

	while (current_a)
	{
		if (current_a->index < b_node->index && current_a->index > best_index)
		{
			best_index = current_a->index;
			best_target = current_a;
		}
		current_a = current_a->next;
	}
	if (!best_target)
		return (find_min(a));
	return (best_target);
}