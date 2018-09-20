/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:32:45 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/14 17:33:17 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_free_tab(char **tab)
{
	int	a;

	a = 0;
	while (tab[a] != NULL)
	{
		free(tab[a]);
		a++;
	}
	free(tab);
	return (0);
}

int		ft_free_room(t_info *lst)
{
	t_room	*elem;
	t_room	*tmp;

	elem = lst->start;
	while (elem)
	{
		tmp = elem->next;
		free(elem->name);
		free(elem);
		elem = tmp;
	}
	return (0);
}

int		ft_free_lst(t_info *lst)
{
	if (lst)
	{
		free(lst->name_start);
		free(lst->name_end);
		free(lst);
	}
	return (0);
}
