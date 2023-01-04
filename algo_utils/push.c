#include "../push_swap.h"

// Push a node from source to target
int	push(t_node **source, t_node **target)
{
	ft_printf("\n\n----> Push\n\tinvoked\n");
    return (0);
}

// Push a node from source to target and print opertion
void	push_node(t_node **source, t_node **target, char *s)
{
	ft_printf("%s\n", s);
    push(source, target);
}
