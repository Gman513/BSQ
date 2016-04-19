/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavenga <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:05:22 by khansman          #+#    #+#             */
/*   Updated: 2016/04/13 13:42:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_map_description(void)
{
	char		value;
	
	map_info = NULL; //needs to be tested
	read(fd, &value, 1);
	while (value != '\n' && value >= '0' && value <= '9') )
	{
		map_info.map_lines = (map_info.map_lines * 10) + (value - '0');
		if (!(read(fd, &value, 1))
			return (0); //needs to be tested
	}//defensive programming needs work
	if (value != '\n')
		map_info.empty = value;
	if (!(read(fd, &value, 1)))
		return (0);
	if (value != '\n')
		map_info.obstacle = value;
	if (!(read(fd, &value, 1)))
		return (0);
	if (value != '\n')
		map_info.full = value;
	return (1);
}

int	ft_test_map_info(tmap_info info)
{
	if (info.size < 1 || info.size == null)
		return (0);
	else if (info.empty == ('NULL' || '\n' || '\0')) //need to test notation
		return (0);
	else if (info.obstacle == ('NULL' || '\n' || '\0')) //need to test notation
		return (0);
	else if (info.full == ('NULL' || '\n' || '\0')) //need to test notation
		return (0);
	return (1);
}

int	ft_test_map_data(void)
{
	unsigned int	length;
	unsigned int	line_len;
	
	length = 0;
	line_len = -1;
	while (read(fd, &buff, 1))
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
	return (1);
}

int	ft_test_map(int fd, tmap_info info)
{
	char			buff;
	
	read(fd, &buff, 1);
	if (buff != '\n')
		return (0);
	else if !(ft_test_map_info(info))
		return (0);
	else if !(ft_test_map_data(fd))
		return (0);
	return (1);
}
