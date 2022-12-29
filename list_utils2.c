#include "push_swap.c"

void	ft_lstdel_node(t_node *node)
{
	if (!node)
		return ;
	free(head);
}

void	ft_lstclear(t_node **head)
{
	t_list	*temp;

	while (head && *head)
	{
		temp = (*head)-> next;
		ft_lstdel_node(*head);
		*head = temp;
	}
}
