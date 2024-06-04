/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:08:32 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/14 18:12:38 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	largest_depth(t_stack *stack, int depth)
{
	int	largest;
	int	index;
	int	i;

	largest = 0;
	i = -1;
	if (ft_stacksize(stack) < depth)
		return (0);
	while (++i < depth && stack)
	{
		if (stack->order > largest)
		{
			largest = stack->order;
			index = i;
		}
		stack = stack->next;
	}
	return (index);
}

void	solve_two(t_stack **stack)
{
	if (!(*stack)->next)
		return ;
	if ((*stack)->order > ((*stack)->next)->order)
		swap_a(stack);
}

void	solve_three(t_stack **stack)
{
	int	largest_index;

	if (ft_stackisordered(*stack))
		return ;
	if (ft_stacksize(*stack) > 2)
	{
		largest_index = largest_depth(*stack, 3);
		if (largest_index == 0)
			rotate_a(stack);
		else if (largest_index == 1)
			rev_rotate_a(stack);
	}
	solve_two(stack);
}

void	solve_five(t_stack **a_head, t_stack **b_head)
{
	while (ft_stacksize(*a_head) > 3)
	{
		if (ft_stackisordered(*a_head))
			return ;
		push_b(a_head, b_head);
	}
	solve_three(a_head);
}
