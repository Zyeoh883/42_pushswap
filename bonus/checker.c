/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:00:21 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/19 12:51:50 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_showstack(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		ft_putnbr_fd(lst->content, 1);
		ft_putstr_fd(", ", 1);
		temp = lst->next;
		lst = temp;
	}
	ft_putchar_fd('\n', 1);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (ac == 1)
		return (0);
	a_stack = init_stack(av);
	if (!init_order_num(a_stack))
	{
		ft_stackclear(&a_stack);
		write(STDERR_FILENO, "Error\n", 6);
		return (-1);
	}
	b_stack = NULL;
	if (input_operations(&a_stack, &b_stack))
	{
		if (ft_stackisordered(a_stack) && ft_stacksize(b_stack) == 0)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	else
		write(STDERR_FILENO, "Error\n", 6);
	ft_stackclear(&a_stack);
	ft_stackclear(&b_stack);
	return (0);
}

int	input_operations(t_stack **a_head, t_stack **b_head)
{
	char	*str;
	int		operand;

	operand = 1;
	while (operand > 0)
	{
		str = get_next_line(STDIN_FILENO);
		operand = check_valid_operation(str);
		free(str);
		if (operand < 0)
			return (0);
		execute_operand(a_head, b_head, operand);
	}
	return (1);
}

int	check_valid_operation(char *str)
{
	int		index;
	char	*operations[12];

	if (!str)
		return (0);
	if (*str == '\n' || ft_strlen(str) < 3)
		return (-1);
	operations[0] = "sa\n";
	operations[1] = "sb\n";
	operations[2] = "ss\n";
	operations[3] = "pa\n";
	operations[4] = "pb\n";
	operations[5] = "ra\n";
	operations[6] = "rb\n";
	operations[7] = "rr\n";
	operations[8] = "rra\n";
	operations[9] = "rrb\n";
	operations[10] = "rrr\n";
	operations[11] = NULL;
	index = -1;
	while (operations[++index] != NULL)
		if (ft_strncmp(str, operations[index], ft_strlen(str)) == 0)
			return (index + 1);
	return (-1);
}

void	execute_operand(t_stack **a_head, t_stack **b_head, int operand)
{
	void	(*ptr[11])();

	if (!operand)
		return ;
	ptr[0] = swap_a;
	ptr[1] = swap_b;
	ptr[2] = swap_s;
	ptr[3] = push_a;
	ptr[4] = push_b;
	ptr[5] = rotate_a;
	ptr[6] = rotate_b;
	ptr[7] = rotate_r;
	ptr[8] = rev_rotate_a;
	ptr[9] = rev_rotate_b;
	ptr[10] = rev_rotate_r;
	ptr[operand - 1](a_head, b_head);
}
