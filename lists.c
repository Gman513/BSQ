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

//Linked List Functions can go down here unless we require a new file
t_map_elem	*ft_create_elem(int empty, int obstacle)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}
