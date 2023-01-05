#include "../push_swap.h"

// Swap stack
int	swap(t_node **stack)
{
    t_node  *temp;

    if (ft_lstsize(*stack) <= 1)
        return (0);
    temp = ft_lstlast(*stack) -> previous;
    ft_extract_node(stack, temp);
    ft_lstadd_back(stack, temp);
    return (1);
}

// Swap a stack and print operation
void	swap_stack(t_node **stack, char *s)
{
    if (swap(stack))
	    ft_printf("%s\n", s);
}

// Swap both stacks and pront ss
void	swap_all(t_node **stack_a, t_node **stack_b)
{
	int sa;
    int sb;

    sa = swap(stack_a);
    sb = swap(stack_b);
    if (sa || sb)
    {
        if (sa && sb)
            ft_printf("ss\n");
        else if (sa)
            ft_printf("sa\n");
        else
            ft_printf("sb\n");
    }
}