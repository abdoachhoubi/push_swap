#include "../push_swap.h"

// Reverse Rotate stack
int	reverse(t_node **stack)
{
	t_node  *temp;

    if (ft_lstsize(*stack) <= 1)
        return (0);
    temp = ft_lstlast(*stack);
    temp -> previous -> next = NULL;
    ft_extract_node(stack, temp);
    ft_lstadd_front(stack, temp);
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