#include "../push_swap.h"

// Swap stack
int	swap(t_node **stack)
{
    t_node  *last_node;
    t_node  *last_node_prev;
    t_node  *last_node_prev_prev;

    if (ft_lstsize(*stack) <= 1)
        return (-1);
    last_node = ft_lstlast(*stack);
    last_node_prev = last_node -> previous;
    last_node_prev_prev = last_node_prev -> previous;
    if (last_node_prev_prev)
    {
        ft_printf(YELLOW"INSIDE THE CONDITION\n"RESET);
        last_node_prev_prev -> next = last_node;
        last_node -> previous = last_node_prev_prev;
    }
    ft_printf(GREEN"LIST SIZE ----> %d\n"RESET, ft_lstsize(*stack));
    last_node -> next = last_node_prev;
    last_node_prev -> previous = last_node;
    last_node_prev -> next = NULL;
    ft_printf(RED"%d\n"RESET, last_node_prev -> value);
    return (1);
}

// Swap a stack and print operation
void	swap_stack(t_node **stack, char *s)
{
    if (swap(stack) != -1)
	    ft_printf("%s\n", s);
}

// Swap both stacks and pront ss
void	swap_all(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}