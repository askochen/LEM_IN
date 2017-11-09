/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:54:50 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_room(t_farm *my_farm, char *name)
{
	t_r_list		*temp;

	temp = my_farm->rooms;
	while (temp)
	{
		if (ft_strequ(name, temp->room->name))
			return (temp->room);
		temp = temp->next;
	}
	return (NULL);
}

void		add_link_to_room(t_link *link, t_room *room)
{
	t_l_list		*temp;

	temp = room->links;
	while (temp)
	{
		if (is_links_equal(temp->link, link))
			return ;
		temp = temp->next;
	}
	room->links = add_link_copy(room->links, link);
}

int			is_links_equal(t_link *link1, t_link *link2)
{
	int		eq1;
	int		eq2;
	int		eq3;
	int		eq4;

	eq1 = ft_strequ(link1->room_1, link2->room_1);
	eq2 = ft_strequ(link1->room_2, link2->room_2);
	eq3 = ft_strequ(link1->room_1, link2->room_2);
	eq4 = ft_strequ(link1->room_2, link2->room_1);
	if (eq1 == 1 && eq2 == 1)
		return (1);
	if (eq3 == 1 && eq4 == 1)
		return (1);
	return (0);
}

t_link		*get_link(t_farm *my_farm, char *str)
{
	t_link		*link;

	link = is_link(my_farm, str);
	if (link == NULL)
		my_farm->is_links = 2;
	return (link);
}

t_link		*is_link(t_farm *my_farm, char *str)
{
	int			len;
	t_r_list	*i;
	t_r_list	*j;
	char		*find;

	i = my_farm->rooms;
	while (i != NULL)
	{
		find = ft_strstr(str, i->room->name);
		len = ft_strlen(i->room->name);
		if (find == str && str[len] == '-')
		{
			j = my_farm->rooms;
			while (j != NULL)
			{
				find = ft_strstr(str + len + 1, j->room->name);
				if (i != j && find != NULL &&
					(ft_strlen(j->room->name) + len + 1) == ft_strlen(str))
					return (new_link(my_farm, i->room->name, j->room->name));
				j = j->next;
			}
		}
		i = i->next;
	}
	return (NULL);
}
