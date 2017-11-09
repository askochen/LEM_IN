/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:54:18 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*get_room(char *str)
{
	int			i;
	char		**parts;
	t_room		*room;

	i = number_of_spaces(str);
	if (i != 2)
		return (NULL);
	parts = ft_strsplit(str, ' ');
	i = number_of_words(parts);
	if (i != 3)
	{
		free_words(&parts);
		return (NULL);
	}
	if (is_coord_wrong(parts) == 1)
	{
		free_words(&parts);
		return (NULL);
	}
	room = words_to_room(parts);
	free_words(&parts);
	return (room);
}

int			number_of_spaces(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
			++i;
		++str;
	}
	return (i);
}

int			number_of_words(char **words)
{
	int		i;

	i = 0;
	while (words[i] != NULL && ft_strlen(words[i]) > 0)
		++i;
	return (i);
}

int			is_coord_wrong(char **words)
{
	int		i;
	int		j;

	i = 1;
	while (i < 3)
	{
		j = 0;
		while (words[i][j])
		{
			if (j == 0 && words[i][j] == '-')
				++j;
			else
			{
				if (ft_isdigit(words[i][j]) == 0)
					return (1);
				++j;
			}
		}
		++i;
	}
	return (0);
}

t_room		*words_to_room(char **words)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(words[0]);
	room->x = ft_atoi(words[1]);
	room->y = ft_atoi(words[2]);
	room->mass = MAX_MASS;
	room->links = NULL;
	return (room);
}
