#include "../inc/push_swap.h"

// Sorts stack of 3 elements
int	short_sort(t_node **stack_a)
{
	t_node	*middle;
	
	if (ft_lstsize(*stack_a) == 2)
		swap_stack(stack_a, "sa");
	else
	{
		middle = (*stack_a) -> next;
		if (((*stack_a) -> value) > (middle -> next -> value))
			rotate_stack(stack_a, "ra");
		else if (((*stack_a) -> value) > (middle -> value))
			swap_stack(stack_a, "sa");
		else
			reverse_stack(stack_a, "rra");
	}
	return (check_sorted(*stack_a));
}

void	sort_stack(t_node **stack_a, t_node	**stack_b)
{
	int	size;
	int	sorted;

	size = ft_lstsize(*stack_a);
	sorted = 0;
	if (size <= 3)
	{
		while (!sorted)
			sorted = short_sort(stack_a);
	}
	// else if (size <= 5)
	// 	mini_sort(stack_a, stack_b);
	// else if (size <= 100)
	// 	medium_sort(stack_a, stack_b);
	// else if (size <= 500)
	// 	big_sort(stack_a, stack_b);
	// if (check_sorted(*stack_a))
	// 	exit(EXIT_SUCCESS);
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
			exit(EXIT_SUCCESS);
		sort_stack(&stack_a, &stack_b);
		ft_print_list(stack_a);
	}
	// DEBUGGING Start
	// DEV Checking leaks
	// system("leaks push_swap");
	// DEBUGGING End
	return (0);
}