#include "../push_swap.h"

// Counts the size of the list
int	ft_lstsize(t_node *list)
{
	int		size;
	t_node	*temp;

	temp = list;
	size = 0;
	while (temp)
	{
		temp = temp -> next;
		size++;
	}
	return (size);
}

// Deletes a specific node from the list
void	ft_lstdel_node(t_node **head, t_node *node)
{
	if (!node)
		return ;
	if (node -> previous || node -> next)
	{
		if (node -> previous)
			node -> previous -> next = node -> next;
		if (node -> next && node -> previous)
			node -> next -> previous = node -> previous;
	}
	if (!(node -> previous))
	{
		(*head) = node -> next;
		(*head) -> previous = NULL;
	}
	free(node);
}

t_node	*ft_extract_node(t_node **head, t_node *node)
{
	if (!node)
		return (NULL);
	if (node -> previous || node -> next)
	{
		if (node -> previous)
			node -> previous -> next = node -> next;
		if (node -> next && node -> previous)
			node -> next -> previous = node -> previous;
	}
	if (!(node -> previous))
	{
		(*head) = node -> next;
		(*head) -> previous = NULL;
	}
	node -> next = NULL;
	node -> previous = NULL;
	return (node);
}

// Deletes all nodes of a list
void	ft_lstclear(t_node **head)
{
	t_node	*temp;

	while (head && *head)
	{
		temp = (*head) -> next;
		ft_lstdel_node(head, *head);
		*head = temp;
	}
}

t_node	*ft_lstlast(t_node *head)
{
	while (head -> next)
		head = head -> next;
	return (head);
}