/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:55:24 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_r_list	*add_room(t_r_list *list, t_room *room)
{
	t_r_list	*temp;

	temp = (t_r_list*)malloc(sizeof(t_r_list));
	temp->room = room;
	temp->next = list;
	return (temp);
}

void		clear_rooms_list(t_r_list *list)
{
	t_r_list	*temp;

	while (list != NULL)
	{
		temp = list->next;
		del_room(list->room);
		free(list);
		list = temp;
	}
}

void		del_room(t_room *room)
{
	free(room->name);
	clear_links_list(room->links);
	free(room);
}
