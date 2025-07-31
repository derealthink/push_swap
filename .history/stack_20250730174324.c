#include "push_swap.h"

void	assign_pos(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->top;
	while(current)
	{
		i = current->pos;
		current = current->next;
		i++;
	}
}

void	assing_index(t_stack *stack)
{
	int		index;
	t_node	*current;
	t_node	*min;
	int		min_val;

	index = 0;
	while (index < stack->size)
	{
		min = NULL;
		current = stack->top;
		min_val = INT_MAX;
		while(current)
		{
			if(current->index == -1 && current->value < min_val)
			{
				min_val = current->value;
				min = current;
			}
			current = current->next;
		}
		if (min)
			min->index = index;
		index++;	
	}
}
