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

typedef struct	s_square
{
	unsigned int	start_x;
	unsigned int	start_y;
	unsigned int	size;
}				t_square;

typedef	struct	s_map_elem
{
	char				delimiter;
	unsigned int		num_empty;
	unsigned int		num_delim;
	struct smap_elem	*next;
}				tmap_elem;


typedef	struct	s_map_info
{
	unsigned int	map_lines;
	unsigned int	line_len;
	char			empty;
	char			obstacle;
	char			full;
	unsigned int	start_pos;
}				t_map_info;

/*"The following global variables are accessed multiple times throughout the 
programs functions, making it an unnecessary use of cpu cycles and memory to 
repeatedly pass them back and forth between functions."*/
tmap_info	map_info;//contains info on the current map.
<<<<<<< HEAD
tmap_elem	*map_list;//pointer to the start of our linked list
=======
t_value		*map_list;//pointer to the start of our linked list
>>>>>>> f2889902775105ee72e2ccf1585cb71d9e674581
int			fd;

#endif
