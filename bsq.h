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

typedef struct	ssquare
{
	unsigned int	start;
	unsigned int	size;
}				tsquare;

typedef	struct	svalue
{
	char			value;
	unsigned int	num_pos;
	struct svalue	*next;
}				tvalue;

typedef	struct	smap_info
{
	unsigned int	size;
	char			empty;
	char			obstacle;
	char			full;
	unsigned int	start_pos;
}				tmap_info;

/*Insert EXTRA nice comment why we need these to reduce memory usage*/
/*"The following global variables are accessed multiple times throughout the 
programs functions, making it an unnecessary use of cpu cycles and memory to 
repeatedly pass them back and forth between functions."*/
tmap_info	map_info;//contails 
tvalue		*map_list;//pointer to the start of our linked list
int			fd;

#endif
