/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_seup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavnga <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:05:22 by khansman          #+#    #+#             */
/*   Updated: 2016/04/13 13:42:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//ft_test_map, ft_map_description
tmap_info	ft_map_description(int fd)
{
	tmap_info	map;
	char		value;
	
	map = null; //needs to be tested
	read(fd, &value, 1);
	while (value != '\n' && value >= '0' && value <= '9') )
	{
		map.size = (map.lines * 10) + (value - '0');
		if (read(fd, &value, 1) == 0)
			return (map.value = -1); //needs to be tested
	}//defensive programming needs work
	if (value != '\n')
		map.empty = value;
	read(fd, &value, 1);
	if (value != '\n')
		map.obstacle = obstacle;
	read(fd, &value, 1);
	if (value != '\n')
		map.full = obstacle;
	return (map);
}

int	ft_test_map_info(tmap_info info)
{
	if (info.size < 1 || info.size == null)
		return (0);
	else if (info.empty == ('null' || '\n' || '\0')) //need to test notation
		return (0);
	else if (info.obstacle == ('null' || '\n' || '\0')) //need to test notation
		return (0);
	else if (info.full == ('null' || '\n' || '\0')) //need to test notation
		return (0);
	return (1);
}

int	ft_test_map(int fd, tmap_info info)
{
	unsigned int	length;
	unsigned int	line_len;
	char			buff;
	
	length = 0;
	line_len = -1;
	read(fd, &buff, 1);
	if (buff != '\n')
		return (0);
	else if !(ft_test_map_info(info))
		return (0);
	else while (read(fd, &buff, 1))
		{
			if (buff == info.empty || buff == info.obstacle || buff == '\n')
			{
				if (line_len == -1 && buff != '\n')
					length++;
				else if (buff == '\n')
				{
					if (line_len > 0 && line_len != length)
						return (0);
					line_len = 0;
				}
				else
					line_len++;  //need to run through to check
			}
			else return (0);
		}
	else return (1);
}
