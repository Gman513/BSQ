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

t_read_stdi	ft_handle_case(t_read_stdi var);

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
	if (fd != -1)
		return (1);
	else
		return (0);
}

void		ft_solve_map(void)
{
	if (!(ft_set_var()) || !(ft_read_map()))
		write(1, "map error\n", 10);
	else if (!(ft_read_map_info()))
		write(1, "map error\n", 10);
	else if (!(ft_read_line_len()))
		write(1, "map error\n", 10);
	else if (!(ft_set_array()))
		write(1, "map error\n", 10);
	else if (!(ft_array_solution()))
		write(1, "map error\n", 10);
	else if (ft_add_solution())
		ft_display_map();
	close(fd);
	ft_manage_array(0);
}

t_read_stdi	ft_handle_case(t_read_stdi var)
{
	if (var.buff == '"' && var.quote == 0)
	{
		var.pos++;
		var.quote = 1;
	}
	else if (var.buff == '"' && var.quote == 1 && var.pos > 0)
	{
		var.quote = 0;
		file_name[var.pos] = '\0';
		ft_solve_map();
		var.pos = 0;
	}
	else if ((CONDITIONONE || var.buff == '\n') && var.pos > 0)
	{
		file_name[var.pos] = '\0';
		ft_solve_map();
		var.pos = 0;
	}
	else
	{
		file_name[var.pos] = var.buff;
		var.pos++;
	}
	return (var);
}

void		ft_readstdi(void)
{
	t_read_stdi	var;
	
	var.pos = 0;
	var.quote = 0;
	file_name = malloc(sizeof(char)*255);
	if (file_name != NULL)
	{
		while (var.buff != '\n' && read(0, &var.buff, 1))
		{
			var = ft_handle_case(var);		
		}
		free(file_name);
	}
}
