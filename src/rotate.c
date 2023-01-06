#include "../inc/push_swap.h"

// Rotates a stack
int	rotate(t_node **stack)
{
    t_node  *temp;

	if (ft_lstsize(*stack) <= 1)
        return (0);
	temp = *stack;
	ft_extract_node(stack, *stack);
	ft_lstadd_back(stack, temp);
    return (1);
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
	int	ra;
	int	rb;

	ra = rotate(stack_a);
	rb = rotate(stack_b);
	if (ra || rb)
	{
		if (ra && rb)
			ft_printf("rr\n");
		else if (ra)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}