#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	first->prev = stack->bottom;
	stack->bottom->next = first;
	stack->bottom = first;
}
void	ra(t_stack *a)
{
	rotate(a);
	printf("ra\n");
}
void	rb(t_stack *b)
{
	rotate(b);
	printf("rb\n");
}
void	rr(t_stack *a, t_stack *b)
{
	rotate (a);
	rotate (b);
	printf("rr\n");
}
void 	rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = a->top;
	current_b = b->top;
	while (current_b != cheapest->target && current_a != cheapest)
	{	
		rr(a, b);
		current_a = current_a->next;
		current_b = current_b->next;
	}

	assign_pos(a);
	assign_pos(b);
}