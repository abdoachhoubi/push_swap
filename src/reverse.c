#include "../inc/push_swap.h"

// Reverse Rotate stack
int	reverse(t_node **stack)
{
	t_node*	new;
	t_node* last;

	if (*stack == NULL || (*stack)->next == NULL)
		return(0);
	last = ft_lstlast(*stack);
	new = ft_lstnew(last -> value);
	ft_lstdel_node(stack, last);
	ft_lstadd_front(stack, new);
	return (1);
}

// Reverse rotate a stack and print operation
void	reverse_stack(t_node **stack, char *s)
{
	if (reverse(stack))
		ft_printf("%s\n", s);
}

// Reverse both stacks and print rrr
void	reverse_all(t_node **stack_a, t_node **stack_b)
{
	int ra;
	int rb;

	ra = reverse(stack_a);
	rb = reverse(stack_b);
	if (ra || rb)
	{
		if (ra && rb)
			ft_printf("rrr\n");
		else if (ra)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}