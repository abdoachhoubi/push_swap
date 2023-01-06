#include "../inc/push_swap.h"

int check_sorted(t_node *stack)
{
    int    size;
    int    i;
    int    *arr;

    size = ft_lstsize(stack);
    arr = (int *)malloc(size * sizeof(int));
    if (!arr)
        message_error(RED"Error:\nAllocation failed!"RESET);
    i = 0;
    while (stack)
    {
        arr[i] = stack -> value;
        stack = stack -> next;
        i++;
    }
    i = check_arr_sorted(arr, size);
    free(arr);
    return (i);
}

int check_arr_sorted(int *arr, int n)
{
    if (n == 1 || n == 0)
        return 1;
    if (arr[n - 1] < arr[n - 2])
        return 0;
    return check_arr_sorted(arr, n - 1);
}