/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_lengh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:37:48 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/13 18:37:52 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_strnlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] != '\0')
		return (i);
	return (-1);
}