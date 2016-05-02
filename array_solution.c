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

int	ft_read_map_info(void) //need to write a sub function to reduce the number of lines, or create a loop...
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
	else return (0);
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

int	ft_set_array(void)
{
	char			buff;
	int	k;
	int	l;
	
	k = 0;
	l = 0;
	if (map_info.line_len == 0)
		return (0);
	ft_manage_array(1);
	while(read(fd, &buff, 1) == 1 && k < map_info.map_lines)
	{
		map_arr[k][l] = buff;
		if (buff != map_info.empty && buff != map_info.obstacle && buff != '\n')
			return (0);
		else if (buff == '\n' && l != (map_info.line_len))
			return (0);
		else if (buff == '\n' && l == (map_info.line_len))
		{
			l = 0;
			k++;
		}
		else l++;
		if (l > map_info.line_len)
			return (0);
	}
	if (k != map_info.map_lines || (read(fd, &buff, 1)))
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
		//printf("\t\t\t\t\t\t\tvar.larg.size: [%i]\n", var.larg.size); //DEBUG CODE
		//write(1, "\t\t\t\t\t\t\tvar.larg.size: [%i]\n", 28); //Debug
		//printf("\t\t\t\t\t\t\tvar.curr.size: [%i]\n", var.curr.size); //DEBUG CODE
		//write(1, "\t\t\t\t\t\t\tvar.curr.size: [%i]\n", 28); //Debug
		write(1, "crazy seg fault fix", 0); //DEbug
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

int ft_manage_array (int procedure)
{
	int k;

	k = 0;
			//printf("\nft_manage_array called \nProcedure = [%i]\n", procedure); //DEBUG CODE
			//write(1, "\nft_manage_array called \nProcedure = [%i]\n", 45); //DEBUG
			//printf("map_info.map_lines = [%i]\n", map_info.map_lines); //DEBUG CODE
			//write(1, "map_info.map_lines = [%i]\n", 29); //DEBUG
	if (procedure == 0)
		k = map_info.map_lines - 1;
	if (procedure == 1)
	{ // DEBUG
		map_arr = malloc(sizeof(void*) * map_info.map_lines - 1);
		//printf("ft_manage_array map_arr malloced [%i] PRIMARY places succesfully\n", map_info.map_lines); //DEBUG CODE
		//write(1, "ft_manage_array map_arr malloced [%i] PRIMARY places succesfully\n", 66); // Debug
	} //DEBUG
	if (map_arr == NULL)
		return (0);
	while (k < map_info.map_lines && k > -1)
	{
		if (procedure == 1)
		{
			map_arr[k] = malloc(sizeof(char) * map_info.line_len + 1);
				//printf("ft_manage_array map_arr[%i] malloced [%i] places succesfully\n", k, map_info.line_len); //DEBUG CODE
				//write(1, "ft_manage_array map_arr[%i] malloced [%i] places succesfully\n", 61);//DEbug
			if (map_arr[k] == NULL)
				return (0);
			k++;
		}
		else
		{
				//printf("ft_manage_array attempting to free map_arr[%i]\n", k); //DEBUG CODE
				//write(1, "ft_manage_array attempting to free map_arr \n", 44); //Debug 
			free(map_arr[k]);
				//printf("ft_manage_array succeeded in freeing map_arr[%i]\n", k); //DEBUG CODE
				//write(1, "ft_manage_array succeeded in freeing map_arr \n", 46); //DEBUG CODE
				//write(1, &k + 48, 3); // DEBUG
			k--;
		}
	}
	if (procedure == 0)
	{//DEBUG
			//write(1, "ft_manage_array attempting to free PRIMARY ARRAY\n", 49); //Debug
		free(map_arr);
			//write(1, "SUCCESS\n", 8); //DEBUG CODE
	}//DEBUG
	return (1);
}

int	ft_add_solution(void)
{
	int		k;
	int		l;
	
	k = 0;//((largest_solution.y + k) < largest_solution.size)
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
