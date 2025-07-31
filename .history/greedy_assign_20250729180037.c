#include "push_swap.h"

void	assign_positions(t_stack *stack)
{
	t_node	*current = stack->top;
	int		pos = 0;

	while (current)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

int	find_target_position(t_stack *a, int b_value)
{
	t_node	*current = a->top;
	int		target_pos = -1;
	int		min_diff = INT_MAX;

	while (current)
	{
		int	diff = current->value - b_value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_pos = current->pos;
		}
		current = current->next;
	}
	if (target_pos == -1)
		return (find_smallest_pos(a));
	return (target_pos);
}
void	assign_targets(t_stack *a, t_stack *b)
{
	t_node	*current = b->top;

	assign_positions(a);
	assign_positions(b);
	while (current)
	{
		current->target_pos = find_target_position(a, current->value);
		current = current->next;
	}
}

void	assign_costs(t_stack *a, t_stack *b)
{
	t_node	*current = b->top;
	int		size_a = stack_size(a);
	int		size_b = stack_size(b);

	while (current)
	{
		current->cost_b = current->pos <= size_b / 2 ? current->pos : (current->pos - size_b);
		current->cost_a = current->target_pos <= size_a / 2 ? current->target_pos : (current->target_pos - size_a);
		current = current->next;
	}
}

