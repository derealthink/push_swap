#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				cost;
	bool			abm;
	struct s_node	*target;
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
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	push(t_stack *from, t_stack *to);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
long 	ft_atol_strict(char *str);
int		num_check_wq(char *str);
int		*parse_wq(char *str);
int		has_doubles(int	*arr, int count);
void	free_split(char	**split);
char	**ft_split(char *str);
int		arg_count(char *str);
int		*parse_ma(char **argv, int count);
void	assign_pos(t_stack *stack);
void	assign_index(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_three(t_stack *stack);
void	set_target_ab(t_stack *a, t_stack *b);
void	calculate_cost_a(t_stack *a);
void	calculate_cost_b(t_stack *b);
t_node	*get_cheapest_node(t_stack *a);
void	execute_move(t_stack *a, t_stack *b, t_node *node);




#endif
