/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:29:12 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/18 21:43:42 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		write(2, "Error\n", 6);
		return (0);
	}
	b_stack = NULL;
	if (ft_stacksize(a_stack) > 31)
		quick_sort(&a_stack, &b_stack);
	solve_five(&a_stack, &b_stack);
	insertion_sort(&a_stack, &b_stack);
	while (largest_order(a_stack) != ft_stacklast(a_stack)->order)
		rev_rotate_a(&a_stack);
	ft_stackclear(&a_stack);
	ft_stackclear(&b_stack);
	return (0);
}
