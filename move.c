/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:53:54 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	move_ants(t_farm *my_farm)
{
	char	**ants;

	ants = (char**)malloc(sizeof(char*) * my_farm->ant_num);
	set_ants_at_start(my_farm, ants);
	while (is_complete(my_farm, ants) == 0)
	{
		try_move_ants(my_farm, ants);
	}
	free(ants);
}

void	set_ants_at_start(t_farm *my_farm, char **ants)
{
	int		i;

	i = 0;
	while (i < my_farm->ant_num)
	{
		ants[i] = my_farm->start->name;
		++i;
	}
}

void	try_move_ants(t_farm *my_farm, char **ants)
{
	int			i;
	t_room		*room;
	t_l_list	*temp;

	i = 0;
	while (i < my_farm->ant_num)
	{
		room = find_room(my_farm, ants[i]);
		temp = room->links;
		while (temp != NULL)
		{
			if (is_good_room(my_farm, room, temp->link, ants) == 1)
			{
				room = find_room(my_farm, get_neighbor(room, temp->link));
				move_ant_to_room(room, ants, i);
				temp = NULL;
			}
			else
				temp = temp->next;
		}
		++i;
	}
	ft_putchar('\n');
}

int		is_good_room(t_farm *my_farm, t_room *room, t_link *link, char **ants)
{
	t_room		*neightbor;
	int			i;

	i = 0;
	neightbor = find_room(my_farm, get_neighbor(room, link));
	if (my_farm->finish == neightbor)
		return (1);
	while (i < my_farm->ant_num)
	{
		if (ants[i] == neightbor->name)
			return (0);
		++i;
	}
	if ((neightbor->mass + 1) == room->mass)
		return (1);
	else
		return (0);
}

void	move_ant_to_room(t_room *room, char **ants, int i)
{
	char	*index;

	index = ft_itoa(i + 1);
	ants[i] = room->name;
	write(1, "\033[0;31m", 7);
	ft_putchar('L');
	ft_putstr(index);
	ft_putchar('-');
	ft_putstr(ants[i]);
	ft_putchar(' ');
	free(index);
}
