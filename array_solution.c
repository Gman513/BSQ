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

int	ft_array_solution(void)
{
	int	k;
	int	l;
	t_square		current;
	t_square		largest;

	k = 0;
	l = 0;
	while (map_arr[k] && k < (map_info.map_lines - largest.size))
	{
		while (map_arr[k][l]  && l < (map_info.line_len - largest.size))
		{
			current.y = 0;
			current.size = 0;
			while (map_arr[k][l + current.size] == map_info.empty)
				current.size++;
			while(current.size > largest.size && (k + current.y + 1) < map_info.map_lines)
			{
				current.y++;
				current.x = 0;
				while (map_arr[k + current.y][l + current.x] == map_info.empty && current.x < current.size)
					current.x++;
				if (current.x + 1 < current.size)
					current.size = current.x + 1;
				if (current.y >= largest.size && current.size > largest.size)//debug edit
				{
					largest.x = l;
					largest.y = k;
					largest.size = current.y + 1;
					printf("\t\tlargest.x = %i\n", l);
					printf("\t\tlargest.y = %i\n", k);
				}
			}
			l++;
		}
		l = 0;
		k++;
	}
	largest_solution = largest;
	return (1);
}

int ft_manage_array (int procedure)
{
	int k;

	k = 0;
	if (procedure == 0)
		k = map_info.map_lines - 1;
	if (procedure == 1)
		map_arr = malloc(sizeof(void*) * map_info.map_lines - 1);
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
