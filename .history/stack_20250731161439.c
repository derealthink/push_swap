#include "push_swap.h"

void	assign_pos(t_stack *stack)
{
	t_node	*current;
	int	i;
	int	median;

	i = 0;
	if(!stack)
		return ;
	median = stack->size / 2;
	current = stack->top;
	while(current)
	{
		i = current->pos;
		if (i <= median)
			current->abm = true;
		else
			current->abm = false;
		current = current->next;
		i++;
	}
}

void	assign_index(t_stack *stack)
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

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if(!stack)
		return(0);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
