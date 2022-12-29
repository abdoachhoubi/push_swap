#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

// Utils
void	swap_a(t_node *stack);
void	swap_b(t_node *stack);
void	swap_all(t_node *stack_a, t_node *stack_b);
void	push_to_a(t_node *stack_a, t_node *stack_b);
void	push_to_b(t_node *stack_a, t_node *stack_b);
void	rotate_a(t_node *stack_a);
void	rotate_b(t_node *stack_b);
void	rotate_all(t_node *stack_a, t_node *stack_b);
void	reverse_a(t_node *stack_a);
void	reverse_b(t_node *stack_b);
void	reverse_all(t_node *stack_a, t_node *stack_b);

#endif