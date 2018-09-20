/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:48:08 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/17 12:39:25 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		check_error(t_info *lst)
{
	if (lst->begins_end != 2)
		lst->error = 1;
	if (lst->error == 0 && (ft_strcmp(lst->end->name, lst->name_end) != 0 ||
	ft_strcmp(lst->start->name, lst->name_start) != 0))
		change_start_end(lst);
}

t_room		*get_room(t_room *elem)
{
	int		i;
	t_room	*new;

	i = 1;
	if (elem->link == NULL)
		return (NULL);
	new = elem->link[0];
	while (elem->link[i] != NULL)
	{
		if (new->pd > elem->link[i]->pd)
			new = elem->link[i];
		i++;
	}
	return (new);
}

t_room		*display(t_room *new, int ants, t_info *lst)
{
	new = get_room(new);
	new->nbr++;
	if (new->nbr <= ants)
	{
		write(1, "L", 1);
		ft_putnbr(new->nbr);
		write(1, "-", 1);
		ft_putstr(new->name);
		write(1, " ", 1);
	}
	if (new == lst->end)
		lst->end->ants++;
	return (new);
}

int			ft_resolve(t_info *lst)
{
	int		i;
	int		ants;
	t_room	*new;

	i = 1;
	new = lst->start;
	lst->start->here = 1;
	ants = lst->ants;
	lst->start->ants = ants;
	while (lst->end->ants != ants || lst->start->here != 0)
	{
		while (new != lst->end && new->next->here != 0)
			new = display(new, ants, lst);
		if (new != lst->end)
			new->next->here = 1;
		if (lst->ants > 0)
			lst->ants--;
		else
			lst->start->here = 0;
		new = lst->start;
		write(1, "\n", 1);
	}
	return (1);
}
