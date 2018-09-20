/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:16:07 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/18 09:19:04 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/includes/libft.h"

# define INT_MAX 2147483647

typedef struct		s_room
{
	int				pd;
	int				ants;
	int				nbr;
	int				here;
	char			*name;
	struct s_room	*next;
	struct s_room	**link;
}					t_room;

typedef struct		s_info
{
	int				ants;
	int				error;
	int				link;
	int				begins_end;
	int				start_tube;
	char			*name_start;
	char			*name_end;
	struct s_room	*start;
	struct s_room	*end;
}					t_info;

t_info				*ft_addlst(t_info *lst, char *s);
t_info				*ft_newlst(void);
int					ft_strnlen(char *str, char c);
int					ft_free_tab(char **tab);
int					ft_free_room(t_info *lst);
int					ft_free_lst(t_info *lst);

t_room				**ft_realloc(t_room **new, t_room *rm1, t_room *rm2);
t_room				**ft_make_link(t_room *rm1, t_room *rm2);
t_room				*ft_find_elem(t_info *lst, t_room *elem, char *s);
int					ft_room_tube(char *line, t_info *lst);
int					is_exist(char *s, t_info *lst);

int					check_details(char **tab, t_info *lst);
int					get_start_end(char *line, t_info *lst, int start);
int					sharp(char *line, t_info *lst);
int					get_ants(char *line, t_info *lst);
int					ft_get_parse(char *line, t_info *lst);

int					ft_recursive(t_info *lst, t_room *elem, int deep,
	int weight);
int					put_weit(t_room *elem, int weit);
int					return_path(int ret, int u);
int					algo(t_info *lst, t_room *elem);
void				change_start_end(t_info *lst);

void				check_error(t_info *lst);
t_room				*display(t_room *new, int ants, t_info *lst);
int					ft_resolve(t_info *lst);

#endif
