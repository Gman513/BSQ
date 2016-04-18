/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                          :+:      :+:    :+:   */
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
	struct	svalue	*next;
}				tvalue;

typedef	struct	smap_info
{
	unsigned int	size;
	char			empty;
	char			obstacle;
	char			full;
	int				start_pos;
}				tmap_info;

/*Insert EXTRA nice comment why we need these to reduce memory usage*/
tmap_info	map_info;
tvalue		*map_list;
int			fd;

#endif
