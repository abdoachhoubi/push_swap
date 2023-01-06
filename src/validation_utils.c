#include "../inc/push_swap.h"

long long   ft_atol(char *s)
{
	long long   res;
	int         sign;
	int         i;

	if (!s)
		return (0);
	sign = 1;
	res = 0;
	i = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res *= 10;
		res += s[i] - 48;
		i++;
	}
	return (res * sign);
}

int valid_int(long long n)
{
	if (n >= -2147483648 && n <= 2147483647)
		return (1);
	return (0);
}

int validate_args(char **args, int len)
{
	int i;
	int valid;

	i = 1;
	valid = 1;
	while (i < len)
	{
		if (!valid_int(ft_atol(args[i])))
			valid = 0;
		i++;
	}
	return (valid);
}

void	check_duplicates(t_node *stack)
{
	t_node	*stack_temp1;
	t_node	*stack_temp2;
	int		temp;
	int		count;

	stack_temp1 = stack;
	while (stack_temp1)
	{
		count = 0;
		temp = stack_temp1 -> value;
		stack_temp2 = stack;
		while (stack_temp2)
		{
			if (stack_temp2 -> value == temp)
				count++;
			stack_temp2 = stack_temp2 -> next;
		}
		if (count != 1)
			message_error(RED"Error:\nDuplicate number -_-"RESET);
		stack_temp1 = stack_temp1 -> next;
	}
}