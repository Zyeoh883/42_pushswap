/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:01:23 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/18 23:46:11 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stack **head, t_stack **redundant)
{
	t_stack	*temp;

	(void)redundant;
	if (!(*head) || !(*head)->next)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = (*head);
	(*head) = temp;
}

void	swap_b(t_stack **redundant, t_stack **head)
{
	t_stack	*temp;

	(void)redundant;
	if (!(*head) || !(*head)->next)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = (*head);
	(*head) = temp;
}

void	swap_s(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if ((*a_head) && (*a_head)->next)
	{
		temp = (*a_head)->next;
		(*a_head)->next = temp->next;
		temp->next = (*a_head);
		(*a_head) = temp;
	}
	if ((*b_head) && (*b_head)->next)
	{
		temp = (*b_head)->next;
		(*b_head)->next = temp->next;
		temp->next = (*b_head);
		(*b_head) = temp;
	}
}

void	push_a(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if (!(*b_head))
		return ;
	temp = (*b_head);
	(*b_head) = (*b_head)->next;
	temp->next = NULL;
	if (!(*a_head))
		(*a_head) = temp;
	else
		ft_stackadd_front(&(*a_head), temp);
}

void	push_b(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if (!(*a_head))
		return ;
	temp = (*a_head);
	(*a_head) = (*a_head)->next;
	temp->next = NULL;
	if (!(*b_head))
		(*b_head) = temp;
	else
		ft_stackadd_front(&(*b_head), temp);
}
