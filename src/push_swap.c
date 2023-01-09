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

t_node	*smallest_node(t_node *head)
{
	t_node	*smallest;

	smallest = head -> next;
	while (head && smallest)
	{
		if (head -> value < smallest -> value)
			smallest = head;
		else
			smallest = head;
		head = head -> next;
	}
	return (smallest);
}

void	move_smallest_to_top(t_node **stack, t_node *smallest)
{
	t_node *temp;

	ft_printf(RED"smallest -> %d\n"RESET, smallest -> value);
	temp = *stack;
	while (temp && ((temp -> value) != (smallest -> value)))
		rotate_stack(stack, "ra");
	ft_print_list(*stack);
}

// Sorts a stack that contains 5 or less nodes
void	mini_sort(t_node **stack_a, t_node **stack_b)
{
	int	sorted;
	int	size;
	int	i;
	t_node *temp;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size)
	{
		temp = smallest_node(*stack_a);
		move_smallest_to_top(stack_a, temp);
		// push_node(stack_a, stack_b, "pb");
		i++;
	}
	while (*stack_b)
		push_node(stack_b, stack_a, "pa");
}

// Sorts a stack
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
	else if (size <= 5)
	{
		mini_sort(stack_a, stack_b);
		// ft_printf(GREEN"smallest -> %d\n"RESET, smallest_node(*stack_a) -> value);
	}
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