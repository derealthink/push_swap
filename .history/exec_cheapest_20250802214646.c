#include "push_swap.h"

void debug_costs(t_stack *a) {
    t_node *current = a->top;
    printf("=== COSTS ===\n");
    while (current) {
        printf("Node %d: pos=%d, abm=%d, cost=%d, target=%d\n", 
               current->value, current->pos, current->abm, 
               current->cost, current->target ? current->target->value : -999);
        current = current->next;
    }
    printf("=============\n");
}

static void	prep_p(t_stack *stack, t_node *tar, char s_name)
{
	int safety = 0;
	printf("=== PREP_P START (stack %c, target %d) ===\n", s_name, tar ? tar->value : -999);
	
	if (!stack || !tar) {
		printf("ERROR: NULL stack or target in prep_p\n");
		return;
	}
	
	while(stack->top != tar && safety < stack->size * 2)
	{
		printf("Current top: %d, target: %d, abm: %d\n", 
		       stack->top->value, tar->value, tar->abm);
		
		if (s_name == 'a')
		{
			if (tar->abm) {
				printf("Doing ra\n");
				ra(stack);
			} else {
				printf("Doing rra\n");
				rra(stack);
			}
		}
		else if (s_name == 'b')
		{
			if (tar->abm) {
				printf("Doing rb\n");
				rb(stack);
			} else {
				printf("Doing rrb\n");
				rrb(stack);
			}
		}
		safety++;
	}
	
	if (safety >= stack->size * 2) {
		printf("ERROR: Infinite loop in prep_p!\n");
	}
	printf("=== PREP_P DONE ===\n");
}

void	pa_greedy(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	printf("=== PA_GREEDY START ===\n");
	cheapest = get_cheapest_node(a);
	printf("Cheapest node: %d, target: %d\n", 
	       cheapest->value, cheapest->target->value);
	
	if (cheapest->abm && cheapest->target->abm) {
		printf("Both above median - calling rotate_both\n");
		rotate_both(a, b, cheapest);
	} else if (!(cheapest->abm) && !(cheapest->target->abm)) {
		printf("Both below median - calling rev_rotate_both\n");
		rev_rotate_both(a, b, cheapest);
	} else {
		printf("Different directions - no simultaneous rotation\n");
	}
	
	assign_pos(a);
	assign_pos(b);
	printf("About to call prep_p for A\n");
	prep_p(a, cheapest, 'a');
	printf("About to call prep_p for B\n");
	prep_p(b, cheapest->target, 'b');
	printf("About to call pb\n");
	pb(a, b);
	printf("=== PA_GREEDY DONE ===\n");
}

void	pb_greedy(t_stack *a, t_stack *b)
{
	t_node	*current;

	printf("=== PB_GREEDY START ===\n");
	current = b->top;
	printf("Moving node %d from B to A, target: %d\n", 
	       current->value, current->target ? current->target->value : -999);
	
	if (!current->target) {
		printf("ERROR: Node %d has no target!\n", current->value);
		return;
	}
	
	prep_p(a, current->target, 'a');
	printf("About to call pa\n");
	pa(a, b);
	printf("=== PB_GREEDY DONE ===\n");
}