/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavenga                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:05:22 by khansman          #+#    #+#             */
/*   Updated: 2016/04/13 13:42:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}				tmap_info;
