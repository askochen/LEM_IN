/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:14:38 by askochen          #+#    #+#             */
/*   Updated: 2017/07/23 16:53:04 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define MAX_MASS 1000000
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct				s_link
{
	char					*room_1;
	char					*room_2;
	int						dist;
}							t_link;

typedef struct				s_links_list
{
	t_link					*link;
	struct s_links_list		*next;
}							t_l_list;

typedef struct				s_room
{
	char					*name;
	int						x;
	int						y;
	int						mass;
	t_l_list				*links;
}							t_room;

typedef struct				s_rooms_list
{
	t_room					*room;
	struct s_rooms_list		*next;
}							t_r_list;

typedef struct				s_farm
{
	int						ant_num;
	t_r_list				*rooms;
	int						find_start;
	int						find_finish;
	t_room					*start;
	t_room					*finish;
	int						is_links;
	char					*map;
}							t_farm;

void						ft_error(t_farm *my_farm, char *str);
t_farm						*ft_new_farm();
void						ft_init_farm(int fd, t_farm *my_farm);
void						ft_get_ants(t_farm *my_farm, char *str);
void						ft_get_room(t_farm *my_farm, char *str);
void						ft_get_link(t_farm *my_farm, char *str);
void						wrong_room(t_farm *my_farm, char *str, t_room *r);
void						final_check(t_farm *my_farm, char *str);
void						ft_check_for_start_finish(char *str,
								t_farm *my_farm);
void						free_words(char ***words);
void						ft_del_farm(t_farm *my_farm);
t_room						*get_room(char *str);
int							number_of_spaces(char *str);
int							number_of_words(char **words);
int							is_coord_wrong(char **words);
t_room						*words_to_room(char **words);
t_r_list					*add_room(t_r_list *list, t_room *room);
void						clear_rooms_list(t_r_list *list);
void						del_room(t_room *room);
t_l_list					*add_link(t_l_list *list, t_room *r1, t_room *r2);
void						clear_links_list(t_l_list *list);
void						ft_del_link(t_link *link);
t_l_list					*add_link_copy(t_l_list *list, t_link *c_link);
t_room						*find_room(t_farm *my_farm, char *name);
void						add_link_to_room(t_link *link, t_room *room);
int							is_links_equal(t_link *link1, t_link *link2);
t_link						*get_link(t_farm *my_farm, char *str);
t_link						*is_link(t_farm *my_farm, char *str);
t_link						*new_link(t_farm *my_farm, char *room1,
								char *room2);
int							get_distance(t_room *room1, t_room *room2);
int							ft_sqrt(int val);
void						ft_print_farm(t_farm *my_farm);
char						*add_line(char *str1, char *str2);
void						ft_find_way(t_farm *my_farm);
void						calculate_room_mass(t_farm *my_farm);
void						recursive_calculation(t_room *room,
							t_farm *my_farm);
char						*get_neighbor(t_room *room, t_link *link);
void						move_ants(t_farm *my_farm);
void						set_ants_at_start(t_farm *my_farm, char **ants);
int							is_complete(t_farm *my_farm, char **ants);
void						try_move_ants(t_farm *my_farm, char **ants);
int							is_good_room(t_farm *my_farm, t_room *room,
							t_link *link, char **ants);
void						move_ant_to_room(t_room *room, char **ants, int i);
#endif
