/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:03:03 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/18 23:34:05 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_stack **head, t_stack **redundant)
{
	t_stack	*temp;

	(void)redundant;
	if (!(*head) || !(*head)->next)
		return ;
	temp = ft_stacklast((*head));
	temp->next = (*head);
	(*head) = (*head)->next;
	temp = temp->next;
	temp->next = NULL;
}

void	rotate_b(t_stack **redundant, t_stack **head)
{
	t_stack	*temp;

	(void)redundant;
	if (!(*head) || !(*head)->next)
		return ;
	temp = ft_stacklast((*head));
	temp->next = (*head);
	(*head) = (*head)->next;
	temp = temp->next;
	temp->next = NULL;
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
}
