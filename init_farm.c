/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:18 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:52:43 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_get_ants(t_farm *my_farm, char *str)
{
	char		*temp;

	if (ft_strlen(str) > 10)
		ft_error(my_farm, str);
	temp = str;
	while (*temp)
	{
		if (ft_isdigit(*temp) == 0)
			ft_error(my_farm, str);
		++temp;
	}
	my_farm->ant_num = ft_atoi(str);
	my_farm->map = add_line(my_farm->map, str);
	if (my_farm->ant_num == 0 || my_farm->ant_num > 2147483647)
		ft_error(my_farm, str);
}

void		ft_get_room(t_farm *my_farm, char *str)
{
	t_room		*room;

	if (*str == 'L')
		ft_error(my_farm, str);
	if (*str == '#')
		ft_check_for_start_finish(str, my_farm);
	else
	{
		room = get_room(str);
		if (room == NULL)
			my_farm->is_links = 1;
		else if (find_room(my_farm, room->name) != NULL)
			ft_error(my_farm, str);
		else
		{
			my_farm->rooms = add_room(my_farm->rooms, room);
			my_farm->map = add_line(my_farm->map, str);
			if (my_farm->find_start == 1 && my_farm->start == NULL)
				my_farm->start = room;
			if (my_farm->find_finish == 1 && my_farm->finish == NULL)
				my_farm->finish = room;
		}
	}
}

void		ft_get_link(t_farm *my_farm, char *str)
{
	t_link		*link;
	t_room		*room_1;
	t_room		*room_2;

	if (ft_strequ(str, "##start") == 1 || ft_strequ(str, "##end") == 1)
		ft_error(my_farm, str);
	if (str[0] == '#')
	{
		my_farm->map = add_line(my_farm->map, str);
		return ;
	}
	link = get_link(my_farm, str);
	if (link == NULL)
	{
		if (my_farm->rooms == NULL)
			ft_error(my_farm, str);
		my_farm->is_links = 2;
		return ;
	}
	my_farm->map = add_line(my_farm->map, str);
	room_1 = find_room(my_farm, link->room_1);
	room_2 = find_room(my_farm, link->room_2);
	add_link_to_room(link, room_1);
	add_link_to_room(link, room_2);
	ft_del_link(link);
}

void		ft_init_farm(int fd, t_farm *my_farm)
{
	int		iter;
	char	*str;

	iter = 0;
	while (get_next_line(fd, &str) && my_farm->is_links < 2)
	{
		while (str[0] == '#' && my_farm->ant_num == 0)
		{
			if (ft_strequ(str, "##start") == 1 || ft_strequ(str, "##end") == 1)
				ft_error(my_farm, str);
			my_farm->map = add_line(my_farm->map, str);
			free(str);
			get_next_line(fd, &str);
		}
		if (iter == 0)
			ft_get_ants(my_farm, str);
		else if (my_farm->is_links == 0)
			ft_get_room(my_farm, str);
		if (my_farm->is_links == 1)
			ft_get_link(my_farm, str);
		free(str);
		++iter;
	}
	final_check(my_farm, str);
}

void		final_check(t_farm *my_farm, char *str)
{
	if (my_farm->is_links == 2 && str != NULL)
		free(str);
	if (my_farm->start == NULL || my_farm->finish == NULL)
		ft_error(my_farm, NULL);
}
