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
	
	read(fd, value, 1);
	while (value != '\n' && value >= '0' && value <= '9') )
	{
		map.size = (map.lines * 10) + (value - '0');
		read(fd, value, 1);
	}
	if (value != '\n')
		map.empty = value;
}
