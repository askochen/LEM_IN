/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:55:43 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_check_for_start_finish(char *str, t_farm *my_farm)
{
	if (ft_strequ(str, "##start"))
	{
		if (my_farm->find_start == 1)
			ft_error(my_farm, str);
		if (my_farm->find_finish == 1 && my_farm->finish == NULL)
			ft_error(my_farm, str);
		my_farm->find_start = 1;
		my_farm->map = add_line(my_farm->map, str);
	}
	else if (ft_strequ(str, "##end"))
	{
		if (my_farm->find_finish == 1)
			ft_error(my_farm, str);
		if (my_farm->find_start == 1 && my_farm->start == NULL)
			ft_error(my_farm, str);
		my_farm->find_finish = 1;
		my_farm->map = add_line(my_farm->map, str);
	}
	else
		my_farm->map = add_line(my_farm->map, str);
}

void		free_words(char ***words)
{
	int		i;

	i = 0;
	if (**words)
	{
		while ((*words)[i] != 0)
		{
			free((*words)[i]);
			++i;
		}
		free(*words);
	}
}

int			is_complete(t_farm *my_farm, char **ants)
{
	int		complete;
	int		i;

	i = 0;
	complete = 1;
	while (i < my_farm->ant_num)
	{
		if (ants[i] != my_farm->finish->name)
			complete = 0;
		++i;
	}
	return (complete);
}

int			get_distance(t_room *room1, t_room *room2)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = room1->x;
	x2 = room2->x;
	y1 = room1->y;
	y2 = room2->y;
	return (ft_sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

int			ft_sqrt(int val)
{
	int i;

	i = 0;
	while (i * i < val)
		++i;
	return (i);
}
