/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:55:57 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_find_way(t_farm *my_farm)
{
	calculate_room_mass(my_farm);
	ft_print_farm(my_farm);
	move_ants(my_farm);
}

void	calculate_room_mass(t_farm *my_farm)
{
	my_farm->finish->mass = 0;
	recursive_calculation(my_farm->finish, my_farm);
	if (my_farm->start->mass == MAX_MASS)
		ft_error(my_farm, NULL);
}

void	recursive_calculation(t_room *room, t_farm *my_farm)
{
	t_room		*temp_room;
	t_l_list	*temp;

	temp = room->links;
	while (temp != NULL)
	{
		temp_room = find_room(my_farm, get_neighbor(room, temp->link));
		if (temp_room->mass > (room->mass + 1))
		{
			temp_room->mass = room->mass + 1;
			recursive_calculation(temp_room, my_farm);
		}
		temp = temp->next;
	}
}

char	*get_neighbor(t_room *room, t_link *link)
{
	if (ft_strequ(room->name, link->room_1))
		return (link->room_2);
	else
		return (link->room_1);
}
