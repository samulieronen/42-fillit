/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:09:57 by seronen           #+#    #+#             */
/*   Updated: 2019/12/19 19:03:37 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_place_coord(t_coord *node, int counter, int i)
{
	if (counter == 0)
		node->c1 = i;
	if (counter == 1)
		node->c2 = i;
	if (counter == 2)
		node->c3 = i;
	if (counter == 3)
		node->c4 = i;
}

static char		*ft_place_over_4(char *map, char *str)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (map[k])
	{
		while (str[i])
		{
			while (str[i] != '\n')
			{
				map[k] = str[i];
				++k;
				++i;
			}
			i++;
			break ;
		}
		while (map[k] != '\n')
			++k;
		++k;
	}
	return (map);
}

static char		*ft_place_under_4(char *str, char *map, int start)
{
	int i;
	int k;
	int hash;

	k = 0;
	i = start;
	ft_place_under_4_helper(str, map, start);
	i = 0;
	hash = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		i++;
	}
	if (hash == 4)
		return (str);
	return (NULL);
}

static char		*ft_downsize(char *map, char *str)
{
	char *new;

	if (!(new = ft_place_under_4(map, str, 0)))
	{
		if (!(new = ft_place_under_4(map, str, 1)))
		{
			if (!(new = ft_place_under_4(map, str, 5)))
			{
				if (!(new = ft_place_under_4(map, str, 6)))
				{
					return (0);
				}
			}
		}
	}
	return (new);
}

t_list			*ft_mod_block(t_list *head, int mapsize)
{
	char	*map;
	char	*new;
	char	*str;
	t_list	*temp;

	temp = head;
	while (head)
	{
		map = ft_make_map_xy(mapsize);
		str = head->content;
		if (mapsize == 3)
		{
			if (!(new = ft_downsize(map, str)))
				return (0);
		}
		else
			new = ft_place_over_4(map, str);
		free(head->content);
		free(map);
		head->content = (char*)malloc(sizeof(char) * ft_strlen(new) + 1);
		head->content = new;
		head = head->next;
	}
	return (temp);
}
