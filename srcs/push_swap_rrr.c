/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:55:44 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/12 06:56:12 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stack **head)
{
	t_stack	*temp;

	if (!(*head) && !(*head)->next)
		return ;
	temp = ft_stacklast((*head));
	temp->next = (*head);
	while ((*head)->next != temp)
		(*head) = (*head)->next;
	(*head)->next = NULL;
	(*head) = temp;
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rev_rotate_b(t_stack **head)
{
	t_stack	*temp;

	if (!(*head) && !(*head)->next)
		return ;
	temp = ft_stacklast((*head));
	temp->next = (*head);
	while ((*head)->next != temp)
		(*head) = (*head)->next;
	(*head)->next = NULL;
	(*head) = temp;
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rev_rotate_r(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if ((*a_head) && (*a_head)->next)
	{
		temp = ft_stacklast((*a_head));
		temp->next = (*a_head);
		while ((*a_head)->next != temp)
			(*a_head) = (*a_head)->next;
		(*a_head)->next = NULL;
		(*a_head) = temp;
	}
	if ((*b_head) && (*b_head)->next)
	{
		temp = ft_stacklast((*b_head));
		temp->next = (*b_head);
		while ((*b_head)->next != temp)
			(*b_head) = (*b_head)->next;
		(*b_head)->next = NULL;
		(*b_head) = temp;
	}
	write(STDOUT_FILENO, "rrr\n", 4);
}
