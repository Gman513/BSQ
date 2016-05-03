/* ************************************************************************** */
/*                                                                 CS^3       */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavenga                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:08:21 by ghavenga          #+#    #+#             */
/*   Updated: 2016/04/20 13:09:00 by ghavenga         ###   ########.fr       */
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
