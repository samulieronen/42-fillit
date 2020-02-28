/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:11:01 by samulierone       #+#    #+#             */
/*   Updated: 2019/12/19 19:03:32 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_place_block(t_coord *temp, char *old, int i)
{
	char *map;

	map = ft_strdup(old);
	if (map[i] == '.' && map[i + temp->c2] == '.' &&
	map[i + temp->c3] == '.' && map[i + temp->c4] == '.')
	{
		map[i + temp->c1] = (char)temp->let;
		map[i + temp->c2] = (char)temp->let;
		map[i + temp->c3] = (char)temp->let;
		map[i + temp->c4] = (char)temp->let;
	}
	else
	{
		ft_strdel(&map);
		return (0);
	}
	ft_memmove(old, map, ft_strlen(map));
	ft_strdel(&map);
	return (1);
}

static int		ft_solve(t_coord *coord, char *map, int index, char *prev)
{
	if (!coord)
	{
		ft_putstr(map);
		ft_strdel(&prev);
		ft_strdel(&map);
		return (1);
	}
	while (map[index + coord->c4])
	{
		if (!(ft_place_block(coord, map, index)))
			index++;
		else if (!(ft_solve(coord->next, map, 0, ft_strdup(map))))
		{
			map = ft_strdup(prev);
			index++;
		}
		else
		{
			ft_strdel(&prev);
			return (1);
		}
	}
	ft_strdel(&map);
	ft_strdel(&prev);
	return (0);
}

int				ft_manager(t_list *head, t_coord *coord, int mapsize)
{
	char *map;

	map = ft_make_map_xy(mapsize);
	while (!(ft_solve(coord, map, 0, ft_strdup(map))))
	{
		mapsize++;
		ft_delete_coord(coord);
		map = ft_make_map_xy(mapsize);
		head = ft_mod_block(head, mapsize);
		coord = ft_make_coord(head);
	}
	ft_delete_list(head);
	ft_delete_coord(coord);
	return (0);
}
