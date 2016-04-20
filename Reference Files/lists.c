/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavnga <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:23:13 by ghavenga          #+#    #+#             */
/*   Updated: 2016/04/19 17:24:00 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map_elem	*ft_create_elem(char delimiter, UINT num_empty, UINT num_delim)
{
	t_map_elem	*list;

	list = NULL;
	list = malloc(sizeof(t_map_elem));
	if (list)
	{
		list->delimiter = delimiter;
		list->num_empty = num_empty;
		list->num_delim = num_delim;
		list->next = NULL;
	}
	return (list);
}

t_map_elem	*ft_free_elem(t_map_elem)
{
	t_map_elem	*list;
	
	list = NULL;
	
}
