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

#include <stdio.h> //DEBUG CODE

int ft_read_line_len(void)
{
	int	k;
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
		printf("ft_read_line_len map_info.line_len = %i\n", map_info.line_len); //DEBUG CODE
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
			printf("ft_read_map_info map_info.map_lines = %i\n", map_info.map_lines); //DEBUG CODE
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
	int	k;
	int	l;
	
	k = 0;
	l = 0;
	if (map_info.line_len == 0)
		return (0);
	ft_manage_array(1);
	while(read(fd, &buff, 1) == 1 && k <= map_info.map_lines)
	{
		printf("ft_set_array map_arr[%i][%i] = %c\n", k, l, buff); //DEBUG CODE
		if (buff != map_info.empty && buff != map_info.obstacle && buff != '\n')
			return (0);
		map_arr[k][l] = buff;
		if (l != (map_info.line_len) && buff == '\n')
		{//debug
			printf("running away\n");//debug code
			return (0);
		}//debug
		else if (l == (map_info.line_len) && buff == '\n')
		{
			printf("set next line\n");//debug code
			map_arr[k][l] = buff;
			l = 0 - 1;
			k++;
		}
		//printf("ft_set_array map_arr[%i][%i] = %c\n", k, l, buff); //DEBUG CODE
		l++;
	}
	printf("exit loop\n");//debug code
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
			printf("ft_array_solution called\n"); //DEBUG CODE
	while (map_arr[k] && (k - largest.size) < map_info.map_lines)
	{
		while (map_arr[k][l]  && (k - largest.size) < map_info.line_len)
		{
			current.y = 0;
			current.size = 0;
				printf("current.y = [%i] | current.size = [%i]\n", current.y, current.size); //DEBUG CODE
			while (map_arr[k][l + current.size] == map_info.empty)
			{//DEBUG
				current.size++;
					printf("current.size++\n"); //DEBUG CODE
			}//DEBUG
			while(current.size > largest.size)
			{
				current.y++;
				current.x = 0;
				while (map_arr[k + current.y][k + current.x] == map_info.empty && current.x < current.size)
				{//debug
					current.x++;
					printf("checking++\n"); //DEBUG CODE
				}//debug
				if (current.x < current.size)
					current.size = current.x;
				if (current.y > largest.size && current.y > largest.size)
				{
					largest.x = k;
					largest.y = l;
					largest.size = current.y;
				}
				printf("Largest.size: %i\n", largest.size); //DEBUG CODE
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
	if (procedure == 1)
	{ // DEBUG
		map_arr = malloc(sizeof(char*) * map_info.map_lines);
		printf("ft_manage_array map_arr malloced [%i] places succesfully\n", map_info.map_lines); //DEBUG CODE
	} //DEBUG
	if (map_arr == NULL)
		return (0);
	while (k <= map_info.map_lines)
	{
		if (procedure == 1)
		{
			map_arr[k] = malloc(sizeof(char) * map_info.line_len);
				printf("ft_manage_array map_arr[%i] malloced [%i] places succesfully\n", k, map_info.line_len); //DEBUG CODE
			if (map_arr[k] == NULL)
				return (0);
			k++;
		}
		else
		{
				printf("ft_manage_array attempting to free map_arr[%i]\n", k); //DEBUG CODE
			free(map_arr[k]);
			k++;
		}
	}
	// INSERT CODE TO FREE PRIMARY ARRAY
	return (1);
}
