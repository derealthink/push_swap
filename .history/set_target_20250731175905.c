#include "push_swap.h"

static t_node	*find_max(t_stack *stack)
{
	t_node *current = stack->top;
	t_node *max = current;

	while (current)
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
	}
	return (max);
}

static t_node	*find_target_node(t_node *a_node, t_stack *b)
{
	t_node	*current_b = b->top;
	t_node	*best_target = NULL;
	int		best_index = INT_MAX;

	while (current_b)
	{
		if (current_b->index > a_node->index && current_b->index < best_index)
		{
			best_index = current_b->index;
			best_target = current_b;
		}
		current_b = current_b->next;
	}
	if (!best_target)
		return (find_max(b));
	return (best_target);
}

void	set_target(t_stack *a, t_stack *b)
{
	t_node	*current_a = a->top;

	while (current_a)
	{
		current_a->target = find_target_node(current_a, b);
		current_a = current_a->next;
	}
}