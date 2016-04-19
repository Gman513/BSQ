/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduction_linked.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavnga <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 16:23:13 by khansman          #+#    #+#             */
/*   Updated: 2016/04/17 13:24:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//this file is to implement the linked list reduction method.
unsigned int	scan_max_len(tvalue *list_pos);
{
	int	k;
	
	k = 0;
	while (list_pos.value == map_info.empty)
	{
		k++;
		if (list_pos.next == NULL)
			list pos = ft_create_elm(list_pos);
		else
			list.pos = list_pos.next;
	}
	return (k);
}

tsquare			ft_scan_map_reduction(void);
{ //if this method is to validate the file while scanning it, then the file pointer
// has to be set to the start of the map when it is called.
// the map info should be set as a global varable, so that it doesn't have to be duplicated for every function
	int						searching;
	long long unsigned int	pos;
	ssquare					largest;
	ssquare					current;
	svalue					*address;
	unsigned int			k;
	
	pos = 0;
	searching = 1;
	address.next = ft_create_elem(NULL);
	while(searching)
	{
		current.start = pos;
		k = scan_max_len(address);
		if (k > largest.size)
		{
			largest.size = k;
			largest.start = pos;
		}
		address = address.next;
		pos++;
	}
}

//Linked List Functions can go down here unless we require a new file
char *ft_create_elem(int empty, int obstacle)
{
	
}
