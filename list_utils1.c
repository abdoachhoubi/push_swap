#include "./push_swap.h"

// Create a new list
t_list	*ft_lstnew(int value)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> value = value;
	list -> previous = NULL;
	list -> next = NULL;
	return (list);
}

void	ft_lstadd_back(t_node **head, t_node *node)
{
	t_list	*temp;

	temp = *head;
	if (!*head)
		*head = node;
	else
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = node;
	}
}

void	ft_lstadd_front(t_node **head, t_node *node)
{
	if (head && node)
		node -> next = *head;
	if (node)
		*head = node;
}

int	ft_lstsize(t_node *list)
{
	int		size;

	temp = list;
	size = 0;
	while (temp -> next)
	{
		temp = temp -> next;
		size++;
	}
	return (size);
}
