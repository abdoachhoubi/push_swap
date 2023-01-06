#include "../inc/push_swap.h"

void    message_error(char *s)
{
    ft_putendl_fd(s, 2);
    exit(EXIT_FAILURE);
}

void    message_free(char *message, t_node **head)
{
    ft_lstclear(head);
    message_error(message);
}
