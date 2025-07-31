#include "push_swap.h"

t_stack	*sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->value;
	if (a > b && b < c)
		sa(&stack);
	if (a > b && b > c)
		rra
}
