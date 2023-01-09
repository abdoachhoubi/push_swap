#include "../inc/push_swap.h"

void	ft_print_list(t_node *stack)
{
	ft_printf("[");
	while (stack)
	{
		ft_printf("%d,\t", stack -> value);
		stack = stack -> next;
	}
	ft_printf("]\n");
}

void	fill_stack(t_node **head, char **args, int len)
{
	int		i;
	t_node	*temp;

	i = 1;
	*head = ft_lstnew(ft_atoi(args[i++]));
	while (i < len)
	{
		temp = ft_lstnew(ft_atoi(args[i++]));
		if (! temp)
			message_free(RED"Error:\nNode allocation failed\n"RESET, head);
		ft_lstadd_back(head, temp);
	}
}
