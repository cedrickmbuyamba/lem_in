/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:49:28 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/18 15:30:53 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			ft_get_parse(char *line, t_info *lst)
{
	get_ants(line, lst);
	while (get_next_line(0, &line) > 0 && lst->error == 0)
	{
		ft_putendl(line);
		if (line[0] == '#')
			sharp(line, lst);
		else if (ft_room_tube(line, lst) == 0)
			lst->error = 1;
		if (lst->error == 0)
			free(line);
	}
	if (lst->error == 1)
	{
		ft_putendl(line);
		free(line);
	}
	while (lst->error == 1 && get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	if (lst->link == 0)
		lst->error = 1;
	return (1);
}

int			main(void)
{
	char	*line;
	t_info	*lst;

	line = NULL;
	lst = ft_newlst();
	if (ft_get_parse(line, lst) == 0 || lst->begins_end != 2)
	{
		ft_free_room(lst);
		free(lst);
		write(1, "ERROR\n", 6);
		return (0);
	}
	if (lst->error == 0 && algo(lst, lst->end) == 1)
		ft_resolve(lst);
	else if (lst->error == 1 && lst->ants <= 0)
		write(1, "\nERROR\n", 7);
	else
		write(1, "\nERROR\n", 7);
	ft_free_room(lst);
	ft_free_lst(lst);
	return (0);
}
