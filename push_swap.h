#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// C Standard library
# include <unistd.h>
# include <stdlib.h>

// Third party libraries
# include "./ft_printf/ft_printf.h"

// DLL Struct
typedef	struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

// Sorting Utils
void	swap(t_node *stack);
void	rotate(t_node *stack);
void	reverse(t_node *stack);
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

// List Utils
t_list	*ft_lstnew(int	value);
void    ft_lstadd_back(t_node **list, t_node *node);
void	ft_lstadd_front(t_node **list, t_node *node);
int		ft_lstsize(t_node *list);
void	ft_lstdel_node(t_node **list, t_node *node);
void	ft_lstclear(t_node **list);

#endif