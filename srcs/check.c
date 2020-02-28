/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:09:44 by seronen           #+#    #+#             */
/*   Updated: 2019/12/22 15:17:14 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_validate_block(char *s)
{
	int i;
	int conn;
	int hash;
	int len;

	i = 0;
	conn = 0;
	hash = 0;
	len = ft_strlen(s);
	while (s[i] && (s[i] == '.' || s[i] == '#' || s[i] == '\n'))
	{
		if (s[i] == '#')
		{
			conn = conn_value(s, i, conn);
			hash++;
		}
		++i;
	}
	if (conn < 6 || hash != 4 || len > 21 || len < 20 || i < 20)
		ft_error(0);
	return (0);
}

void			ft_check_integrity(t_list *h)
{
	char	*s;
	int		i;

	while (h)
	{
		s = h->content;
		i = 0;
		if (s[0] == '\n')
			ft_error(0);
		if (s[4] != '\n' || s[9] != '\n' || s[14] != '\n' ||
			s[19] != '\n' || (s[20] != '\n' && s[20] != '\0'))
			ft_error(0);
		if (h->next == NULL)
		{
			if (s[20] != '\0')
				ft_error(0);
		}
		h = h->next;
	}
}

int				ft_check_4block(t_coord *c)
{
	while (c)
	{
		if (c->c2 == 1 && c->c3 == 2 && c->c4 == 3)
			return (0);
		else if (c->c2 == 5 && c->c3 == 10 && c->c4 == 15)
			return (0);
		c = c->next;
	}
	return (1);
}

int				ft_check_square(t_coord *c)
{
	if (!c->next)
	{
		if (c->c1 == 0 && c->c2 == 1 && c->c3 == 5 && c->c4 == 6)
		{
			ft_putstr("AA\nAA\n");
			return (0);
		}
	}
	return (1);
}
