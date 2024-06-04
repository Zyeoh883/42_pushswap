/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:09 by zyeoh             #+#    #+#             */
/*   Updated: 2024/01/25 15:11:05 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	long			content;
	int				order;
	struct s_stack	*next;
}					t_stack;

void				ft_stackclear(t_stack **lst);
void				ft_showstack(t_stack *lst);

t_stack				*init_stack(char **value);
t_stack				*add_to_stack(char *str, t_stack *result);
int					init_order_num(t_stack *stack);
int					parse_set_order(t_stack *stack, int value, int order);

t_stack				*ft_stacknew(long content);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_stacklast(t_stack *lst);
int					ft_stacksize(t_stack *lst);

long				ft_atol(const char *str);
int					ft_numlen(long nbr);
int					ft_stackisordered(t_stack *lst);
int					check_valid(char **list);

void				swap_a(t_stack **head);
void				swap_b(t_stack **head);
void				swap_s(t_stack **a_head, t_stack **b_head);
void				push_a(t_stack **a_head, t_stack **b_head);
void				push_b(t_stack **a_head, t_stack **b_head);

void				rotate_a(t_stack **head);
void				rotate_b(t_stack **head);
void				rotate_r(t_stack **a_head, t_stack **b_head);

void				rev_rotate_a(t_stack **head);
void				rev_rotate_b(t_stack **head);
void				rev_rotate_r(t_stack **a_head, t_stack **b_head);

int					largest_depth(t_stack *stack, int depth);
void				solve_two(t_stack **stack);
void				solve_three(t_stack **stack);
void				solve_five(t_stack **a_head, t_stack **b_head);

void				quick_sort(t_stack **a_head, t_stack **b_head);
void				transfer_pair(t_stack **a_head, t_stack **b_head, int top,
						int size);
void				eff_rotate(t_stack **a_head, t_stack **b_head,
						int *lower_bound);

void				insertion_sort(t_stack **a_head, t_stack **b_head);
void				insert_runs(t_stack **a_head, t_stack **b_head,
						int max_order, void (*spin)(t_stack **));
int					largest_order(t_stack *stack);
void				sort_runs(t_stack **a_head, t_stack **b_head, int max_order,
						int b_largest);

#endif