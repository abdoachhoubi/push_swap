#include "../push_swap.h"

// Reverse Rotate stack
int	reverse(t_node **stack)
{
	ft_printf("\n\n----> Reverse\n\tinvoked\n");
    return (0);
}

// Reverse rotate a stack and print operation
void	reverse_stack(t_node **stack, char *s)
{
    reverse(stack);
	ft_printf("%s\n", s);
}

// Reverse both stacks and print rrr
void	reverse_all(t_node **stack_a, t_node **stack_b)
{
    reverse(stack_a);
    reverse(stack_b);
	ft_printf("rrr\n");
}