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

#define UINT unsigned int

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int			ft_read_map(void);
void		ft_solve_map(void);
void		ft_readstdi(void);
void		ft_display_map(void);
int			ft_read_map_info(void);
int			ft_read_line_len(void);
int			ft_set_array(void);

typedef struct	s_square
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
}				t_square;

typedef	struct	s_map_info
{
	unsigned int	map_lines;
	unsigned int	line_len;
	char			empty;
	char			obstacle;
	char			full;
}				t_map_info;

/*"The following global variables are accessed multiple times throughout the 
programs functions, making it an unnecessary use of cpu cycles and memory to 
repeatedly pass them back and forth between functions."*/
t_map_info	map_info;//contains info on the current map.
int			fd;
char		*file_name;
char		**map_arr;
s_square	largest_solution;

#endif
