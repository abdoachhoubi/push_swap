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
	t_node	*head;
	t_node	*temp;
	int		i;
	i = 1;

	head = ft_lstnew(0);
	while (i < 10)
	{
		temp = ft_lstnew(i);
		ft_lstadd_back(&head, temp);
		i++;
	}
	free(temp);
	ft_print_list(head);
	swap_stack(&head, "sa");
	ft_print_list(head);
	system("leaks push_swap");
	return (0);
}