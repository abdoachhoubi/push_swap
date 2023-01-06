#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// C Standard library
# include <unistd.h>
# include <stdlib.h>

// OUTPUT COLORS
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define YELLOW	"\033[1m\033[33m"
# define RESET	"\033[0m"

// Third party libraries
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

// DLL Struct
typedef	struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

// Algo utils
int		push(t_node **source, t_node **target);
void	push_node(t_node **source, t_node **target, char *s);
int		reverse(t_node **stack);
void	reverse_stack(t_node **stack, char *s);
void	reverse_all(t_node **stack_a, t_node **stack_b);
int		rotate(t_node **stack);
void	rotate_stack(t_node **stack, char *s);
void	rotate_all(t_node **stack_a, t_node **stack_b);
int		swap(t_node **stack);
void	swap_stack(t_node **stack, char *s);
void	swap_all(t_node **stack_a, t_node **stack_b);

// List Utils
t_node	*ft_lstnew(int value);
void	ft_lstadd_back(t_node **list, t_node *node);
void	ft_lstadd_front(t_node **list, t_node *node);
int		ft_lstsize(t_node *list);
void	ft_lstdel_node(t_node **head, t_node *node);
void	ft_lstclear(t_node **list);
t_node	*ft_lstlast(t_node *head);
t_node	*ft_extract_node(t_node **head, t_node *node);

// Sorting utils
void	sort_stack(t_node **stack_a, t_node	**stack_b);
int		check_sorted(t_node *stack);
int		check_arr_sorted(int *arr, int n);

//	Validation utils
long long	ft_atol(char *s);
int			valid_int(long long n);
int			validate_args(char **args, int len);
void	check_duplicates(t_node *stack);

// Error handling utils
void	message_error(char *s);
void	message_free(char *message, t_node **head);

// Dev tools
void	ft_print_list(t_node *stack);
#endif