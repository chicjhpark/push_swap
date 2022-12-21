/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/28 09:17:45 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_sort_a2(int *a, int *b, t_info *info)
{
	if (a[0] > a[info->a_num - 1] && check_max(b, info->b_num) > 0
		&& check_max(b, info->b_num) < info->b_num / 2)
		ft_msg(rotate_ab(a, b, info));
	else if (a[0] > a[info->a_num - 1])
		ft_msg(rotate_a(a, info));
	else if (b[1] > b[0] && b[1] > b[2] && b[0] > b[2])
		ft_msg(swap_ab(a, b, info));
	else
		ft_msg(swap_a(a));
}

void	pivot_sort_a3(int *a, int *b, t_info *info)
{
	if (a[info->a_num - 1] < info->pivot
		&& check_max(b, info->b_num) > info->b_num / 2)
		ft_msg(reverse_rotate_ab(a, b, info));
	else if (a[info->a_num - 1] < info->pivot)
		ft_msg(reverse_rotate_a(a, info));
	else if (a[0] < a[1] && check_max(b, info->b_num) > 0
			&& check_max(b, info->b_num) < info->b_num / 2)
		ft_msg(rotate_ab(a, b, info));
	else if (a[0] < a[1])
		ft_msg(rotate_a(a, info));
	else if (b[1] > b[0] && b[1] > b[2] && b[0] > b[2])
		ft_msg(swap_ab(a, b, info));
	else
		ft_msg(swap_a(a));
}

void	pivot_sort_a(int *a, int *b, t_info *info)
{
	if (a[0] < info->pivot && a[0] < a[1] && a[0] < a[info->a_num - 1])
		ft_msg(push_b(b, a, info));
	else if (a[0] < a[1] && a[0] < a[info->a_num - 1])
	{
		if (a[1] < a[info->a_num - 1] && check_max(b, info->b_num) > 0
			&& check_max(b, info->b_num) < info->b_num / 2)
			ft_msg(rotate_ab(a, b, info));
		else if (a[1] < a[info->a_num - 1])
			ft_msg(rotate_a(a, info));
		else if (b[1] > b[0] && b[1] > b[2] && b[0] > b[2])
			ft_msg(swap_ab(a, b, info));
		else
			ft_msg(swap_a(a));
	}
	else if (a[1] < a[0] && a[1] < a[info->a_num - 1])
		pivot_sort_a2(a, b, info);
	else
		pivot_sort_a3(a, b, info);
}

void	parse_stack(int *a, int *b, t_info *info)
{
	if (check_sort_a(a, info) == TRUE)
		return ;
	while (info->a_num > 3 && check_sort_a(a, info) == FALSE)
	{
		init_pivot(a, info->a_num, info);
		while (info->a_num > 3
				&& check_pivot(a, info->a_num, info, 'a') == TRUE)
			pivot_sort_a(a, b, info);
	}
	while (check_sort_a(a, info) != TRUE || info->a_num != info->num)
	{
		if (info->a_num > 3)
			sort_stack3(a, b, info);
		else
			sort_stack(a, b, info);
		while (check_sort_a(a, info) == TRUE && info->b_num > 0)
			push_a_max(a, b, info);
	}
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	t_info	info;

	if (argc >= 2)
	{
		init_info(&info, argc);
		init_stack(&a, &b, info, &argv[1]);
		parse_stack(a, b, &info);
		free(a);
		free(b);
	}
	return (0);
}
