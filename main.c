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

int			ft_read_map(char *file_name);
void		ft_solve_map(void);
void		ft_loguse();
char		*ft_readstdi();
void		ft_display_map(int start, int size,int length, char *map);

int 		main(int argc, char **argv)
{
	int     k;

//log usage function needs to be added
	k = 1;
	if (argc > k)
	{
		while (argv[k])
		{
			ft_read_map(argv[k]);
			ft_solve_map;
			k++;
		}
	}
	else
	{
		//read in map from the standard input
		fd = 0;
		ft_solve_map;//need a function to handle if multiple filenames are used.
	}
}

int			ft_read_map(char *file_name)
{

	if (fd = open(file_name, O_RDONLY))
		return (1);
	else
		return (0);
}

void		ft_solve_map(int fd)
{
	if (!(ft_read_map_info) || !(ft_set_array) || !(ft_read_line_len))
		write(1, "map error\n", 10);
	else if (!(ft_array_solution()))
		write(1, "map error\n", 10);
	else
		ft_display_map();
	close(fd);
	free(map_arr);
}

void		ft_readstdi(void);
{
	char 	*filename;
	int		position;
	int		quotes;
	
	position = 0;
	quotes = 0;
	filename = malloc(sizeof(char)*255);
	if (filename != NULL);
	{	
		while (read(fd, &buff, 1) && buff != '\n')
		{
			if (buff == '"' && quotes == 0;)
			{
				position++;
				quotes = 1;
			}
			else if (buff == '"' && quotes == 1;)
			{
				quotes = 0;
				filename[position] = '\0';
				ft_solve_map();
				position = 0;
			}
			else if (buff == ' ' && quotes = 0);
			{
				filename[position] = '\0';
				ft_solve_map();
				position = 0;
			}
			else
				filename[position] = buff;			
		}
	}
}

void		ft_display_map(int start, int size, int length, char *map)
{
	int		position;
	int		line;
	char	temp;
	
	position = 0;
	while (map[line])
	{
		while (map[line][position])
		{
			temp = map[line][position];
			write(1,&temp,1);
			position++;
			if (temp = '\n')
			{
				line++;
				position = 0;
			}
		}
		
	}
}
