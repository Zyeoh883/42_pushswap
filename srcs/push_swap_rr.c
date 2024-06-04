/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:16:07 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/12 06:56:06 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **head)
{
	t_stack	*temp;

	if (!(*head) && !(*head)->next)
		return ;
	temp = ft_stacklast((*head));
	temp->next = (*head);
	(*head) = (*head)->next;
	temp = temp->next;
	temp->next = NULL;
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_stack **head)
{
	t_stack	*temp;

	if (!(*head) && !(*head)->next)
		return ;
	temp = ft_stacklast((*head));
	temp->next = (*head);
	(*head) = (*head)->next;
	temp = temp->next;
	temp->next = NULL;
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_r(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if ((*a_head) && (*a_head)->next)
	{
		temp = ft_stacklast((*a_head));
		temp->next = (*a_head);
		(*a_head) = (*a_head)->next;
		temp = temp->next;
		temp->next = NULL;
	}
	if ((*b_head) && (*b_head)->next)
	{
		temp = ft_stacklast((*b_head));
		temp->next = (*b_head);
		(*b_head) = (*b_head)->next;
		temp = temp->next;
		temp->next = NULL;
	}
	write(STDOUT_FILENO, "rr\n", 3);
}
