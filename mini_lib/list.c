/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:34:24 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/14 17:32:47 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/includes/libft.h"

static void	add(t_room *new, char *str)
{
	new->next = NULL;
	new->link = NULL;
	new->ants = 0;
	new->nbr = 0;
	new->here = 0;
	new->pd = INT_MAX;
	new->name = ft_strdup(str);
}

t_info		*ft_addlst(t_info *lst, char *s)
{
	t_room	*new;

	if (lst != NULL)
	{
		if ((new = (t_room*)malloc(sizeof(t_room))) != NULL)
		{
			add(new, s);
			if (lst->end == NULL)
			{
				lst->start = new;
				lst->end = new;
			}
			else
			{
				lst->end->next = new;
				lst->end = new;
			}
		}
	}
	return (lst);
}
