/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:14:44 by zyeoh             #+#    #+#             */
/*   Updated: 2023/12/18 20:24:26 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol(const char *str)
{
	long long	result;
	int			sign;

	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}

int	ft_numlen(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 10 > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_stackisordered(t_stack *lst)
{
	int	prev_val;
	int	group;
	int	lowest;

	if (!lst)
		return (0);
	group = 1;
	lowest = lst->content;
	while (lst->next && group < 3)
	{
		prev_val = lst->content;
		lst = lst->next;
		if (prev_val >= lst->content)
			group++;
		if (group == 2 && lowest < lst->content)
			group++;
	}
	if (group > 1)
		return (0);
	return (1);
}

int	check_valid(char **arg)
{
	int	index;

	while (*++arg)
	{
		index = 0;
		while ((*arg)[index])
		{
			while ((*arg)[index] == ' ')
				index++;
			if (!(*arg)[index])
				break ;
			if ((*arg)[index] == '-' || (*arg)[index] == '+')
				index++;
			if (!ft_isdigit((*arg)[index]))
				return (0);
			while (ft_isdigit((*arg)[index]))
				index++;
			if (ft_isdigit((*arg)[index]) || (*arg)[index] == '-'
				|| (*arg)[index] == '+')
				return (0);
		}
	}
	return (1);
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	free(*lst);
}
