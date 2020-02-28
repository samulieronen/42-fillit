/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:44:04 by seronen           #+#    #+#             */
/*   Updated: 2019/12/20 17:23:13 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				*ft_make_map_xy(int size)
{
	int		i;
	char	*map;
	int		len;
	int		linelen;

	i = 0;
	len = (size * size) + size;
	map = (char*)malloc(sizeof(char) * (len + 1));
	linelen = 0;
	while (i < len)
	{
		map[i] = '.';
		if (linelen == size)
		{
			map[i] = '\n';
			linelen = 0;
		}
		else
			++linelen;
		++i;
	}
	map[i] = '\0';
	return (map);
}

t_coord				*ft_make_coord(t_list *node)
{
	t_coord *head;
	t_coord *temp;
	char	*str;
	int		let;

	head = NULL;
	temp = NULL;
	temp = ft_lstnew_coord();
	let = 'A';
	while (node)
	{
		if (head == NULL)
			head = temp;
		str = node->content;
		coord_helper(str, temp);
		temp->let = let;
		let++;
		if (node->next != NULL)
			temp->next = ft_lstnew_coord();
		temp = temp->next;
		node = node->next;
	}
	return (head);
}

static int			get_mapsize(t_list *head)
{
	int bc;
	int size;

	bc = 0;
	while (head)
	{
		head = head->next;
		bc++;
	}
	size = 2;
	bc = bc * 4;
	while (size * size < bc)
		size++;
	if (size > 3)
		return (size);
	else
		return (3);
}

int					ft_prepare(t_list *head, int x)
{
	t_coord		*coord;
	t_coord		*startc;

	startc = ft_make_coord(head);
	if (!(ft_check_square(startc)))
	{
		ft_delete_coord(startc);
		ft_delete_list(head);
		return (0);
	}
	if (!(ft_check_4block(startc)))
		x = 4;
	else
		x = get_mapsize(head);
	if (x != 4)
	{
		if (!(head = ft_mod_block(head, x)))
			ft_error(0);
	}
	coord = ft_make_coord(head);
	ft_delete_coord(startc);
	ft_manager(head, coord, x);
	return (0);
}
