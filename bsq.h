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
tmap_info	map_info;//contains info on the current map.
int			fd;
char		*file_name;

#endif
