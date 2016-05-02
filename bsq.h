/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavenga                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:05:22 by khansman          #+#    #+#             */
/*   Updated: 2016/04/13 13:42:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BSQ_H__
#define __BSQ_H__

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int					ft_read_map(void);
void				ft_solve_map(void);
void				ft_readstdi(void);
void				ft_display_map(void);
int					ft_read_map_info(void);
int					ft_read_line_len(void);
int					ft_set_array(void);
int					ft_array_solution(void);
int					ft_manage_array (int procedure);
int					ft_add_solution(void);
int					ft_set_var(void);

typedef struct		s_square
{
	int				x;
	int				y;
	int				size;
}					t_square;

typedef	struct		s_map_info
{
	int				map_lines;
	int				line_len;
	char			empty;
	char			obstacle;
	char			full;
}					t_map_info;

typedef struct		s_arr_sol
{
	int				k;
	int				l;
	t_square		curr;
	t_square		larg;
}					t_arr_sol;

typedef struct		s_std_var
{
	char			buff;
	int				k;
	int				l;
}					t_std_var;

typedef struct		s_read_stdi
{
	int		pos;
	int		quote;
	char	buff;
}					t_read_stdi;

/*"The following global variables are accessed multiple times throughout the 
programs functions, making it an unnecessary use of cpu cycles and memory to ss
repeatedly pass them back and forth between functions."*/
t_map_info			map_info;
int					fd;
char				*file_name;
char				**map_arr;
t_square			largest_solution;

#endif
