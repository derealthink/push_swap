#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

void	init_stack(t_stack *stack);
t_node	*create_node(int value);
void	push_bottom(t_stack *stack, t_node *n);
void	print_stack(t_stack *stack, char name);
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
long 	ft_atol_strict(char *str);




#endif
