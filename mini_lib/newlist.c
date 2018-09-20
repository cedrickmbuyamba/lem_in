/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:35:33 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/14 17:40:44 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_info	*ft_newlst(void)
{
	t_info	*new;

	if (!(new = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	if (new != NULL)
	{
		new->ants = 0;
		new->error = 0;
		new->link = 0;
		new->start_tube = 0;
		new->begins_end = 0;
		new->name_start = NULL;
		new->name_end = NULL;
		new->start = NULL;
		new->end = NULL;
	}
	return (new);
}
