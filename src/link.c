/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:45:56 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/14 13:38:42 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_room		**ft_realloc(t_room **new, t_room *rm1, t_room *rm2)
{
	int		i;

	i = 0;
	while (rm1->link[i])
	{
		new[i] = rm1->link[i];
		i++;
	}
	new[i] = rm2;
	new[++i] = NULL;
	return (new);
}

t_room		**ft_make_link(t_room *rm1, t_room *rm2)
{
	int		i;
	t_room	**nvo;

	i = 0;
	if (!rm1->link)
	{
		rm1->link = malloc(sizeof(t_room*) * 2);
		rm1->link[0] = rm2;
		rm1->link[1] = NULL;
	}
	else
	{
		while (rm1->link[i] != NULL)
			i++;
		nvo = malloc(sizeof(t_room*) * (i + 2));
		nvo = ft_realloc(nvo, rm1, rm2);
		free(rm1->link);
		return (nvo);
	}
	return (rm1->link);
}

t_room		*ft_find_elem(t_info *lst, t_room *elem, char *s)
{
	elem = lst->start;
	while (elem)
	{
		if (ft_strcmp(elem->name, s) == 0)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

int			get_link(t_info *lst, t_room *aroom, t_room *broom, char **t)
{
	int		i;
	t_room	*end;

	i = 0;
	end = lst->end;
	if (t[2] != NULL)
		return (ft_free_tab(t));
	aroom = ft_find_elem(lst, aroom, t[0]);
	broom = ft_find_elem(lst, broom, t[1]);
	ft_free_tab(t);
	if (!aroom || !broom)
		return (0);
	lst->start_tube = 1;
	aroom->link = ft_make_link(aroom, broom);
	broom->link = ft_make_link(broom, aroom);
	return (1);
}

int			ft_room_tube(char *line, t_info *lst)
{
	char	**t;
	t_room	*a;
	t_room	*b;

	a = NULL;
	b = NULL;
	if (lst->error == 1)
		return (0);
	if (ft_strnlen(line, '-') > 0)
	{
		lst->link = 1;
		check_error(lst);
		t = ft_strsplit(line, '-');
		return (get_link(lst, a, b, t));
	}
	else if (ft_strnlen(line, ' ') + 1 > 0 && lst->start_tube == 0)
	{
		t = ft_strsplit(line, ' ');
		if (t[3] != NULL)
			return (ft_free_tab(t));
		check_details(t, lst);
		ft_free_tab(t);
		return (1);
	}
	return (0);
}
