/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:38:47 by jduong            #+#    #+#             */
/*   Updated: 2019/12/22 15:11:33 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_under_4_helper(char *str, char *map, int start)
{
	int i;
	int k;

	k = 0;
	i = start;
	while (map[i])
	{
		while (str[k])
		{
			while (str[k] != '\n')
			{
				str[k] = map[i];
				++k;
				++i;
			}
			k++;
			break ;
		}
		while (map[i] != '\n')
			++i;
		if (start == 6 || start == 1)
			i++;
		++i;
	}
}

void	coord_helper(char *str, t_coord *temp)
{
	int i;
	int ibase;
	int counter;

	i = 0;
	ibase = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (counter == 0)
			{
				ibase = i;
				ft_place_coord(temp, counter, 0);
			}
			else
				ft_place_coord(temp, counter, i - ibase);
			++counter;
		}
		++i;
	}
}

int		conn_value(char *s, int i, int conn)
{
	if (s[i + 1] == '#')
		conn++;
	if (s[i - 1] == '#')
		conn++;
	if (s[i + 5] == '#')
		conn++;
	if (s[i - 5] == '#')
		conn++;
	return (conn);
}
