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

#include <stdio.h> //DEBUG CODE

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
	{
		ft_readstdi();
		return(0);
	}
	return (1);
}

int			ft_read_map(void)
{

	fd = open(file_name, O_RDONLY);
	printf("ft_read_map fd = %i\n", fd); //DEBUG CODE
	if (fd != -1)
		return (1);
	else
		return (0);
}

void		ft_solve_map(void)
{
	if (!(ft_read_map()))
		write(1, "map error\n", 9);
	else if (!(ft_read_map_info()))
		write(1, "map error\n", 9);
	else if (!(ft_read_line_len()))
		write(1, "map error\n", 9);
	else if (!(ft_set_array()))
		write(1, "map error\n", 9);
	else if (!(ft_array_solution()))
		write(1, "map error\n", 9);
	else if (ft_add_solution())
		ft_display_map();
	close(fd);
	ft_manage_array(0);
}

void		ft_readstdi(void)
{
	int		position;
	int		quotes;
	char	buff;
	
	position = 0;
	quotes = 0;
	file_name = malloc(sizeof(char)*255);
	if (file_name != NULL)
	{
		while (buff != '\n' && read(0, &buff, 1))
		{
			if (buff == '"' && quotes == 0)
			{
				position++;
				quotes = 1;
			}
			else if (buff == '"' && quotes == 1 && position > 0)
			{
				quotes = 0;
				file_name[position] = '\0';
					printf("ft_readstdi file_name = %s\n", file_name); //DEBUG CODE
				ft_solve_map();
				position = 0;
			}
			else if (((buff == ' ' && quotes == 0) || buff == '\n') && position > 0)
			{
				file_name[position] = '\0';
					printf("ft_readstdi file_name = %s\n", file_name); //DEBUG CODE
				ft_solve_map();
				position = 0;
			}
			else
			{
				file_name[position] = buff;
				position++;
			}			
		}
		free(file_name);
	}
}

void		ft_display_map(void)
{
	int		line;
	
	line = 0;
	while (line != map_info.map_lines)
	{
		write(1,map_arr[line], map_info.line_len + 1);
		line++;
	}
	printf("Reaches end of ft_display_map\n"); //DEBUG CODE
}
