/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:44:42 by zyeoh             #+#    #+#             */
/*   Updated: 2024/05/03 17:29:25 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **head)
{
	t_stack	*temp;

	if (!(*head) && !(*head)->next)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = (*head);
	(*head) = temp;
	write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_stack **head)
{
	t_stack	*temp;

	if (!(*head) && !(*head)->next)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = (*head);
	(*head) = temp;
	write(STDOUT_FILENO, "sb\n", 3);
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
	write(STDOUT_FILENO, "s\n", 3);
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
	write(STDOUT_FILENO, "pa\n", 3);
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
	write(STDOUT_FILENO, "pb\n", 3);
}
