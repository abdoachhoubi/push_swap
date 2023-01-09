#include "../inc/push_swap.h"

// Push a node from source to target
int	push(t_node **source, t_node **target)
{
	t_node  *new;

    if (*source == NULL)
        return (0);
    new = ft_lstnew((*source) -> value);
    ft_lstdel_node(source, *source);
    ft_lstadd_front(target, new);
    return (1);
}

// Push a node from source to target and print opertion
void	push_node(t_node **source, t_node **target, char *s)
{
    if (push(source, target))
	    ft_printf("%s\n", s);
}
