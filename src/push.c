#include "../inc/push_swap.h"

// Push a node from source to target
int	push(t_node **source, t_node **target)
{
	t_node  *temp;

    if (ft_lstsize(*source) < 1)
        return (0);
    temp = *source;
    ft_extract_node(source, temp);
    ft_lstadd_front(target, temp);
    return (1);
}

// Push a node from source to target and print opertion
void	push_node(t_node **source, t_node **target, char *s)
{
    if (push(source, target))
	    ft_printf("%s\n", s);
}
