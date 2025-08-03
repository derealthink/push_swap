#include "push_swap.h"

static t_node	*find_max(t_stack *stack)
{
	long	max_val;
	t_node *current;
	t_node *max;

	max_val = LONG_MIN; 
	current = stack->top;
	max = NULL;
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max = current;
		}
		current = current->next;
	}
	return (max);
}

void	find_target_a(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*target;
	long		best_val;

	current_a = a->top;
	while (current_a)
	{
		target = NULL;
		current_b = b->top;
		best_val = LONG_MIN;
		while (current_b)
		{
			if (current_b->value < current_a->value && current_b->value > best_val)
			{
				best_val = current_b->value;
				target = current_b;
			}
		current_b = current_b->next;
		}
		if (!target)
			current_a->target = find_max(b);
		else
			current_a->target = target;
		current_a = current_a->next;
	}
}
/*
void	find_target_a(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*target;
	long		best_val;

	current_a = a->top;
	while (current_a)
	{
		target = find_max(b);  // Default to max
		current_b = b->top;
		best_val = LONG_MIN;
		while (current_b)
		{
			if (current_b->value < current_a->value && current_b->value > best_val)
			{
				best_val = current_b->value;
				target = current_b;  // Override with better target
			}
			current_b = current_b->next;
		}
		current_a->target = target;
		current_a = current_a->next;
	}
}*/
