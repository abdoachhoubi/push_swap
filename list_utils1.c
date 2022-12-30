#include "./push_swap.h"

// Create a new list
t_node	*ft_lstnew(int value)
{
	t_node	*list;

	list = (t_node *)malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list -> value = value;
	list -> previous = NULL;
	list -> next = NULL;
	return (list);
}

void	ft_lstadd_back(t_node **head, t_node *node)
{
	t_node	*temp;

	temp = *head;
	if (!*head)
		*head = node;
	else
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = node;
		node -> previous = temp;
	}
}

void	ft_lstadd_front(t_node **head, t_node *node)
{
	if (head && node)
	{
		node -> next = *head;
		node -> previous = NULL;
	}
	if (node)
		*head = node;
}

int	ft_lstsize(t_node *list)
{
	int		size;
	t_node	*temp;

	temp = list;
	size = 0;
	while (temp -> next)
	{
		temp = temp -> next;
		size++;
	}
	return (size);
}
