#include "../push_swap.h"

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

// Adds a new node to the back
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

// Adds a new node to the head
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
