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

int ft_read_line_len(void)
{
	unsigned int	k;
	char			buff;
	
	k = 0;
	while (read(fd, &buff, 1) && buff != '\n');
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
	while (buff != '\n' && buff >= '0' && buff <= '9')
	{
		map_info.map_lines = (map_info.map_lines)*10 + (buff - '0');
		if (!(read(fd, &buff, 1)))
			return (0);
	}
	if (buff != '\n')
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
	//char			*arr_row;
	char			**arr_col;
	unsigned int	k;
	unsigned int	l;
	
	k = 0;
	l = 0;
	if (map_info.line_len == 0)
		return (0);
	//arr_row = malloc(sizeof(char) * map_info.line_len);
	arr_col = malloc(sizeof(char) * map_info.line_len * map_info.map_lines);//malloc(sizeof(arr_row))
	while(read(fd, &buff, 1) && k <= map_info.map_lines)
	{
		if (buff != map_info.empty && buff != map_info.obstacle && buff != '\n')
			return (0);
		if (buff != '\n')
			arr_col[k][l] = buff;
		else
			if (l != map_info.line_len)
				return (0);
			else
			{
				l = 0 - 1;
				k++;
			}
		l++;
	}
	map_arr = malloc(sizeof(arr_col));
	map_arr = arr_col;
	//free(arr_row);
	free(arr_col);
	return (1);
}

int	ft_array_solution(void)
{
	unsigned int	k;
	unsigned int	l;
	t_square		current;
	t_square		largest;

	k = 0;
	l = 0;
	while (map_arr[k] && (k - largest.size) < map_info.map_lines)
	{
		while (map_arr[k][l]  && (k - largest.size) < map_info.line_len)
		{
			current.y = 0;
			current.size = 0;
			while (map_arr[k][l + current.size] == map_info.empty)
				current.size++;
			while(current.size > largest.size)
			{
				current.y++;
				current.x = 0;
				while (map_arr[k + current.y][k + current.x] == map_info.empty && current.x <= current.size)
					current.x++;
				if (current.x < current.size)
					current.size = current.x;
				if (current.y >= current.size && current.size > largest.size)
					largest = current;
			}
			l++;
		}
		l = 0;
		k++;
	}
	largest_solution = largest;
	return (1);
}
