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

int		ft_read_map(char *file_name);
void	ft_solve_map(void);
tsquare	ft_scan_map_reduction(void);
void	ft_display_map(tsquare);

int 	main(int argc, char **argv)
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

int		ft_read_map(char *file_name)
{

	if (fd = open(file_name, O_RDONLY))
		return (1);
	else
		return (0);
}

void	ft_solve_map(int fd)
{
	if (fd == -1) || !(ft_testmap(fd, ft_map_description(fd)))//need to reset the file pointer possition after this call
		write(1, "map error\n", 10);
	else
	{
		ft_display_map(ft_scan_map_reduction(fd));
		//ft_display_map(ft_scan_map_expansion(fd));
	}
	if (fd > 1)
		close(fd);
}
