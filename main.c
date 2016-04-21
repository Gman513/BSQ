/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavenga                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:05:22 by khansman          #+#    #+#             */
/*   Updated: 2016/04/13 13:42:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int 		main(int argc, char **argv)
{
	int     k;

	k = 1;
	if (argc > k)
	{
		while (argv[k])
		{
			file_name = argv[k];
			ft_solve_map();
			k++;
		}
	}
	else
		ft_readstdi();
	return (1);
}

int			ft_read_map(void)
{

	fd = open(file_name, O_RDONLY);
	if (fd != -1)
		return (1);
	else
		return (0);
}

void		ft_solve_map(void)
{
	if (!(ft_read_map()))
		write(1, "map error\n", 10);
	else if (!(ft_read_map_info()) || !(ft_read_line_len()) || (ft_set_array()))
		write(1, "map error\n", 10);
	else if (!(ft_array_solution()))
		write(1, "map error\n", 10);
	else
		ft_display_map();
	close(fd);
	free(map_arr);
}

void		ft_readstdi(void)
{
	int		position;
	int		quotes;
	
	position = 0;
	quotes = 0;
	file_name = malloc(sizeof(char)*255);
	if (file_name != NULL)
	{	
		while (read(fd, &buff, 1) && buff != '\n')
		{
			if (buff == '"' && quotes == 0)
			{
				position++;
				quotes = 1;
			}
			else if (buff == '"' && quotes == 1)
			{
				quotes = 0;
				file_name[position] = '\0';
				ft_solve_map();
				position = 0;
			}
			else if (buff == ' ' && quotes = 0)
			{
				file_name[position] = '\0';
				ft_solve_map();
				position = 0;
			}
			else
				file_name[position] = buff;			
		}
		free(file_name);
	}
}

void		ft_display_map(void)
{
	int		position;
	int		line;
	char	temp;
	
	position = 0;
	while (map_arr[line])
	{
		while (map_arr[line][position])
		{
			temp = map_arr[line][position];
			write(1,&temp,1);
			position++;
			if (temp == '\n')
			{
				line++;
				position = 0;
			}
		}
		
	}
}
