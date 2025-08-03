#include "push_swap.h"

static t_node	*find_min(t_stack *stack)
{
	long	min;
	t_node *current;
	t_node *min;
	
	if (!stack || !stack->top)
		return (NULL);
	min = LONG_MAX;
	current = stack->top;
	min = current;
	while (current)
	{
		if (current->value < min)
			min = current;
		current = current->next;
	}
	return (min);
}

static t_node	*find_target_node_ba(t_node *b_node, t_stack *a)
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

void	set_target_ba(t_stack *b, t_stack *a)
{
	t_node	*current_b = b->top;

	while (current_b)
	{
		current_b->target = find_target_node_ba(current_b, a);
		current_b = current_b->next;
	}
}