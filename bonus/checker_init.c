/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:12:36 by zyeoh             #+#    #+#             */
/*   Updated: 2024/01/25 15:13:36 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*add_to_stack(char *str, t_stack *result)
{
	t_stack	*temp;
	char	**nums;
	int		index;

	nums = ft_split(str, ' ');
	if (!nums || !*nums)
	{
		ft_stackclear(&result);
		return (0);
	}
	index = -1;
	while (nums[++index])
	{
		temp = ft_stacknew(ft_atol(nums[index]));
		if (result)
			ft_stackadd_back(&result, temp);
		else
			result = temp;
	}
	while (index > 0)
		free(nums[--index]);
	free(nums);
	return (result);
}

t_stack	*init_stack(char **arg)
{
	t_stack	*result;

	if (!check_valid(arg))
		return (NULL);
	result = NULL;
	while (*++arg)
	{
		result = add_to_stack(*arg, result);
		if (!result)
			return (0);
	}
	return (result);
}

int	init_order_num(t_stack *stack)
{
	int		order;
	long	highest;
	t_stack	*head;

	if (!stack)
		return (0);
	order = ft_stacksize(stack);
	while (order > 0)
	{
		head = stack;
		highest = LONG_MIN;
		while (head)
		{
			if (head->order == 0 && highest < head->content)
				highest = head->content;
			head = head->next;
		}
		if (highest < INT_MIN || INT_MAX < highest)
			return (0);
		if (!parse_set_order(stack, highest, order))
			return (0);
		order--;
	}
	return (1);
}

int	parse_set_order(t_stack *stack, int value, int order)
{
	while (stack->next && stack->content != value)
		stack = stack->next;
	if (stack->content == value)
		stack->order = order;
	stack = stack->next;
	if (stack)
	{
		while (stack->next && stack->content != value)
			stack = stack->next;
		if (stack->content == value)
			return (0);
	}
	return (1);
}
