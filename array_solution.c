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

t_arr_sol			ft_calc_pos(t_arr_sol var);
t_std_var			ft_line_state(t_std_var var);
int					ft_set_arr_proc(int procedure);

int ft_read_line_len(void)
{
	int	k;
	char			buff;
	
	k = 0;
	read(fd, &buff, 1);
	if (buff != '\n')
		return (0);
	while (read(fd, &buff, 1) && buff != '\n')
		k++;
	if (buff != '\n')
		return (0);
	map_info.line_len = k;
	if (close(fd) == 1 || !(ft_read_map()))
		return (0);
	while (read(fd, &buff, 1) && buff != '\n');
	return (1);	
}

int	ft_read_number(void)
{
	char	buff;
	
	if (!(read(fd, &buff, 1)))
		return (0);
	if (buff < '0' || buff > '9')
		return (0);
	while (buff >= '0' && buff <= '9')
	{
		map_info.map_lines = (map_info.map_lines)*10 + (buff - '0');
		if (!(read(fd, &buff, 1)))
			return (0);
	}
	if (buff != '\n' && map_info.map_lines != 0)
		map_info.empty = buff;
	else 
		return (0);
	return (1);
}

int	ft_read_map_info(void)
{
	char	buff;
	
	if (!(ft_read_number()))
		return (0);
	if (!(read(fd, &buff, 1)))
			return (0);
	if (buff != '\n')
		map_info.obstacle = buff;
	else return (0);
	if (!(read(fd, &buff, 1)))
			return (0);
	if (buff != '\n')
		map_info.full = buff;
	else return (0);
	return (1);
}

t_std_var	ft_line_state(t_std_var var)
{
	if (var.buff == '\n' && var.l == (map_info.line_len))
	{
		var.l = 0;
		var.k++;
	}
	else 
		var.l++;
	return (var);
}

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
		if (var.buff != map_info.empty && var.buff != map_info.obstacle && var.buff != '\n')
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

t_arr_sol	ft_calc_pos(t_arr_sol var)
{
	while(var.curr.size > var.larg.size && (var.k + var.curr.y + 1) < map_info.map_lines)
	{
		var.curr.y++;
		var.curr.x = 0;
		while (map_arr[var.k + var.curr.y][var.l + var.curr.x] == map_info.empty && var.curr.x < var.curr.size)
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

int	ft_array_solution(void)
{
	t_arr_sol	var;

	var.k = 0;
	var.l = 0;
	while (map_arr[var.k] && var.k < (map_info.map_lines - var.larg.size))
	{
		while (map_arr[var.k][var.l]  && var.l < (map_info.line_len - var.larg.size))
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
	largest_solution = var.larg;
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
			map_arr[k + largest_solution.y][l + largest_solution.x] = map_info.full;
			l++;
		}
		k++;
	}
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
