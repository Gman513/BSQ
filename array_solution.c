/* ************************************************************************** */
/*                                                                 CS^3       */
/*                                                        :::      ::::::::   */
/*   array_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavenga                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:08:21 by khansman          #+#    #+#             */
/*   Updated: 2016/04/20 13:09:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_set_array(void)
{
	t_std_var	var;
	
	var.k = 0;
	var.l = 0;
	if (map_info.line_len == 0)
		return (0);
	ft_manage_array(1);
	while(read(fd, &var.buff, 1) == 1 && var.k < map_info.map_lines)
	{
		map_arr[var.k][var.l] = var.buff;
		if (CONDITIONTWO && var.buff != map_info.obstacle && var.buff != '\n')
			return (0);
		else if (var.buff == '\n' && var.l != (map_info.line_len))
			return (0);
		else 
			var = ft_line_state(var);
		if (var.l > map_info.line_len)
			return (0);
	}
	if (var.k != map_info.map_lines || (read(fd, &var.buff, 1)))
		return (0);
	return (1);
}

int	ft_set_arr_proc(int procedure)
{
	int	k;
	
	k = 0;
	if (procedure == 0)
		k = map_info.map_lines - 1;
	if (procedure == 1)
		map_arr = malloc(sizeof(void*) * map_info.map_lines - 1);
	return (k);
}

int ft_manage_array (int procedure)
{
	int k;

	k = ft_set_arr_proc(procedure);
	if (map_arr == NULL)
		return (0);
	while (k < map_info.map_lines && k > -1)
	{
		if (procedure == 1)
		{
			map_arr[k] = malloc(sizeof(char) * map_info.line_len + 1);
			if (map_arr[k] == NULL)
				return (0);
			k++;
		}
		else
		{ 
			free(map_arr[k]);
			k--;
		}
	}
	if (procedure == 0)
		free(map_arr);
	return (1);
}

int	ft_set_var(void)
{
	map_info.map_lines = 0;
	map_info.line_len = 0;
	map_info.empty = 0;
	map_info.obstacle = 0;
	map_info.full = 0;
	largest_solution.x = 0;
	largest_solution.y = 0;
	largest_solution.size = 0;
	return (1);
}

void		ft_display_map(void)
{
	int		line;
	
	line = 0;
	while (line != map_info.map_lines)
	{
		write(1,map_arr[line], map_info.line_len + 1);
		line++;
	}
}
