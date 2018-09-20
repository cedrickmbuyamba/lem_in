/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:47:18 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/18 10:50:43 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			is_exist(char *s, t_info *lst)
{
	t_room	*tmp;

	if (lst->start == NULL)
	{
		lst = ft_addlst(lst, s);
		return (1);
	}
	tmp = lst->start;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, s) == 0)
		{
			lst->error = 1;
			return (0);
		}
		tmp = tmp->next;
	}
	lst = ft_addlst(lst, s);
	return (1);
}

int			check_details(char **tab, t_info *lst)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (is_exist(tab[i], lst) == 0)
		return (0);
	x = ft_atoi(tab[++i]);
	y = ft_atoi(tab[++i]);
	if (x < 0 || y < 0)
		lst->error = 1;
	return (1);
}

int			get_start_end(char *line, t_info *lst, int start)
{
	int		i;
	char	**t;

	i = 0;
	get_next_line(0, &line);
	ft_putstr(line);
	write(1, "\n", 1);
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	t = ft_strsplit(line, ' ');
	free(line);
	if (t && t[1] == NULL)
		return (ft_free_tab(t));
	if (start == 1)
		lst->name_start = ft_strdup(t[0]);
	else if (start == 2)
		lst->name_end = ft_strdup(t[0]);
	if (check_details(t, lst) == 0 || t[3] != NULL)
		return (ft_free_tab(t));
	ft_free_tab(t);
	return (1);
}

int			sharp(char *line, t_info *lst)
{
	if (ft_strcmp("##start", line) == 0 && ft_strlen(line) == 7)
	{
		if (lst->name_start != NULL || get_start_end(line, lst, 1) == 0)
		{
			lst->error = 1;
			return (0);
		}
		lst->begins_end++;
	}
	else if (ft_strcmp("##end", line) == 0 && ft_strlen(line) == 5)
	{
		if (lst->name_end != NULL || get_start_end(line, lst, 2) == 0)
		{
			lst->error = 1;
			return (0);
		}
		lst->begins_end++;
	}
	return (1);
}

int			get_ants(char *line, t_info *lst)
{
	int		nb;

	get_next_line(0, &line);
	ft_putstr(line);
	write(1, "\n", 1);
	nb = ft_atoi(line);
	if (nb <= 0)
	{
		lst->error = 1;
		lst->ants = nb;
		free(line);
		return (0);
	}
	lst->ants = nb;
	free(line);
	return (1);
}
