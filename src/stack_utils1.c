#include "../inc/push_swap.h"

// Create a new node
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

// Adds a new node to the front of the stack
void ft_lstadd_front(t_node **head, t_node *node)
{
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    (*head)->previous = node;
    node->next = *head;
    *head = node;
}

// Adds a new node to the back of the stack
void ft_lstadd_back(t_node **head, t_node *node)
{
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    t_node *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = node;
    node->previous = curr;
}

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
