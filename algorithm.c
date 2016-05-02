/* ************************************************************************** */
/*                                                                 CS^3       */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavenga                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:08:21 by ghavenga          #+#    #+#             */
/*   Updated: 2016/04/20 13:09:00 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_add_solution(void)
{
	int		k;
	int		l;
	
	k = 0;
	while(k < largest_solution.size)
	{
		l = 0;
		while(l < largest_solution.size)
		{
			ADDSOLUTION = map_info.full;
			l++;
		}
		k++;
	}
	return (1);
}

int	ft_array_solution(void)
{
	t_arr_sol	var;

	var.k = 0;
	var.l = 0;
	while (map_arr[var.k] && var.k < (map_info.map_lines - var.larg.size))
	{
		while (CONDITIONFIVE  && var.l < (map_info.line_len - var.larg.size))
		{
			var.curr.y = 0;
			var.curr.size = 0;
			while (map_arr[var.k][var.l + var.curr.size] == map_info.empty)
				var.curr.size++;
			var = ft_calc_pos(var);
			var.l++;
		}
		var.l = 0;
		var.k++;
	}
	if (var.larg.size > 1)
		largest_solution = var.larg;
	else if (!(ft_single()))
		return (0);
	return (1);
}

int			ft_single(void)
{
	int		k;
	int		l;
	
	k = 0;
	l = 0;
	while (l < map_info.map_lines && CONDITIONSIX)
	{
		while (k < map_info.line_len && CONDITIONSIX)
			k++;
		if (k >= map_info.line_len && CONDITIONSIX)
		{
			l++;
			k = 0;
		}
	}
	if (l < map_info.map_lines && k < map_info.line_len)
	{
		largest_solution.x = k;
		largest_solution.y = l;
		largest_solution.size = 1;
		return (1);
	}
	return (0);
}

t_arr_sol	ft_calc_pos(t_arr_sol var)
{
	while(CONDITIONTHREE && (var.k + var.curr.y + 1) < map_info.map_lines)
	{
		var.curr.y++;
		var.curr.x = 0;
		while (CONDITIONFOUR == map_info.empty && var.curr.x < var.curr.size)
			var.curr.x++;
		if (var.curr.x + 1 < var.curr.size)
			var.curr.size = var.curr.x + 1;
		if (var.curr.y >= var.larg.size && var.curr.size > var.larg.size)
		{
			var.larg.x = var.l;
			var.larg.y = var.k;
			var.larg.size = var.curr.y + 1;
		}
		write(1, "crazy seg fault fix", 0);
	}
	return (var);
}
