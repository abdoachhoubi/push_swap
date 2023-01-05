#include "./push_swap.h"

long long ft_atol(char *s)
{
	long long	res;
	int			sign;
	int			i;

	if (!s)
		message_error("Passed NULL To function ft_atol");
	i = 0;
	sign = 1;
	res = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res *= 10;
		res += s[i++] - 48;
	}
	return (res * sign);
}


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

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*temp;
	int		i;

	// NOTE Filling stack a
	i = 1;
	stack_a = ft_lstnew(0);
	while (i < 10)
	{
		temp = ft_lstnew(i);
		ft_lstadd_back(&stack_a, temp);
		i++;
	}

	// NOTE Filling stack b
	i = -1;
	stack_b = ft_lstnew(0);
	while (i > -10)
	{
		temp = ft_lstnew(i);
		ft_lstadd_back(&stack_b, temp);
		i--;
	}

	ft_printf(RED"\n--------------------------------------\n\n"RESET);
	// NOTE Printing both stacks
	ft_printf(RED"Printing stack_a\n"RESET);
	ft_print_list(stack_a);
	ft_printf(RED"Printing stack_b\n"RESET);
	ft_print_list(stack_b);

	// NOTE Testing utils
	// DEBUGGING a = [null, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, null]
	swap_stack(&stack_a, "sa");
	// DEBUGGING a = [null, 0, 1, 2, 3, 4, 5, 6, 7, 9, 8, null]
	// swap_stack(&stack_a, "sa");

	// NOTE Printing both stacks
	ft_printf(RED"Printing stack_a\n"RESET);
	ft_print_list(stack_a);
	ft_printf(RED"Printing stack_b\n"RESET);
	ft_print_list(stack_b);
	ft_printf(RED"\n--------------------------------------\n\n"RESET);

	// NOTE Checking leaks
	system("leaks push_swap");

	// NOTE End of program
	return (0);
}