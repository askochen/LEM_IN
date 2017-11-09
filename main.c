/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:34 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:53:36 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_error(t_farm *my_farm, char *str)
{
	write(1, "\033[0;34m", 7);
	ft_putstr("ERROR\n");
	if (str != NULL)
		free(str);
	ft_del_farm(my_farm);
	exit(1);
}

t_farm		*ft_new_farm(void)
{
	t_farm		*my_farm;

	my_farm = (t_farm*)malloc(sizeof(t_farm));
	my_farm->ant_num = 0;
	my_farm->rooms = NULL;
	my_farm->start = NULL;
	my_farm->finish = NULL;
	my_farm->find_start = 0;
	my_farm->find_finish = 0;
	my_farm->is_links = 0;
	my_farm->map = (char*)malloc(sizeof(char));
	my_farm->map[0] = '\0';
	return (my_farm);
}

void		ft_del_farm(t_farm *my_farm)
{
	clear_rooms_list(my_farm->rooms);
	free(my_farm->map);
	free(my_farm);
}

int			main(void)
{
	t_farm		*my_farm;
	int			fd;

	my_farm = ft_new_farm();
	fd = 0;
	if (fd < 0)
		ft_error(my_farm, NULL);
	ft_init_farm(fd, my_farm);
	ft_find_way(my_farm);
	ft_del_farm(my_farm);
	return (0);
}
