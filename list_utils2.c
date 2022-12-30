#include "push_swap.c"

void	ft_lstdel_node(t_node *node)
{
	if (!node)
		return ;
	// ft_printf("DEL : %d\n", node -> previous -> value);
	node -> previous -> next = node -> next;
	free(node);
}

void	ft_lstclear(t_node **head)
{
	t_node	*temp;

	while (head && *head)
	{
		temp = (*head)-> next;
		ft_lstdel_node(*head);
		*head = temp;
	}
}
