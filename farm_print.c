/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:12:58 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:52:17 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_farm(t_farm *my_farm)
{
	write(1, "\033[0;32m", 7);
	ft_putstr(my_farm->map);
	ft_putstr("\n");
}

char	*add_line(char *str1, char *str2)
{
	char *temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	str1 = temp;
	temp = ft_strjoin(str1, "\n");
	free(str1);
	return (temp);
}
