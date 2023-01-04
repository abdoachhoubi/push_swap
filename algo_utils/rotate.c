#include "../push_swap.h"

// Rotates a stack
int	rotate(t_node **stack)
{
    t_node  *temp;

	if (ft_lstsize(*stack) <= 1)
        return (-1);
    temp = ft_lstlast(*stack);
    ft_printf("\n\n---> Rotate\n\tLast element: %d\n", temp -> value);
    return (0);
}

// Rotate a stack and print operation
void	rotate_stack(t_node **stack, char *s)
{
	rotate(stack);
	ft_printf("%s\n", s);
}

// Rotate both stacks and print rr
void	rotate_all(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}