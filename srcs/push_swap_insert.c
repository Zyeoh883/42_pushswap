/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:48:44 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/14 18:06:21 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **a_head, t_stack **b_head)
{
	int	index;
	int	max_order;

	while (largest_order(*a_head) != ft_stacklast(*a_head)->order)
		rev_rotate_a(a_head);
	max_order = ft_stacksize(*a_head) + ft_stacksize(*b_head);
	while (*b_head)
	{
		index = largest_depth(*b_head, ft_stacksize(*b_head));
		if (index > ft_stacksize(*b_head) / 2)
			insert_runs(a_head, b_head, max_order, rev_rotate_b);
		else
			insert_runs(a_head, b_head, max_order, rotate_b);
	}
}

void	insert_runs(t_stack **a_head, t_stack **b_head, int max_order,
		void (*spin)(t_stack **))
{
	int	b_largest;

	b_largest = largest_order(*b_head);
	while ((*b_head)->order != b_largest)
	{
		sort_runs(a_head, b_head, max_order, b_largest);
		if ((*b_head)->order != b_largest)
		{
			if (spin == rotate_b && (*a_head)->order < b_largest
				&& b_largest != max_order)
				rotate_r(a_head, b_head);
			else if (spin == rev_rotate_b
				&& ft_stacklast(*a_head)->order != max_order
				&& ft_stacklast(*a_head)->order > b_largest)
				rev_rotate_r(a_head, b_head);
			else
				spin(b_head);
		}
	}
	while ((*a_head)->order < b_largest && b_largest != max_order)
		rotate_a(a_head);
	while (ft_stacklast(*a_head)->order > b_largest
		&& ft_stacklast(*a_head)->order != max_order)
		rev_rotate_a(a_head);
	push_a(a_head, b_head);
}

void	sort_runs(t_stack **a_head, t_stack **b_head, int max_order,
		int b_largest)
{
	int	upper_bound;
	int	lower_bound;

	if ((*b_head)->order == b_largest)
		return ;
	upper_bound = ft_stacklast(*a_head)->order;
	if (upper_bound == max_order)
		upper_bound = 0;
	lower_bound = (*a_head)->order;
	while (upper_bound < (*b_head)->order && (*b_head)->order < lower_bound
		&& (*b_head)->order != b_largest)
	{
		lower_bound = (*b_head)->order;
		push_a(a_head, b_head);
	}
}

int	largest_order(t_stack *stack)
{
	int	largest_order;

	largest_order = 0;
	while (stack)
	{
		if (stack->order > largest_order)
			largest_order = stack->order;
		stack = stack->next;
	}
	return (largest_order);
}
