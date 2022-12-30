#include "../push_swap.h"

int main()
{
    t_node  *head = ft_lstnew(0);
    t_node  *lst1 = ft_lstnew(1);
    t_node  *lst2 = ft_lstnew(2);
    t_node  *lst3 = ft_lstnew(3);

    ft_lstadd_back(&head, lst1);
    ft_lstadd_back(&head, lst2);
    ft_lstadd_back(&head, lst3);
    ft_lstdel_node(lst2);
    ft_printf("MAIN: %d\n", lst1 -> next -> value);
    return (0);
}