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

void	sort_stack(t_node **stack_a, t_node	**stack_b)
{
	// DEBUGGING Starts
	ft_printf(RED"---------------------------------------------------\n"RESET);
	// DEV Printing stacks
	ft_printf("stack_a =\t");
	ft_print_list(*stack_a);
	ft_printf("stack_b =\t");
	ft_print_list(*stack_b);

	// DEV Testing operations
	swap_stack(stack_a, "sa");
	push_node(stack_a, stack_b, "pb");
	push_node(stack_a, stack_b, "pb");
	rotate_stack(stack_b, "rb");
	reverse_stack(stack_b, "rrb");

	// DEV Printing stacks
	ft_printf("stack_a =\t");
	ft_print_list(*stack_a);
	ft_printf("stack_b =\t");
	ft_print_list(*stack_b);
	ft_printf(RED"---------------------------------------------------\n"RESET);
	// DEBUGGING Ends
}

int	main(int ac, char **av)
{
	t_node	*stack_b;
	t_node	*stack_a;

	if (ac > 1)
	{
		if (!validate_args(av, ac))
			message_error(RED"Error:\npush_swap only accept int values"RESET);
		fill_stack(&stack_a, av, ac);
		check_duplicates(stack_a);
		if (check_sorted(stack_a))
		{
			ft_printf(GREEN"Stack Sorted\n"RESET);
			exit(1);
		}
		sort_stack(&stack_a, &stack_b);
	}
	else
		message_error(RED"Error:\nNot enough arguments"RESET);
	
	// DEBUGGING Start
	// DEV Checking leaks
	system("leaks push_swap");
	// DEBUGGING End
	return (0);
}