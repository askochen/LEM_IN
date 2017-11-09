/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:53:21 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_l_list	*add_link_copy(t_l_list *list, t_link *c_link)
{
	t_l_list	*temp;
	t_link		*temp_link;

	temp_link = (t_link*)malloc(sizeof(t_link));
	temp_link->room_1 = ft_strdup(c_link->room_1);
	temp_link->room_2 = ft_strdup(c_link->room_2);
	temp_link->dist = c_link->dist;
	temp = (t_l_list*)malloc(sizeof(t_l_list));
	temp->link = temp_link;
	temp->next = list;
	return (temp);
}

void		clear_links_list(t_l_list *list)
{
	t_l_list	*temp;

	while (list != NULL)
	{
		temp = list->next;
		ft_del_link(list->link);
		free(list);
		list = temp;
	}
}

void		ft_del_link(t_link *link)
{
	free(link->room_1);
	free(link->room_2);
	free(link);
}

t_link		*new_link(t_farm *my_farm, char *room1, char *room2)
{
	t_link		*link;
	t_room		*list_room_1;
	t_room		*list_room_2;

	link = (t_link*)malloc(sizeof(t_link));
	link->room_1 = ft_strdup(room1);
	link->room_2 = ft_strdup(room2);
	list_room_1 = find_room(my_farm, room1);
	list_room_2 = find_room(my_farm, room2);
	link->dist = get_distance(list_room_1, list_room_2);
	return (link);
}
