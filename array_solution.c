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

include "bsq.h"

int read_line_len(void)
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
	if (!(close(fd)) || !(ft_read_map()))
		return (0);
	return (1);	
}

//these functions assume that map_info variables havr been initiated before they are run.
int	ft_read_map_info(void) //need to write a sub function to reduce the number of lines, or create a loop...
{
	char	buff;
	
	if (!(read(fd, &buff, 1)))
		return (0);
	while (buff != '\n' && buff >= '0' && buff <= '9')
	{
		map_info.size = (map_info.size)*10 + (buff - '0');
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
	//This function assumes that the file pointer is already set to the starting point of the map.
	//This function also makes use of global variables which store information regarding the map's setup.
	char			buff;
	char			*arr_row;
	char			**arr_col;
	unsigned int	k;
	unsigned int	l;
	
	k = 0;
	l = 0;
	if (map_info.line_len == 0 || buff != '\n')
		return (0);
	arr_row = malloc(sizeof(char) * map_info.line_len);
	arr_col = malloc(sizeof(arr_row) * map_info.size);
	while(read(fd, &buff, 1) && k <= map_info.size)
	{
		if (buff != (map_info.empty || map_info.obstacle || '\n'))
			return (0);
		if (buff != '\n')
			array_col[k][l] = buff;
		else
			if (l != map_info.line_len)
				return (0);
			else
				l = 0 - 1;
		l++;
		k++;
	}
	map_arr = malloc(sizeof(arr_col));
	free arr_row;
	free arr_col;
	return (1);
}

int	array_solution(void);
{
	unsigned int	k;
	unsigned int	l;
	tsquare			current;
	tsquare			largest;

	k = 0;
	l = 0;
	if (!(ft_read_map_info) || !(ft_set_array))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	while (map_arr[k] && (k - largest.size) < map_info.size)
	{
		while (map_arr[k][l]  && (k - largest.size) < map_info.line_len)
		{
			current.y = 0;
			current.size = 0;
			while (map_arr[k][l + current] == map_info.empty)
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
