/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:44:57 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/18 09:28:10 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	change_start_end(t_info *lst)
{
	t_room *start;
	t_room *end;
	t_room *tmp;

	tmp = lst->start;
	if (ft_strcmp(lst->start->name, lst->name_start) != 0)
	{
		while (ft_strcmp(tmp->next->name, lst->name_start) != 0)
			tmp = tmp->next;
		start = tmp->next;
		tmp->next = start->next;
		start->next = lst->start;
		lst->start = start;
		tmp = lst->start;
	}
	if (ft_strcmp(lst->end->name, lst->name_end) != 0)
	{
		while (ft_strcmp(tmp->next->name, lst->name_end) != 0)
			tmp = tmp->next;
		end = tmp->next;
		tmp->next = end->next;
		end->next = NULL;
		lst->end->next = end;
		lst->end = end;
	}
}

int		put_weit(t_room *elem, int weit)
{
	elem->pd = weit;
	return (0);
}

int		return_path(int ret, int u)
{
	if (u == -1)
		return (-1);
	if (ret == 1)
		return (1);
	return (0);
}

int		ft_recursive(t_info *lst, t_room *elem, int deep, int weit)
{
	int		i;
	int		u;
	int		ret;

	i = 0;
	ret = 0;
	u = -1;
	if (elem->pd != INT_MAX && deep == 0)
		return (-1);
	if (elem == lst->start)
		return (1);
	if (elem->pd == INT_MAX)
		return (put_weit(elem, weit));
	while (elem->link[i] != NULL && ret != 1)
	{
		ret = ft_recursive(lst, elem->link[i], deep - 1, weit);
		if (u == -1)
			u = ret;
		i++;
	}
	return (return_path(ret, u));
}

int		algo(t_info *lst, t_room *elem)
{
	int	d;
	int	r;

	if (lst->error == 1 || elem->link == NULL)
		return (0);
	d = 1;
	r = 1;
	elem->pd = 0;
	while (!(r = ft_recursive(lst, elem, d, d)))
		d++;
	if (r == -1)
		return (0);
	return (1);
}
