/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:59:36 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/14 18:32:20 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack **a_head, t_stack **b_head)
{
	int	group;
	int	top;
	int	size;

	top = 0;
	while (*a_head && !ft_stackisordered(*a_head))
	{
		group = ft_stacksize(*a_head) / 4 + 1;
		if (group < 32)
			group = 32;
		top += group;
		size = group / 2 - 1;
		transfer_pair(a_head, b_head, top, size);
	}
	while (largest_order(*a_head) != ft_stacklast(*a_head)->order)
		rev_rotate_a(a_head);
}

void	transfer_pair(t_stack **a_head, t_stack **b_head, int top, int size)
{
	int	buffer;
	int	transferred;

	buffer = 0;
	transferred = 0;
	while (*a_head && !ft_stackisordered(*a_head) && transferred < size * 2)
	{
		if ((*a_head)->order < top)
		{
			if ((*a_head)->order >= top - size)
				while (buffer > 0 && buffer--)
					rotate_b(b_head);
			else
				buffer++;
			push_b(a_head, b_head);
			transferred++;
		}
		else
			eff_rotate(a_head, b_head, &buffer);
	}
	while (!ft_stackisordered(*a_head) && buffer != size * 2 && buffer-- > 0)
		rotate_b(b_head);
}

void	eff_rotate(t_stack **a_head, t_stack **b_head, int *lower_bound)
{
	if (*lower_bound > 0)
	{
		rotate_r(a_head, b_head);
		--*lower_bound;
	}
	else
		rotate_a(a_head);
}
