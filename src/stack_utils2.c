#include "../inc/push_swap.h"


// Deletes a node from the satck
void	ft_lstdel_node(t_node **head, t_node *node)
{
    if (*head == NULL || node == NULL)
        return;
    if (*head == node)
        *head = node->next;
    if (node->next != NULL)
        node->next->previous = node->previous;
    if (node->previous != NULL)
        node->previous->next = node->next;
    free(node);
}

// Extracts a node from the stack
t_node	*ft_extract_node(t_node **head, t_node *node)
{
	t_node	*new;

	new = ft_lstnew(node -> value);
	if (!new)
		message_free(RED"Error:\nMemory allocation failed!"RESET, head);
	ft_lstdel_node(head, node);
	return (new);
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